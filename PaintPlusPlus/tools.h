#ifndef TOOLS_H
#define TOOLS_H

#include "Tools/pen.h"
#include <iostream>
#include "pixel.h"
#include "Tools/pencil.h"
#include "Tools/square.h"
#include "Tools/circle.h"
#include "Tools/colorpicker.h"
#include "Tools/paintfill.h"

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
    Square square;
    circle Circle;
    colorpicker ColorPicker;
    paintfill PaintFill;


    void setMatrixPointer(pixel **newMatrixPointer);

    void drawWithPen(int posx, int posy, uint32_t color);


    void drawWithPencil(int start[], int end[], uint32_t color, int grosor);

    void drawSquare(int start[], int end[], uint32_t color, int grosor);

    void drawCircle(int start[], int end[], uint32_t color, int grosor);

    void drawWithPaintFiller(int width, int height, uint32_t color, int posX, int posY);

    uint32_t getColorColorPicker(int x, int y);

    void set_grosor(int num);
    int get_grosor();

};

#endif // TOOLS_H
