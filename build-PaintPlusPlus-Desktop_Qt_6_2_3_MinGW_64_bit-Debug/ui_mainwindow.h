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
    QAction *actionAbrir;
    QAction *actionGuardar_como;
    QAction *action90;
    QAction *action90_izquierda;
    QAction *actionFlip_vertical;
    QAction *actionFlip_horizontal;
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
    QPushButton *undoButton;
    QPushButton *redoButton;
    QPushButton *redolistButton;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuImagen;
    QMenu *menuRotar;
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
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        actionGuardar_como = new QAction(MainWindow);
        actionGuardar_como->setObjectName(QString::fromUtf8("actionGuardar_como"));
        action90 = new QAction(MainWindow);
        action90->setObjectName(QString::fromUtf8("action90"));
        action90_izquierda = new QAction(MainWindow);
        action90_izquierda->setObjectName(QString::fromUtf8("action90_izquierda"));
        actionFlip_vertical = new QAction(MainWindow);
        actionFlip_vertical->setObjectName(QString::fromUtf8("actionFlip_vertical"));
        actionFlip_horizontal = new QAction(MainWindow);
        actionFlip_horizontal->setObjectName(QString::fromUtf8("actionFlip_horizontal"));
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
        Color_button->setEnabled(false);

        gridLayout_2->addWidget(Color_button, 4, 1, 1, 1);

        figureeraserButton = new QPushButton(gridLayoutWidget_2);
        figureeraserButton->setObjectName(QString::fromUtf8("figureeraserButton"));
        figureeraserButton->setEnabled(false);

        gridLayout_2->addWidget(figureeraserButton, 9, 1, 1, 1);

        squareButton = new QPushButton(gridLayoutWidget_2);
        squareButton->setObjectName(QString::fromUtf8("squareButton"));
        squareButton->setEnabled(false);

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
        circle_Button->setEnabled(false);

        gridLayout_2->addWidget(circle_Button, 3, 1, 1, 1);

        spinBox = new QSpinBox(gridLayoutWidget_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setMinimum(2);
        spinBox->setMaximum(100);
        spinBox->setSingleStep(2);

        gridLayout_2->addWidget(spinBox, 8, 1, 1, 1);

        colorPickerButton = new QPushButton(gridLayoutWidget_2);
        colorPickerButton->setObjectName(QString::fromUtf8("colorPickerButton"));
        colorPickerButton->setEnabled(false);

        gridLayout_2->addWidget(colorPickerButton, 5, 1, 1, 1);

        eraserButton = new QPushButton(gridLayoutWidget_2);
        eraserButton->setObjectName(QString::fromUtf8("eraserButton"));
        eraserButton->setEnabled(false);

        gridLayout_2->addWidget(eraserButton, 10, 1, 1, 1);

        paintFillButton = new QPushButton(gridLayoutWidget_2);
        paintFillButton->setObjectName(QString::fromUtf8("paintFillButton"));
        paintFillButton->setEnabled(false);

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
        undoButton = new QPushButton(centralwidget);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));
        undoButton->setGeometry(QRect(20, 470, 51, 31));
        redoButton = new QPushButton(centralwidget);
        redoButton->setObjectName(QString::fromUtf8("redoButton"));
        redoButton->setGeometry(QRect(80, 470, 41, 31));
        redolistButton = new QPushButton(centralwidget);
        redolistButton->setObjectName(QString::fromUtf8("redolistButton"));
        redolistButton->setGeometry(QRect(140, 580, 89, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1132, 27));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuImagen = new QMenu(menubar);
        menuImagen->setObjectName(QString::fromUtf8("menuImagen"));
        menuRotar = new QMenu(menuImagen);
        menuRotar->setObjectName(QString::fromUtf8("menuRotar"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, toolBar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuImagen->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionNuevo);
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionGuardar_como);
        menuImagen->addAction(menuRotar->menuAction());
        menuRotar->addAction(action90);
        menuRotar->addAction(action90_izquierda);
        menuRotar->addAction(actionFlip_vertical);
        menuRotar->addAction(actionFlip_horizontal);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Paint++", nullptr));
        actionNuevo->setText(QCoreApplication::translate("MainWindow", "Nuevo...", nullptr));
        actionAbrir->setText(QCoreApplication::translate("MainWindow", "Abrir...", nullptr));
        actionGuardar_como->setText(QCoreApplication::translate("MainWindow", "Guardar como...", nullptr));
        action90->setText(QCoreApplication::translate("MainWindow", "90\302\260 derecha", nullptr));
        action90_izquierda->setText(QCoreApplication::translate("MainWindow", "90\302\260 izquierda", nullptr));
        actionFlip_vertical->setText(QCoreApplication::translate("MainWindow", "Flip vertical", nullptr));
        actionFlip_horizontal->setText(QCoreApplication::translate("MainWindow", "Flip horizontal", nullptr));
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
        undoButton->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        redoButton->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        redolistButton->setText(QCoreApplication::translate("MainWindow", "Redolist", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuImagen->setTitle(QCoreApplication::translate("MainWindow", "Imagen", nullptr));
        menuRotar->setTitle(QCoreApplication::translate("MainWindow", "Rotar", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H