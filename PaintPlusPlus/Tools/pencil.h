#ifndef PENCIL_H
#define PENCIL_H

#include <pixel.h>
#include <QDebug>

class Pencil
{
public:
   Pencil();
   void drawALineInCanvas(pixel **canvas, int start[], int end[], uint32_t color, int grosor, int id, double zoom);

private:
    float mResult(int start[], int end[]);
    float bResult(int x, int y, float m);
};

#endif // PENCIL_H
