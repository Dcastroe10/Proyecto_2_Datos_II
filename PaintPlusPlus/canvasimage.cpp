#include "canvasimage.h"

canvasImage::canvasImage(QWidget* parent) :
    QLabel(parent)
{

}

canvasImage::~canvasImage()
{

}

void canvasImage::mouseMoveEvent(QMouseEvent *event)
{
    QPoint mousePos = event->pos();
    x = event->pos().x();
    y = event->pos().y();

    if (x <= this->size().width() && y <= this->size().height()) {
        if (x > 0 && y > 0) {
            emit sendMousePosition(x, y);
            qDebug() << mousePos.x() << mousePos.y();
        }
    }
}


