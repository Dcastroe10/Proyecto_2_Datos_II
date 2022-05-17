#include "circle.h"

#include <QDebug>

circle::circle()
{

}


void circle::draw_circle(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor){
    int radius = abs((start[0]-end[0])/2);
    int center;
    if (start[0] < end[0]){
        center = start[0]+radius;
    }else{
        center = start[0] - radius;
    }
    qDebug()<<"entroooooooooooooo    "<<radius<<"      radioooo";
    qDebug()<<"entroooooooooooooo    "<<center<<"      centeeeer";

}
