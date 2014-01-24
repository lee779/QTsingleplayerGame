#include "zigzagmonster.h"
#include "linkedlist.h"


zigzagMonster::zigzagMonster()
{
    image.load("images/zigzagger.jpg");
    shotType = 'Z';
    rect  = image.rect();
     x = rand()%370 + 200;
     y =1;
    rect.moveTo(x,y);

    speed = 1;
    if (x>400)
        hdirection = 'r';
    else
        hdirection = 'l';
}

void zigzagMonster::moveDown()
{

        if (rect.left() <=202 )     //set random left/right direction
            hdirection = 'r';
        if (rect.right() > 600 )
            hdirection = 'l';


        if (hdirection == 'r')                  //move in that direction
            rect.moveTo((++x), rect.top());
        if (hdirection == 'l')
            rect.moveTo((--x), rect.top());


        y+=speed;
        rect.moveBottom(y);             //move down 1


}


void zigzagMonster::spitFireballs(int whereFire)
{

    fireballs.push_back(new fireball(x, y+whereFire));         //add fireballs!

    ////fireBallList.push_front(new fireball(x,y+whereFire));

}
/*LinkedList<fireball*>* zigzagMonster::getFireballs()
{
    return &fireBallList;
}
*/
std::vector<fireball*>* zigzagMonster::getFireballs()
{
    return &fireballs;                  //return pointer to fireballs vector
}


