#ifndef BFS_H
#define BFS_H

#include "pixel.h"
#include <iostream>
#include <stdint.h>
#include <QDebug>
#include "queue.h"

class bfs
{
public:
    void initBFS(int posX,int posY, pixel** matrix);
    void BFS(int width, int height, uint32_t color, pixel** matrix, int posX, int posY);


private:
    queue* queueX;
    queue* queueY;
    bool** visited;
    uint32_t colorCheck;
    bool outOfBounds(int width, int height, int posX, int posY);

};

#endif // BFS_H
