#ifndef SQUARE_H
#define SQUARE_H
#include "pixel.h"

class Square
{
public:
    Square();
    void draw_square_in_canvas(pixel **canvas, int start[], int end[], uint32_t color, int grosor, int id, double zoom, int width, int height);
    bool outOfBounds(int width, int height, int posX, int posY);
};

#endif // SQUARE_H
