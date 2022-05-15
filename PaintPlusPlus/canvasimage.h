#ifndef CANVASIMAGE_H
#define CANVASIMAGE_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

#include "pixel.h"

class canvasImage : public QLabel
{
    Q_OBJECT
public:
    canvasImage(QWidget *parent = 0);
    ~canvasImage();

    void createNewMatrix(int x, int y);


    pixel **getMatrix() const;

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void sendMousePosition(int&, int&);
    void sendMouseClicked(int&, int&);
    void sendMouseReleased(int&, int&);

private:
    pixel **matrix;
    int x;
    int y;
};

#endif // CANVASIMAGE_H
