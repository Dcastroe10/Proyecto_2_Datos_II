#ifndef CREATECANVASDIALOG_H
#define CREATECANVASDIALOG_H

#include <QDialog>

namespace Ui {
class createCanvasDialog;
}

class createCanvasDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createCanvasDialog(QWidget *parent = nullptr);
    ~createCanvasDialog();

private slots:
    void on_pushButton_clicked();


signals:
    void accept(int&, int&);

private:
    Ui::createCanvasDialog *ui;
    int x;
    int y;
};

#endif // CREATECANVASDIALOG_H
