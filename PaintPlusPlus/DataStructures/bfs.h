#ifndef BFS_H
#define BFS_H

#include "queue.h"
#include "pixel.h"
#include <iostream>

class bfs
{
public:
    bfs();
    void doBFS(int width, int height, u_int32_t color, pixel** matrix, int posX, int posY);

private:
    queue* queueX;
    queue* queueY;
    bool** visited;

    int** neighbours(int width, int height, u_int32_t colorSelected, pixel** matrix, int posX, int posY);
    bool outOfBounds(int width, int height, int posX, int posY);
    void initBFS(int width, int height);
};

#endif // BFS_H
