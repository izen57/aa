#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "algorithm.h"
#include "interface.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QMessageBox>
#include <QChartView>
#include <QtCharts>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QLogValueAxis>
#include <QLineSeries>
#include <QSplineSeries>
#include <QElapsedTimer>

#include <QDebug>

#define WIDTH 1200
#define HEIGHT 840
#define N_DISTRIBUTION 10000
#define DO_PLOT1 0
#define DO_PLOT2 0
#define DO_PLOT3 0

#define N_POINTS 7
#define N_REPEATS 10000
#define N_PARTS 15
#define OFFSET 180
#define ANGLE 15
#define LENGTH 10000

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_btnDrawSector_clicked();

    void on_btnCls_clicked();

    void on_btnSavePlot_clicked();

private:
    Ui::MainWindow *ui;

    InputError readInput();

    void showMsgIncorrectInput(QString details);

    void initChart();

    void clearChart();

    void addPlot();

    void addPlot2();

    int xCenter = 0, yCenter = 0;

    int nParts = 1;

    int lineLength = 1;

    double angleOffset = 0;

    double angleSector = 0;

    int nThreads = 1;

    QImage mainImg;

    QImage drawImg;

    QImage bgImg;

    Interface user;

    QColor drawColor, bgColor;

    QGraphicsScene *scene = nullptr;

    QGraphicsPixmapItem *mainImgPixmap = nullptr;

    QChartView *chartView = nullptr;

    QChart *chart = nullptr;

    QChart *defaultChart = nullptr;

    QChart *firstChart = nullptr;

    QLogValueAxis *xAxis = nullptr;

    QValueAxis *xValueAxis = nullptr;

    QValueAxis *yAxis = nullptr;

    int chartMaxX = 0, chartMaxY = 0;
};
#endif // MAINWINDOW_H
