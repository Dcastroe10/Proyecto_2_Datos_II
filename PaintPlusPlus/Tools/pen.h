#ifndef PEN_H
#define PEN_H

#include "pixel.h"
#include <iostream>
#include <QDebug>

class Pen
{
public:
    Pen();

    void drawInCanvas(pixel** canvas, int posx, int posy, uint32_t color);

};

#endif // PEN_H
