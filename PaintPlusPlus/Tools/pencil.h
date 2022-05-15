#ifndef PENCIL_H
#define PENCIL_H

#include <pixel.h>
#include <QDebug>

class Pencil
{
public:
   Pencil();
   void drawALineInCanvas(pixel **canvas, int start[], int end[], uint32_t color);

private:
    float mResult(int start[], int end[]);
    float bResult(int x, int y, int m);
};

#endif // PENCIL_H
