#include "createcanvasdialog.h"
#include "ui_createcanvasdialog.h"
#include <QMessageBox>
#include <QtDebug>

createCanvasDialog::createCanvasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createCanvasDialog)
{
    ui->setupUi(this);
}

createCanvasDialog::~createCanvasDialog()
{
    qDebug() << "close";
    delete ui;
}


void createCanvasDialog::on_pushButton_clicked()
{
    this->x = ui->spinBoxX->value();
    this->y = ui->spinBoxY->value();

    if (this->x != 0 && this->y != 0) {
        emit accept(x, y);
        this->close();
    } else {
        QMessageBox::about(this, "Error", "El valor de las dimensiones no puede ser cero");
    }


}


