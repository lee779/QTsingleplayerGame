#ifndef BOMB_H
#define BOMB_H

#include <vector>
#include "bullet.h"

class Bomb : public Bullet
{
public:
    Bomb(int);
    void moveDown();
    void move(int, int);
    void setExplosion();
    int getTimer();
    int trackDirX(int);

protected:
    int  timerExplosion;
    bool dontMove;

};

#endif // BOMB_H
