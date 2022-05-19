/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <canvasimage.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    canvasImage *canvasLabel;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *Color_button;
    QPushButton *figureeraserButton;
    QPushButton *squareButton;
    QPushButton *penButton;
    QPushButton *pencilButton;
    QLabel *label;
    QPushButton *circle_Button;
    QSpinBox *spinBox;
    QPushButton *colorPickerButton;
    QPushButton *eraserButton;
    QPushButton *paintFillButton;
    QPushButton *pushButton_3;
    QLabel *mouseLocationLabel;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1132, 693);
        QPalette palette;
        MainWindow->setPalette(palette);
        actionNuevo = new QAction(MainWindow);
        actionNuevo->setObjectName(QString::fromUtf8("actionNuevo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(240, 10, 841, 631));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        canvasLabel = new canvasImage(gridLayoutWidget);
        canvasLabel->setObjectName(QString::fromUtf8("canvasLabel"));
        canvasLabel->setEnabled(false);
        canvasLabel->setCursor(QCursor(Qt::CrossCursor));
        canvasLabel->setFrameShape(QFrame::StyledPanel);
        canvasLabel->setScaledContents(true);
        canvasLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(canvasLabel, 0, 1, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 152, 403));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Color_button = new QPushButton(gridLayoutWidget_2);
        Color_button->setObjectName(QString::fromUtf8("Color_button"));

        gridLayout_2->addWidget(Color_button, 4, 1, 1, 1);

        figureeraserButton = new QPushButton(gridLayoutWidget_2);
        figureeraserButton->setObjectName(QString::fromUtf8("figureeraserButton"));

        gridLayout_2->addWidget(figureeraserButton, 9, 1, 1, 1);

        squareButton = new QPushButton(gridLayoutWidget_2);
        squareButton->setObjectName(QString::fromUtf8("squareButton"));

        gridLayout_2->addWidget(squareButton, 2, 1, 1, 1);

        penButton = new QPushButton(gridLayoutWidget_2);
        penButton->setObjectName(QString::fromUtf8("penButton"));
        penButton->setEnabled(false);

        gridLayout_2->addWidget(penButton, 0, 1, 1, 1);

        pencilButton = new QPushButton(gridLayoutWidget_2);
        pencilButton->setObjectName(QString::fromUtf8("pencilButton"));
        pencilButton->setEnabled(false);

        gridLayout_2->addWidget(pencilButton, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 7, 1, 1, 1);

        circle_Button = new QPushButton(gridLayoutWidget_2);
        circle_Button->setObjectName(QString::fromUtf8("circle_Button"));

        gridLayout_2->addWidget(circle_Button, 3, 1, 1, 1);

        spinBox = new QSpinBox(gridLayoutWidget_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(2);
        spinBox->setMaximum(100);
        spinBox->setSingleStep(2);

        gridLayout_2->addWidget(spinBox, 8, 1, 1, 1);

        colorPickerButton = new QPushButton(gridLayoutWidget_2);
        colorPickerButton->setObjectName(QString::fromUtf8("colorPickerButton"));

        gridLayout_2->addWidget(colorPickerButton, 5, 1, 1, 1);

        eraserButton = new QPushButton(gridLayoutWidget_2);
        eraserButton->setObjectName(QString::fromUtf8("eraserButton"));

        gridLayout_2->addWidget(eraserButton, 10, 1, 1, 1);

        paintFillButton = new QPushButton(gridLayoutWidget_2);
        paintFillButton->setObjectName(QString::fromUtf8("paintFillButton"));

        gridLayout_2->addWidget(paintFillButton, 6, 1, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 540, 89, 31));
        mouseLocationLabel = new QLabel(centralwidget);
        mouseLocationLabel->setObjectName(QString::fromUtf8("mouseLocationLabel"));
        mouseLocationLabel->setGeometry(QRect(0, 620, 93, 22));
        mouseLocationLabel->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 580, 91, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1132, 27));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, toolBar);

        menubar->addAction(menuArchivo->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionNuevo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Paint++", nullptr));
        actionNuevo->setText(QCoreApplication::translate("MainWindow", "Nuevo...", nullptr));
        canvasLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">No hay ning\303\272n lienzo</span><br/>\302\241Inicia uno nuevo!</p></body></html>", nullptr));
        Color_button->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        figureeraserButton->setText(QCoreApplication::translate("MainWindow", "Figure eraser", nullptr));
        squareButton->setText(QCoreApplication::translate("MainWindow", "Cuadrado", nullptr));
        penButton->setText(QCoreApplication::translate("MainWindow", "Pen", nullptr));
        pencilButton->setText(QCoreApplication::translate("MainWindow", "Pencil", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Grosor general:", nullptr));
        circle_Button->setText(QCoreApplication::translate("MainWindow", "C\303\255rculo", nullptr));
        colorPickerButton->setText(QCoreApplication::translate("MainWindow", "Color Picker", nullptr));
        eraserButton->setText(QCoreApplication::translate("MainWindow", "Free eraser", nullptr));
        paintFillButton->setText(QCoreApplication::translate("MainWindow", "PaintFill", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        mouseLocationLabel->setText(QCoreApplication::translate("MainWindow", "0, 0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Coords (x,y)", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
