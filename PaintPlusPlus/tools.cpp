#include "tools.h"

void Tools::setMatrixPointer(pixel **newMatrixPointer)
{
    matrixPointer = newMatrixPointer;
}

rotater Tools::getRot()
{
    return rot;
}

double Tools::getZoom() const
{
    return zoom;
}

void Tools::setZoom(double newZoom)
{
    zoom = newZoom;
}

Tools::Tools()
{

}

Pen Tools::getPen()
{
    return pen;
}

void Tools::drawWithPen(int posx, int posy, uint32_t color, int id)
{
    pen.drawInCanvas(this->matrixPointer, posx, posy, color, id);
}

void Tools::drawWithPencil(int start[2], int end[2], uint32_t color, int grosor, int id, int width, int height) {
    pencil.drawALineInCanvas(this->matrixPointer, start, end, color, grosor, id, this->zoom, width , height);
    this->add_toUndoList(start[0],start[1],id,end[0],end[1],1,grosor,color);
}

void Tools::drawSquare(int *start, int *end, uint32_t color, int grosor, int id){
    square.draw_square_in_canvas(this->matrixPointer,start, end, color, grosor, id, this->zoom);
    this->add_toUndoList(start[0],start[1],id,end[0],end[1],2,grosor,color);
}

void Tools::drawCircle(int *start, int *end, uint32_t color, int grosor, int id){
    Circle.draw_circle(this->matrixPointer,start, end, color, grosor, id);
    this->add_toUndoList(start[0],start[1],id,end[0],end[1],3,grosor,color);
}

void Tools::drawWithPaintFiller(int width, int height, uint32_t color, int posX, int posY, int id)
{
    PaintFill.doPaintFill(width, height, color, this->matrixPointer, posX, posY, id);
     this->add_toUndoList(-1,-1,id,-1,-1,-1,-1,color);//paintfilleeerr
}


uint32_t Tools::getColorColorPicker(int x, int y) {
    return this->ColorPicker.getColorInMatrix(this->matrixPointer, x, y);
}

void Tools::rectangularSelection(int *start, int *end){
    int startx= start[0];
    int starty = start[1];
    int endx = end[0];
    int endy = end[1];
    int m = 0;
    int n = 0;

    int ciclo_startx;
    int ciclo_starty;
    int ciclo_endx;
    int ciclo_endy;

    if(startx < endx){
        ciclo_startx = startx;
        ciclo_endx = endx;
    }else{
         ciclo_startx = endx;
         ciclo_endx = startx;
    }

    if(starty<endy){
        ciclo_starty = starty;
        ciclo_endy = endy;
    }else{
        ciclo_starty = endy;
        ciclo_endy = starty;

    }

    for (int i = ciclo_startx; i < ciclo_endx; i++){
        for(int j = ciclo_starty ; j < ciclo_endy; j++){
            this->RectangularSelected[m][n] = this->matrixPointer[i][j];
            qDebug()<<this->RectangularSelected[m][n].getId();
            n++;
        }
        m++;
        n=0;

    }


}

void Tools::set_RectangularSelected_size(int width, int height)
{
    delete[] RectangularSelected;
    RectangularSelected = new pixel* [width];
    for (int p = 0; p<height;p++){
        RectangularSelected[p] = new pixel [height];
    }

}




void Tools::set_grosor(int num){
    this->grosor = num;
}

int Tools::get_grosor(){
    return grosor;
}




void Tools::add_toUndoList(int x, int y, int id, int x2, int y2, int figura, int grosor,uint32_t color)
{
    this->lista_Undo.addCoords(x,y,id,x2,y2, figura, grosor,color);
    qDebug()<<lista_Undo.getCoords(0)[0]<<lista_Undo.getCoords(0)[1]<<"cooordsss";
    qDebug()<<"ID"<<lista_Undo.get_head_Id();
}
void Tools::deleteUndo(){
    this->lista_Undo.delete_head();
}

void Tools::deleteRedo(){
    this->lista_Redo.delete_head();
}

void Tools::add_toRedoList(int x, int y, int id,int x2, int y2, int figura, int grosor,uint32_t color)
{
    this->lista_Redo.addCoords(x,y,id,x2,y2, figura, grosor,color);
    qDebug()<<lista_Redo.getCoords(0)[0]<<lista_Redo.getCoords(0)[1]<<"cooordsss";
    qDebug()<<"ID"<<lista_Redo.get_head_Id();
}

void Tools::print_listUndo(){
    for (int i = 0; i<5;i++){
        qDebug()<<lista_Undo.getId(i);
    }
}

int Tools::getUndo(){
    if(lista_Undo.get_head_Id() != -1){
        return lista_Undo.get_head_Id();
    }
    return -1;
}

int Tools::getUndoSize(){
    return this->lista_Undo.getSize();
}

int Tools::getGrosorUndo(){
    return this->lista_Undo.getGrosor();
}

uint32_t Tools::getColorUndo()
{
    return this->lista_Undo.getColor();
}

uint32_t Tools::getColorRedo()
{
    return this->lista_Redo.getColor();
}


int Tools::getRedo(){
    if(lista_Redo.get_head_Id() != -1){
        return lista_Redo.get_head_Id();
    }
    return -1;
}

int Tools::getRedoSize(){
    return this->lista_Redo.getSize();
}

int Tools::getStartX_UndoList(){
    return this->lista_Undo.get_head_startX();
}

int Tools::getStartY_UndoList(){
    return this->lista_Undo.get_head_startY();
}

int Tools::getEndX_UndoList(){
    return this->lista_Undo.get_head_endX();
}

int Tools::getEndY_UndoList(){
    return this->lista_Undo.get_head_endY();
}

int Tools::getUndoFigura(){
    return this->lista_Undo.get_head_figure();
}

int Tools::getRedoFigura(){
    return this->lista_Redo.get_head_figure();
}


int Tools::getStartX_RedoList(){
    return this->lista_Redo.get_head_startX();
}

int Tools::getStartY_RedoList(){
    return this->lista_Redo.get_head_startY();
}

int Tools::getEndX_RedoList(){
    return this->lista_Redo.get_head_endX();
}

int Tools::getEndY_RedoList(){
    return this->lista_Redo.get_head_endY();
}

int Tools::getGrosorRedo(){
    return this->lista_Redo.getGrosor();
}



