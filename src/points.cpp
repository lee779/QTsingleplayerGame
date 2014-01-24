#include "points.h"

points::points()
{

      image.load("images/score_up.jpg");
      shotType = 'P';
      rect = image.rect();
      x = rand()%370 + 200;
      y = 1;
      speed =1;//speed of bullet
      rect.moveTo(x, y);
}
