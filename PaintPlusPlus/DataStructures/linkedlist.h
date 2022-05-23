#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <iostream>

class linkedList
{
private:
    node *head = NULL;
    int size = 0;
public:
    linkedList();
    void addCoords(int x, int y, int id, int x2, int y2, int figura, int grosor, uint32_t color);
    int* getCoords(int index);
    int deleteData(int index);
    void deleteLastData();
    int getSize();
    int get_head_Id();
    int get_head_startX();
    int get_head_startY();
    int get_head_endX();
    int get_head_endY();
    int getId(int index);
    void delete_head();
    int get_head_figure();
    int getGrosor();
    uint32_t getColor();
};

#endif // LINKEDLIST_H
