#include "linkedlist.h"

linkedList::linkedList()
{

}
/**
 * @brief Agrega un nodo a la lista enlazada
 * @param x         posición inicial x
 * @param y         posición inicial y
 * @param id        identificador
 * @param x2        posición final x
 * @param y2        posición final y
 * @param figura    identificador del tipo de figura
 * @param grosor    grosor del trazo
 * @param color     color de la figura
 */
void linkedList::addCoords(int x, int y, int id, int x2, int y2, int figura, int grosor,uint32_t color) {  //codigo de numeros para saber que figura es
    if (head == NULL) {
        head = new node(x, y, id, x2, y2, figura, grosor, color);
    } else {
        node *tmp = head;
        head = new node(x, y, id, x2, y2, figura, grosor,color);
        head->setNext(tmp);
    }
    this->size++;
}

/**
 * @brief Obtiene las coordenadas (x,y) de un elemento de la lista por medio del índice del mismo
 * @param index     índice de posición
 * @return array con las coordenadas del elemento en la lista
 */
int* linkedList::getCoords(int index) {
    if (index < size && index >= 0) {
        node *tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->getNext();
        }
        int *returnValue = new int[2];
        returnValue[0] = tmp->get_startX();
        returnValue[1] = tmp->get_startY();
        return returnValue;
    } else {
        return NULL;
    }
}

/**
 * @brief Obtiene el identificador del elemento en la lista
 * @param index     indice del elemento en la lista
 * @return entero que representa el identificador del elemento
 */
int linkedList::getId(int index){
    if (index < size && index >= 0) {
        node *tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->getNext();
        }
        int returnValue;
        returnValue = tmp->getId();
        return returnValue;
    } else {
        return NULL;
    }
}

/**
 * @brief Elimina el primer elemento de la lista enlazada
 */
void linkedList::delete_head(){  
    head = head->getNext();
    size--;
}

/**
 * @brief Obtiene el id del primer elemento de la lista enlazada
 * @return el identificador del primer elemento
 */
int linkedList::get_head_Id(){
    return head->getId();
}

/**
 * @brief obtiene el la coordenada x del primer elemento de la lista
 * @return La posición x inicial del primer elemento en la lista
 */
int linkedList::get_head_startX()
{
    return head->get_startX();
}

/**
 * @brief obtiene el la coordenada y del primer elemento de la lista
 * @return La posición y inicial del primer elemento en la lista
 */
int linkedList::get_head_startY()
{
    return head->get_startY();
}

/**
 * @brief obtiene el la coordenada x del primer elemento de la lista
 * @return La posición x final del primer elemento en la lista
 */
int linkedList::get_head_endX()
{
    return head->get_endX();
}

/**
 * @brief obtiene el la coordenada y del primer elemento de la lista
 * @return La posición y final del primer elemento en la lista
 */
int linkedList::get_head_endY()
{
    return head->get_endY();
}

/**
 * @brief obtiene el identificador de figura del primer elemento de la lista
 * @return el identificador de figura del primer elemento de la lista
 */
int linkedList::get_head_figure(){
    return head->get_figure();
}

/**
 * @brief Obtiene el grosor asignado al primer elemento de la lista
 * @return el grosor del primer elemento de la lista
 */
int linkedList::getGrosor(){
    return head->getGrosor();
}

/**
 * @brief Obtiene el color asignado al primer elemento de la lista
 * @return el color del primer elemento de la lista
 */
uint32_t linkedList::getColor()
{
    return head->getColor();
}

/**
 * @brief Obtiene el valor del tamaño de la lista.
 * @return entero del tamaño de la lista.
 */
int linkedList::getSize() {
    return size;
}
