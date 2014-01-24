#include "boss.h"


Boss::Boss()
{
   // timerToDeath = 500;             //500 cycles to live!
    shotType='B';
    image.load("images/fireboss.jpg");
    x = 400;
    vdirection = 'd';               //starts moving downwards
    rect = image.rect();
    rect.moveTo(x, y);
    speed = 1;
    int choosedir = rand()%370 + 200;
    if (choosedir > 400)                //left or right starting direction
        hdirection = 'r';
    else
        hdirection = 'l';
}

void Boss::moveDown(){

    if (rect.left() <=202 )             //if hits wall, changes direction
        hdirection = 'r';
    if (rect.right() > 600 )
        hdirection = 'l';

    if (hdirection == 'r')                  //moves left or right depending on currently set direction
        rect.moveTo((++x), rect.top());
    if (hdirection == 'l')
        rect.moveTo((--x), rect.top());

    if (rect.top() < 1 )                //doesn't move past 200 pixels down
        vdirection = 'd';
    if (rect.bottom() > 200 )
        vdirection = 'u';

    if (vdirection == 'u')                  //moves up or down depending
        rect.moveTo(rect.left(), --y);
    if (vdirection == 'd')
        rect.moveTo(rect.left(), ++y);


}

int Boss::getTimer(){
    return timerToDeath;
}

/*void Boss::spitFireballs(int howMany)
{
    if(howMany ==2)
    {
        fireBallList.push_front(new fireball(x,y+30));
        fireBallList.push_front(new fireball(x+150,y+30));

    }
}*/

void Boss::spitFireballs(int howMany)
{

    if (howMany == 2)
    {
        fireballs.push_back(new fireball(x, y+30));         //add fireballs!
        fireballs.push_back(new fireball(x+150, y+30));
    }
    if (howMany ==3)
    {
        fireballs.push_back(new fireball(x, y+30));         //add fireballs!
        fireballs.push_back(new fireball(x+80, y+30));
        fireballs.push_back(new fireball(x+160,y+30));
    }
}

void Boss::setExplosion()
{
    image.load("images/fireboss_dead.jpg");
    rect = image.rect();
    rect.moveTo(x, y);
    //timerToDeath = 400;
}
