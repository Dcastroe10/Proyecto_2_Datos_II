/********************************************************************************
** Form generated from reading UI file 'createcanvasdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECANVASDIALOG_H
#define UI_CREATECANVASDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createCanvasDialog
{
public:
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBoxX;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBoxY;

    void setupUi(QDialog *createCanvasDialog)
    {
        if (createCanvasDialog->objectName().isEmpty())
            createCanvasDialog->setObjectName(QString::fromUtf8("createCanvasDialog"));
        createCanvasDialog->resize(201, 131);
        pushButton = new QPushButton(createCanvasDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 100, 161, 25));
        gridLayoutWidget = new QWidget(createCanvasDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 160, 83));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBoxX = new QSpinBox(gridLayoutWidget);
        spinBoxX->setObjectName(QString::fromUtf8("spinBoxX"));
        spinBoxX->setMinimum(0);
        spinBoxX->setMaximum(1024);
        spinBoxX->setSingleStep(50);
        spinBoxX->setValue(500);

        gridLayout->addWidget(spinBoxX, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spinBoxY = new QSpinBox(gridLayoutWidget);
        spinBoxY->setObjectName(QString::fromUtf8("spinBoxY"));
        spinBoxY->setMinimum(0);
        spinBoxY->setMaximum(1024);
        spinBoxY->setSingleStep(50);
        spinBoxY->setValue(500);

        gridLayout->addWidget(spinBoxY, 2, 1, 1, 1);


        retranslateUi(createCanvasDialog);

        QMetaObject::connectSlotsByName(createCanvasDialog);
    } // setupUi

    void retranslateUi(QDialog *createCanvasDialog)
    {
        createCanvasDialog->setWindowTitle(QApplication::translate("createCanvasDialog", "Nuevo lienzo...", nullptr));
        pushButton->setText(QApplication::translate("createCanvasDialog", "Aceptar", nullptr));
        label->setText(QApplication::translate("createCanvasDialog", "Dimensiones", nullptr));
        label_2->setText(QApplication::translate("createCanvasDialog", "X:", nullptr));
        label_3->setText(QApplication::translate("createCanvasDialog", "Y:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createCanvasDialog: public Ui_createCanvasDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECANVASDIALOG_H
