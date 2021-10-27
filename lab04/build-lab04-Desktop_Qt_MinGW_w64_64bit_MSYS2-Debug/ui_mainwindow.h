/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *btnDrawSector;
    QPushButton *btnCls;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *inpXCenter;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *inpYCenter;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *inpNThreads;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *inpNParts;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *inpLength;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *inpDegOffset;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *inpDegSector;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *inpPathPlot;
    QPushButton *btnSavePlot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 900);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1200, 840));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        btnDrawSector = new QPushButton(centralwidget);
        btnDrawSector->setObjectName(QString::fromUtf8("btnDrawSector"));
        btnDrawSector->setGeometry(QRect(1210, 360, 211, 71));
        QFont font;
        font.setPointSize(12);
        btnDrawSector->setFont(font);
        btnCls = new QPushButton(centralwidget);
        btnCls->setObjectName(QString::fromUtf8("btnCls"));
        btnCls->setGeometry(QRect(1210, 430, 211, 71));
        btnCls->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1260, 30, 231, 106));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        inpXCenter = new QLineEdit(layoutWidget);
        inpXCenter->setObjectName(QString::fromUtf8("inpXCenter"));
        inpXCenter->setFont(font);
        inpXCenter->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(inpXCenter);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        inpYCenter = new QLineEdit(layoutWidget);
        inpYCenter->setObjectName(QString::fromUtf8("inpYCenter"));
        inpYCenter->setFont(font);
        inpYCenter->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(inpYCenter);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1210, 160, 380, 190));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font2;
        font2.setPointSize(10);
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_8);

        inpNThreads = new QLineEdit(layoutWidget1);
        inpNThreads->setObjectName(QString::fromUtf8("inpNThreads"));
        sizePolicy.setHeightForWidth(inpNThreads->sizePolicy().hasHeightForWidth());
        inpNThreads->setSizePolicy(sizePolicy);
        inpNThreads->setFont(font);
        inpNThreads->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(inpNThreads);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_7);

        inpNParts = new QLineEdit(layoutWidget1);
        inpNParts->setObjectName(QString::fromUtf8("inpNParts"));
        sizePolicy.setHeightForWidth(inpNParts->sizePolicy().hasHeightForWidth());
        inpNParts->setSizePolicy(sizePolicy);
        inpNParts->setFont(font);
        inpNParts->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(inpNParts);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_6);

        inpLength = new QLineEdit(layoutWidget1);
        inpLength->setObjectName(QString::fromUtf8("inpLength"));
        sizePolicy.setHeightForWidth(inpLength->sizePolicy().hasHeightForWidth());
        inpLength->setSizePolicy(sizePolicy);
        inpLength->setMinimumSize(QSize(205, 0));
        inpLength->setFont(font);
        inpLength->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(inpLength);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        inpDegOffset = new QLineEdit(layoutWidget1);
        inpDegOffset->setObjectName(QString::fromUtf8("inpDegOffset"));
        sizePolicy.setHeightForWidth(inpDegOffset->sizePolicy().hasHeightForWidth());
        inpDegOffset->setSizePolicy(sizePolicy);
        inpDegOffset->setFont(font);
        inpDegOffset->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(inpDegOffset);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_5);

        inpDegSector = new QLineEdit(layoutWidget1);
        inpDegSector->setObjectName(QString::fromUtf8("inpDegSector"));
        sizePolicy.setHeightForWidth(inpDegSector->sizePolicy().hasHeightForWidth());
        inpDegSector->setSizePolicy(sizePolicy);
        inpDegSector->setFont(font);
        inpDegSector->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(inpDegSector);


        verticalLayout_3->addLayout(horizontalLayout_4);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(1250, 560, 297, 30));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        inpPathPlot = new QLineEdit(layoutWidget2);
        inpPathPlot->setObjectName(QString::fromUtf8("inpPathPlot"));
        inpPathPlot->setFont(font2);

        horizontalLayout_8->addWidget(inpPathPlot);

        btnSavePlot = new QPushButton(layoutWidget2);
        btnSavePlot->setObjectName(QString::fromUtf8("btnSavePlot"));

        horizontalLayout_8->addWidget(btnSavePlot);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnDrawSector->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\201\320\265\320\272\321\202\320\276\321\200", nullptr));
        btnCls->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\206\320\265\320\275\321\202\321\200\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        inpXCenter->setText(QCoreApplication::translate("MainWindow", "600", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        inpYCenter->setText(QCoreApplication::translate("MainWindow", "420", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\276\321\202\320\276\320\272\320\276\320\262", nullptr));
        inpNThreads->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\207\320\260\321\201\321\202\320\265\320\271", nullptr));
        inpNParts->setText(QCoreApplication::translate("MainWindow", "352", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262", nullptr));
        inpLength->setText(QCoreApplication::translate("MainWindow", "300", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207. \321\201\320\274\320\265\321\211\320\265\320\275\320\270\320\265 (deg)", nullptr));
        inpDegOffset->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \321\201\320\265\320\272\321\202\320\276\321\200\320\260 (deg)", nullptr));
        inpDegSector->setText(QCoreApplication::translate("MainWindow", "352", nullptr));
        inpPathPlot->setText(QCoreApplication::translate("MainWindow", "..\\plot.png", nullptr));
        btnSavePlot->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
