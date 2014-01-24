#include "monster.h"

Monster::Monster()              //base monster
{

    image.load("images/Monster.jpg");

    shotType='V';
    rect = image.rect();
    x = rand()%370 + 200;
    y =1;
    rect.moveTo(x, y);
    speed = 1;
}


void Monster::moveDown()
{

    y+=speed;
    rect.moveBottom(y);             //just move down

}

void Monster::spitFireballs(int whereFire)
{
    fireballs.push_back(new fireball(x, y+30));         //add fireballs!
   fireballs.push_back(new fireball(x+whereFire, y+30));
}

/*LinkedList<fireball*>* Monster::getFireballs()
{
    return &fireBallList;
}*/


std::vector<fireball*>* Monster::getFireballs()
{
    return &fireballs;                  //return pointer to fireballs vector
}


