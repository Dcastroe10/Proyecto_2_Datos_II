#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>


class pixel
{
public:
    pixel();

    uint32_t getColor() const;
    void setColor(uint32_t newColor);
    void setFigura(int figura);
    int getFigura();

    int getId() const;

    void setId(int newId);

private:
    uint32_t color = 0xffffff;
    int id = -1;
    int figura = -1;

};

#endif // PIXEL_H
