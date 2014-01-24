#include "bomb.h"

Bomb::Bomb(int xpos)
{
    timerExplosion = 300;
    image.load("images/bomb.png");
    shotType='@';
    rect = image.rect();
    x =  xpos;
    y = 1;
    rect.moveTo(x, y);
    speed = 1;
    dontMove= false;
}


void Bomb::moveDown(){

    if (dontMove)
    {timerExplosion--;}
    else
    {
        y+=speed;
        rect.moveBottom(y);
    }
}

void Bomb::move(int newx, int newy)
{
       x += newx;
       y += newy;

      rect.translate(newx, newy);

}

int Bomb::getTimer()
{
    return timerExplosion;
}

void Bomb::setExplosion(){
    int xpos = x;
    shotType = 'E';
    image.load("images/explosion.png");
    rect = image.rect();
    x = xpos;
    y = 1;
    rect.moveTo(x,y);
    dontMove = true;
}


int Bomb::trackDirX(int x)	//returns whether the item is to the left of right of the x point
{				//(1 and -1) respectively
    if(rect.x()<x) return 1;
    else if (rect.x()>x) return -1;
    else return 0;
}
