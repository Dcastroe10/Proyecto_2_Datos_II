#ifndef NODE_H
#define NODE_H

#include <string.h>
#include <iostream>

class node
{
private:
    node *next = NULL;
    int value1 = 0;
    int value2 = 0;
public:
    node(int x, int y);
    node();
    int getX();
    int getY();
    void setX(int newX);
    void setY(int newY);
    void setNext(node *next1);
    node* getNext();
};

#endif // NODE_H