#ifndef NODE_H
#define NODE_H

#include <string.h>
#include <iostream>

class node
{
private:
    node *next = NULL;
    int startX = -1;
    int startY = -1;
    int endX = -1;
    int endY = -1;
    int grosor;
    int id = -1;
    int figure = -1;
    uint32_t color;
public:
    node(int x, int y, int id, int x2, int y2, int figure, int grosor,uint32_t color);
    node(int id);

    node();
    int getX();
    int getY();
    void setX(int newX);
    void setY(int newY);
    void setNext(node *next1);
    node* getNext();

    int get_startX();
    int get_startY();
    int get_endX();
    int get_endY();
    int getId();
    int get_figure();
    int getGrosor();
    uint32_t getColor();
};

#endif // NODE_H
