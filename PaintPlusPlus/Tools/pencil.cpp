#include "pencil.h"

Pencil::Pencil()
{

}

float Pencil::mResult(int start[2], int end[2]) {
    float m = (end[1] - start[1]) / (end[0] - start[0]);
    return m;
}

float Pencil::bResult(int x, int y, int m) {
    float b = y - (m * x);
    return b;
}

/*
void Pencil::drawALineInCanvas(pixel **canvas, int start[2], int end[2], uint32_t color) {
    float m = mResult(start, end);
    float b = bResult(start[0], start[1], m);
    float y = 0;

    int xi = 0;
    int yi = 0;

    float startX = start[0];
    float endX = end[0];


    if (start[0] > end[0]) {
        for (startX; startX > endX; startX += 0.1) {
            y = (m * startX) + b;
            //xi = int(x);
            //yi = int(y);
            //qDebug() << "line >";
            //canvas[xi][yi].setColor(color);
        }
    } else {
        for (int x = start[0]; x < end[0]; x++) {
            y = (m * x) + b;
            qDebug() << "line <";
            //canvas[x][y].setColor(color);
        }
    }

}
*/

