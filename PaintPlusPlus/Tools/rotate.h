#ifndef ROTATER_H
#define ROTATER_H

#include "pixel.h"
#include <QDebug>

class rotater
{
public:
    rotater();

    pixel** rotate90(pixel** oldMatrix, int oldWidth, int oldHeight);
    pixel** flipVertical(pixel** oldMatrix, int oldWidth, int oldHeight);
    pixel** matrixCreator(int width, int height);
    pixel** flipHorizontal(pixel **oldMatrix, int oldWidth, int oldHeight);
};

#endif // ROTATER_H
