#ifndef CANVASIMAGE_H
#define CANVASIMAGE_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class canvasImage : public QLabel
{
    Q_OBJECT
public:
    canvasImage(QWidget *parent = 0);
    ~canvasImage();

protected:
    void mouseMoveEvent(QMouseEvent *event);

signals:
    void sendMousePosition(QPoint&);
};

#endif // CANVASIMAGE_H
