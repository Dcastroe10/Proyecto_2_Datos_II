#include "node.h"


node::node(int x, int y)
{
    this->value1 = x;
    this->value2 = y;
}

node::node() {

}

void node::setNext(node *next1) {
    next = next1;
}

node *node::getNext()
{
    return next;
}

int node::getX() {
    return value1;
}

int node::getY() {
    return value2;
}

void node::setX(int newX) {
    this->value1 = newX;
}

void node::setY(int newY) {
    this->value2 = newY;
}

