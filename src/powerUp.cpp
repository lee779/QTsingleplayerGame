
#include <stdlib.h>
#include <iostream>
#include <QTime>
#include "powerUp.h"

powerUp::powerUp()
{
    image.load("images/powerup_blue.jpg");
    rect = image.rect();
    x = rand()%370 + 200;
    y = 1;
    rect.moveTo(x, y);
    speed = 1;
    shotType= '*';
}

void powerUp::moveDown()
{
    y+=speed;
    rect.moveBottom(y);
}

void powerUp::setRandomColor(int selectColor)
{
    color = selectColor;
    if(selectColor ==1)
        image.load("images/powerup_blue.jpg");
    if(selectColor ==2)
        image.load("images/powerup_red.jpg");
    if(selectColor ==3)
        image.load("images/powerup_yellow.jpg");
    if(selectColor ==4)
        image.load("images/powerup_purple.jpg");
}

