#include "arrow.h"

arrow::arrow()
{
    image.load("images/followMe.png");
    shotType = 'A';
    rect = image.rect();
    x =  rand()%370 + 200;
    y = 1;
    rect.moveTo(x,y);
    speed =1;

}


void arrow::move(int newx, int newy)
{
    x += newx;
    y += newy;

   rect.translate(newx, newy);
}



int arrow::trackDirX(int x)	//returns whether the item is to the left of right of the x point
{				//(1 and -1) respectively
    if(rect.x()<x) return 1;
    else if (rect.x()>x) return -1;
    else return 0;
}

int arrow::trackDirY(int y)
{
    if (rect.y()<y) return 1;
    else if (rect.y()>y) return -1;
    else return 0;
}

