#ifndef TOOLS_H
#define TOOLS_H

#include "Tools/pen.h"
#include <iostream>
#include "pixel.h"
#include "Tools/pencil.h"

class Tools
{
private:
    uint32_t color;
    int grosor;
    pixel **matrixPointer;

public:
    Tools();
    Pen pen;
    Pen getPen();
    Pencil pencil;

    void setMatrixPointer(pixel **newMatrixPointer);

    void drawWithPen(int posx, int posy, uint32_t color);


    void drawWithPencil(int start[], int end[], uint32_t color, int grosor);

    void set_grosor(int num);
    int get_grosor();
};

#endif // TOOLS_H
