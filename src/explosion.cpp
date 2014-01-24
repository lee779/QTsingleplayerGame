#include "explosion.h"

explosion::explosion()
{

      image.load("images/destroyMonster.png");
      shotType = '!';
      rect = image.rect();
      x = rand()%370 + 200;
      y = 1;
      speed =1; //speed of bullet
      rect.moveTo(x, y);
}


