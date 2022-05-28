#include "node.h"

/**
 * @brief Asignación de parámetros al nodo
 * @param x         posición inicial x
 * @param y         posición inicial y
 * @param id        identificador
 * @param x2        posición final x
 * @param y2        posición final y
 * @param figura    identificador del tipo de figura
 * @param grosor    grosor del trazo
 * @param color     color de la figura
 */
node::node(int x, int y, int id, int x2, int y2, int figure, int grosor,uint32_t color)
{
    this->startX = x;
    this->startY = y;
    this->endX = x2;
    this->endY = y2;
    this->figure = figure;
    this->id = id;
    this->grosor = grosor;
    this->color = color;
}

/**
 * @brief Constructor para cuando solo se agrega el identificador
 * @param id    Identificador
 */
node::node(int id) {
    this->id = id;
}

/**
 * @brief Define la referencia al siguiente elemento
 * @param next1     Referencia al siguiente objeto en la lista
 */
void node::setNext(node *next1) {
    next = next1;
}

/**
 * @brief Obtiene el id del nodo
 * @return el identificador del nodo
 */
int node::getId(){
    return this->id;
}

/**
 * @brief Obtiene el elemento al que "apunta"
 * @return    El puntero hacie el siguiente elemento
 */
node *node::getNext()
{
    return next;
}

/**
 * @brief Obtiene la posición x inicial del nodo
 * @return  La posición x inicial del nodo
 */
int node::get_startX()
{
    return this->startX;
}

/**
 * @brief Obtiene la posición y inicial del nodo
 * @return  La posición y inicial del nodo
 */
int node::get_startY()
{
    return this->startY;
}

/**
 * @brief Obtiene la posición x final del nodo
 * @return  La posición x final del nodo
 */
int node::get_endX()
{
    return this->endX;
}

/**
 * @brief Obtiene la posición y final del nodo
 * @return  La posición y final del nodo
 */
int node::get_endY()
{
    return this->endY;
}

/**
 * @brief Obtiene el indificador de figura del nodo
 * @return  El indicador del tipo de figura que representa el nodo
 */
int node::get_figure(){
    return this->figure;
}

/**
 * @brief Obtiene el grosor de la figura que representa el nodo
 * @return  El indentificdaor de figura del nodo
 */
int node::getGrosor(){
    return this->grosor;
}

/**
 * @brief Obtiene el color guardado en el nodo
 * @return El color guardado en el nodo
 */
uint32_t node::getColor()
{
    return this->color;
}
