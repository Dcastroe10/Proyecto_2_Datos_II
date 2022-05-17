#ifndef SQUARE_H
#define SQUARE_H
#include "pixel.h"

class Square
{
public:
    Square();
    void draw_square_in_canvas(pixel **canvas, int start[], int end[], uint32_t color, int grosor);
};

#endif // SQUARE_H
