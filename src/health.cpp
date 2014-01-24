#include "health.h"

health::health()
{
      image.load("images/HP_up.jpg");
      shotType = '+';
      rect = image.rect();
      x = rand()%370 + 200;
      y = 1;
      speed =1; //speed of bullet
      rect.moveTo(x, y);
}
