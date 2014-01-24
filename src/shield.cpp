#include "shield.h"

shield::shield()
{
    image.load("images/shield.jpg");
    rect = image.rect();
    shotType = 'S';
    x = rand()%370 + 200;
    y = 1;
    speed =1;
    rect.moveTo(x, y);
}
