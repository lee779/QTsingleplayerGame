#include "shooter.h"

shooter::shooter(int xpos, int ypos)
{
    shotType = '>';
    image.load("images/bullet.png");
    x = xpos;
    y = ypos;
    rect = image.rect();
    rect.moveTo(x,y);
    speed =1;

}
void shooter::moveDown()
{
    y= y- speed;
    rect.moveTo(x, y);
}




