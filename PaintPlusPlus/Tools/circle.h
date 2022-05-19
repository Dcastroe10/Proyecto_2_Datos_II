#ifndef CIRCLE_H
#define CIRCLE_H
#include "pixel.h"
#include <cmath>


class circle
{
public:
    circle();

    void draw_circle(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor, int id);

    void put_pixel(pixel **canvas,int x, int y, int centerx, int centery, uint32_t color, int grosor, int id);
};



#endif // CIRCLE_H
