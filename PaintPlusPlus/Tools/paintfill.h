#ifndef PAINTFILL_H
#define PAINTFILL_H

#include "DataStructures/bfs.h"
#include "pixel.h"

class paintfill
{
private:
    bfs BFS;
public:
    paintfill();
    void doPaintFill(int width, int height, int color, pixel** matrix, int posX, int posY, int id);
};

#endif // PAINTFILL_H
