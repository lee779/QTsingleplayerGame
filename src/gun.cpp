#include "gun.h"
#include "linkedlist.h"

gun::gun(int xpos) //get the xpos of the hitbox
{
    image.load("images/gun.png");
    shotType='G';
    rect = image.rect();
    x =  xpos;
    y = 1;
    rect.moveTo(x, y);
    speed = 1;
}

void gun::spitFireballs(int whereFire)
{
    fireballs.push_back(new fireball(x+15, y+32));

   //  fireballs.push_back(new fireball(x,y+30+whereFire*2));
}


std::vector<fireball*>* gun::getFireballs()
{
    return &fireballs;                  //return pointer to fireballs vector

}
/*LinkedList<fireball*>* gun::getFireballs()
{
    return &fireBallList;
}*/

void gun::moveLeft(){
    if (rect.left() >=202 )
        rect.moveTo((--x), rect.top());
    }
void gun::moveRight(){
    if (rect.right() <=600 )
         rect.moveTo((++x), rect.top());
    }
void gun::moveDown(){
rect.moveTo(x, y);
}
