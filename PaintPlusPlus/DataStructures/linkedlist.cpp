#include "linkedlist.h"


linkedList::linkedList()
{

}

void linkedList::addCoords(int x, int y) {
    if (head == NULL) {
        head = new node(x, y);
    } else {
        node *tmp = head;
        head = new node(x, y);
        head->setNext(tmp);
    }
    this->size++;
}

int* linkedList::getCoords(int index) {
    if (index < size && index >= 0) {
        node *tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->getNext();
        }
        int *returnValue = new int[2];
        returnValue[0] = tmp->getX();
        returnValue[1] = tmp->getY();
        return returnValue;
    } else {
        return NULL;
    }
}


int linkedList::deleteData(int index) {
    if (size == 1 && index == 0) {
        delete(head);
        size--;
        return 1;
    } else if (size == 0) {
        return -1;
    } else if (size == 2 && index == 1) {
        delete(head->getNext());
        head->setNext(NULL);
        size--;
        return 1;
    } else if (index < size && index >= 0) {
        node *tmp = head;
        for (int i = 0; i < index - 1; i++) {
            tmp = tmp->getNext();
        }
        node *tmpNext = tmp->getNext()->getNext();
        delete(tmp->getNext());
        tmp->setNext(tmpNext);
        size--;
        return 1;
    }
    return 0;
}

/**
 * @brief Elimina el último elemento de la lista.
 * 
 */
void linkedList::deleteLastData() {
    deleteData(size - 1);
}

/**
 * @brief Obtiene el valor del tamaño de la lista.
 * 
 * @return entero del tamaño de la lista.
 */
int linkedList::getSize() {
    return size;
}
