#include "circle.h"

#include <QDebug>

circle::circle()
{

}


void circle::draw_circle(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor){
    int radius = abs((start[0]-end[0])/2);
    int centerx;
    int centery;
    //brensananahbsadmsadjlaksdasd method
    int x=0;
    int y = radius;
    int d = 3-2*radius;

    if (start[0] < end[0]){
        centerx = start[0]+radius;
    }else{
        centerx = start[0] - radius;
    }

    if(start[1]< end[1]){
        centery = start[1] + radius;

    }else{
        centery = start[1] - radius;
    }

    while(x<=y){

        this->put_pixel(canvas, x, y, centerx, centery, color, grosor);

        if(d<0){
            d = d + 4 * x + 6;
        }else{
            d = d + 4 * x - 4 * y + 10;
            y--;
        }
        x++;

    }

}


void circle::put_pixel(pixel **canvas,int x, int y, int centerx, int centery, uint32_t color, int grosor){
    for (int i = -grosor; i < grosor; i++){
        for(int j = -grosor; j < grosor; j++){

            canvas[x + centerx + i][ y + centery + j].setColor(color);

            canvas[x + centerx + i][ -y + centery + j].setColor(color);

            canvas[-x + centerx + i][ -y + centery + j].setColor(color);

            canvas[-x + centerx + i][ y + centery + j].setColor(color);

            canvas[y + centerx + i][ x + centery + j].setColor(color);

            canvas[y + centerx + i][ -x + centery + j].setColor(color);

            canvas[-y + centerx + i][ -x + centery + j].setColor(color);

            canvas[-y + centerx + i][ x + centery + j].setColor(color);







        }
    }
}
