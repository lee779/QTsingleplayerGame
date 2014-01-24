#include "fireball.h"

fireball::fireball(int xpos, int ypos)
{
    image.load("images/fireball.jpg");
    rect = image.rect();
    x = xpos;
    y = ypos;
    rect.moveTo(x, y);
    speed = 1;
    shotType= 'f';
}

void fireball::move(int newx, int newy)
{

      rect.translate(newx, newy);

}

void fireball::moveDown()
{
    y+= speed;
    rect.moveTo(x, y);
}

int fireball::trackDirX(int x)	//returns whether the item is to the left of right of the x point
{				//(1 and -1) respectively
    if(rect.x()<x) return 1;
    else if (rect.x()>x) return -1;
    else return 0;
}


