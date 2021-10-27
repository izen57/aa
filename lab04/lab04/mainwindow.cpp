#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    drawColor = QColor(0, 0, 0);
    bgColor = QColor(255, 255, 255);

    mainImg = QImage(WIDTH, HEIGHT, QImage::Format_RGB32);
    mainImg.fill(bgColor);

    mainImgPixmap = scene->addPixmap(QPixmap::fromImage(mainImg));

    ui->graphicsView->setScene(scene);
    mainImgPixmap->setPixmap(QPixmap::fromImage(mainImg));

    if (DO_PLOT1)
        addPlot();
    if (DO_PLOT2)
        addPlot2();
}

MainWindow::~MainWindow()
{
    delete ui;
}

InputError MainWindow::readInput()
{
    InputError error = INPUT_ERROR;
    int offset, angle;
    if (!user.readInputInt(xCenter, ui->inpXCenter, 0, WIDTH))
    {
        showMsgIncorrectInput("X центра");
        return error;
    }
    if (!user.readInputInt(yCenter, ui->inpYCenter, 0, HEIGHT))
    {
        showMsgIncorrectInput("Y центра");
        return error;
    }
    if (!user.readInputInt(nParts, ui->inpNParts, 0, 360))
    {
        showMsgIncorrectInput("Колчиество частей");
        return error;
    }
    if (!user.readInputInt(lineLength, ui->inpLength, 0, WIDTH))
    {
        showMsgIncorrectInput("Длина отрезков");
        return error;
    }
    if (!user.readInputInt(offset, ui->inpDegOffset, 0, 360))
    {
        showMsgIncorrectInput("Начальное смещение");
        return error;
    }
    if (!user.readInputInt(angle, ui->inpDegSector, 0, 360))
    {
        showMsgIncorrectInput("Угол сектора");
        return error;
    }
    if (!user.readInputInt(nThreads, ui->inpNThreads, 0, 32))
    {
        showMsgIncorrectInput("Количество потоков");
        return error;
    }
    angleOffset = offset;
    angleSector = angle;

    error = OK;
    return error;
}

void MainWindow::showMsgIncorrectInput(QString details)
{
    QMessageBox msgBox(QMessageBox::Warning, tr("Предупреждение"), "Некорректный ввод", {}, this);
    msgBox.setDetailedText(details);
    msgBox.addButton(tr("Ок"), QMessageBox::AcceptRole);
    msgBox.exec();
}

void MainWindow::on_btnDrawSector_clicked()
{
    if (readInput() != OK)
        return;

    QPainter painter(&mainImg);
    painter.setPen(drawColor);

    QElapsedTimer timer;
    timer.start();
    drawSectorMultiThread(xCenter, yCenter, lineLength, nParts, angleOffset, angleSector, painter, nThreads);
    auto t_elapsed = timer.elapsed();
    qDebug() << nThreads << " потоков: " << t_elapsed;

    painter.end();
    mainImgPixmap->setPixmap(QPixmap::fromImage(mainImg));
}

void MainWindow::on_btnCls_clicked()
{
    mainImg.fill(bgColor);
    mainImgPixmap->setPixmap(QPixmap::fromImage(mainImg));
    update();
}

void MainWindow::initChart()
{
    chart = new QChart();
    chart->legend()->setVisible(false);
    chart->legend()->setAlignment(Qt::AlignBottom);

    xAxis = new QLogValueAxis;
    yAxis = new QValueAxis;
    xValueAxis = new QValueAxis;
    chartMaxX = 0, chartMaxY = 0;

    chartView = new QChartView();
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setChart(chart);
}

void MainWindow::addPlot()
{
    if (!chart)
        initChart();
    chart->setTitle("Анализ общего времени выполнения");

    QLineSeries* series = new QLineSeries;
    chart->addSeries(series);

    QPainter painter(&mainImg);
    painter.setPen(drawColor);

    QElapsedTimer timer;
    timer.start();
    double t_elapsed = timer.elapsed();
    srand(time(nullptr));

    int curThreads = 1;
    for (int i = 0; i < N_POINTS; ++i)
    {
        t_elapsed = 0;
        for (int i = 0; i < N_REPEATS; ++i)
        {
            timer.restart();
            drawSectorMultiThread(0, 0, LENGTH, N_PARTS, OFFSET, ANGLE, painter, curThreads);
            t_elapsed += timer.elapsed();
        }
        t_elapsed /= N_REPEATS;
        *series << QPointF(curThreads, t_elapsed);
        curThreads *= 2;
    }

    yAxis->setMin(0);
    yAxis->setMax(30);
    xAxis->setMin(1);
    xAxis->setMax(32);
    xAxis->setBase(2);
    chart->addAxis(xAxis, Qt::AlignBottom);
    chart->addAxis(yAxis, Qt::AlignLeft);
    series->attachAxis(xAxis);
    series->attachAxis(yAxis);

    chart->setAnimationOptions(QChart::SeriesAnimations);
    chartView->setChart(chart);
}

void MainWindow::addPlot2()
{
    if (!chart)
        initChart();

    chart->setTitle("Анализ распределения времени выполнения");

    QLineSeries* series = new QLineSeries;
    chart->addSeries(series);

    QPainter painter(&mainImg);
    painter.setPen(drawColor);

    QElapsedTimer timer;
    timer.start();
    double t_elapsed = timer.elapsed();
    srand(time(nullptr));

    int len = 15;
    std::vector<int> times(len);
    int threads = 8;
    if (/*DISTRIBUTION_G*/N_DISTRIBUTION)
        threads = 16;

    for (int i = 0; i < N_DISTRIBUTION; ++i)
    {
        timer.restart();
        drawSectorMultiThread(0, 0, LENGTH, N_PARTS, OFFSET, ANGLE, painter, threads);
        t_elapsed = timer.elapsed();
        times[t_elapsed]++;
    }
    for (int i = 0; i < len; ++i)
        *series << QPointF(i, times[i]);

    yAxis->setMin(0);
    yAxis->setMax(N_DISTRIBUTION);
    xValueAxis->setMin(0);
    xValueAxis->setMax(len);
    xValueAxis->setTickCount(len - 1);
    chart->addAxis(xValueAxis, Qt::AlignBottom);
    chart->addAxis(yAxis, Qt::AlignLeft);
    series->attachAxis(xValueAxis);
    series->attachAxis(yAxis);

    chart->setAnimationOptions(QChart::SeriesAnimations);
    chartView->setChart(chart);
}

void MainWindow::on_btnSavePlot_clicked()
{
    QString path = ui->inpPathPlot->text();
    chartView->grab().save(path);
}
