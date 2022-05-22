#ifndef TOOLS_H
#define TOOLS_H

#include "Tools/pen.h"
#include <iostream>
#include "pixel.h"
#include "Tools/pencil.h"
#include "Tools/square.h"
#include "Tools/circle.h"
#include "Tools/colorpicker.h"
#include "Tools/paintfill.h"
#include "Tools/bmp.h"
#include "Tools/rotate.h"
#include "DataStructures/linkedlist.h"

class Tools
{
private:
    uint32_t color;
    int grosor;
    pixel **matrixPointer;
    rotater rot;

public:
    Tools();
    Pen pen;
    Pen getPen();
    Pencil pencil;
    Square square;
    circle Circle;
    colorpicker ColorPicker;
    paintfill PaintFill;
    bmp BMP;
    linkedList lista_Undo;
    linkedList lista_Redo;


    void setMatrixPointer(pixel **newMatrixPointer);

    void drawWithPen(int posx, int posy, uint32_t color, int id);


    void drawWithPencil(int start[], int end[], uint32_t color, int grosor, int id);

    void drawSquare(int start[], int end[], uint32_t color, int grosor, int id);

    void drawCircle(int start[], int end[], uint32_t color, int grosor, int id);

    void drawWithPaintFiller(int width, int height, uint32_t color, int posX, int posY, int id);

    void add_toUndoList(int x, int y, int id, int x2, int y2, int figura, int grosor);

    void add_toRedoList(int x, int y, int id, int x2, int y2, int figura, int grosor);

    uint32_t getColorColorPicker(int x, int y);

    void set_grosor(int num);
    int get_grosor();

    rotater getRot();

    void print_listUndo();
    int getUndo();
    void deleteUndo();
    int getUndoSize();
    int getStartX_UndoList();
    int getStartY_UndoList();
    int getEndX_UndoList();
    int getEndY_UndoList();
    int getRedo();
    int getRedoSize();
    void deleteRedo();
    int getUndoFigura();
    int getRedoFigura();
    int getStartX_RedoList();
    int getStartY_RedoList();
    int getEndX_RedoList();
    int getEndY_RedoList();
    int getGrosorRedo();
    int getGrosorUndo();
};

#endif // TOOLS_H
