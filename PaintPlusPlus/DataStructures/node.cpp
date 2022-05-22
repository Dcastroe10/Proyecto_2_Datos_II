#include "node.h"


node::node(int x, int y, int id, int x2, int y2, int figure, int grosor)
{
    this->startX = x;
    this->startY = y;
    this->endX = x2;
    this->endY = y2;
    this->figure = figure;
    this->id = id;
    this->grosor = grosor;
}

node::node(int id) {
    this->id = id;
}

void node::setNext(node *next1) {
    next = next1;
}

int node::getId(){
    return this->id;
}

node *node::getNext()
{
    return next;
}

int node::get_startX()
{
    return this->startX;
}

int node::get_startY()
{
    return this->startY;
}

int node::get_endX()
{
    return this->endX;
}

int node::get_endY()
{
    return this->endY;
}

int node::get_figure(){
    return this->figure;
}

int node::getGrosor(){
    return this->grosor;
}
int node::getX() {
    return startX;
}

int node::getY() {
    return startY;
}

void node::setX(int newX) {
    this->startX = newX;
}

void node::setY(int newY) {
    this->startY = newY;
}

