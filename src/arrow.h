#ifndef ARROW_H
#define ARROW_H
#include "bullet.h"

class arrow : public Bullet
{
public:
    arrow();
     void move(int, int);
     int trackDirX(int);
     int trackDirY(int);

};

#endif // ARROW_H
