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


    qDebug()<<"entroooooooooooooo    "<<radius<<"      radioooo";
    qDebug()<<"entroooooooooooooo    "<<centerx<<"      centeeeer";



  /*
    for (int i = -grosor; i < grosor; i++){
        for(int j = -grosor; j < grosor; j++){
            canvas[centerx + i][centery + j].setColor(color);

            //En x
            canvas[centerx + radius + i][centery + j].setColor(color);
            canvas[centerx - radius + i][centery + j].setColor(color);
            //EN Y
            canvas[centerx + i][centery + radius + j].setColor(color);
            canvas[centerx + i][centery - radius + j].setColor(color);


            //revisar que siga siendo el radio y ajaa
            canvas[centerx + i + 5][centery + radius + j].setColor(color);
            canvas[centerx + i + 5][centery - radius + j].setColor(color);
        }
    }

*/


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
