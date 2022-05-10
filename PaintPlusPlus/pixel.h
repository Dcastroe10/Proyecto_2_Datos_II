#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>


class pixel
{
public:
    pixel();

    uint32_t getColor() const;
    void setColor(uint32_t newColor);

    int getId() const;
    void setId(int newId);

private:
    uint32_t color = 0xffffff;
    int id = -1;

};

#endif // PIXEL_H
