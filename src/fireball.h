#ifndef FIREBALL_H
#define FIREBALL_H

#include<QImage>
#include<QRect>
#include<bullet.h>


class fireball: public Bullet
{
    public:
        fireball(int xpos, int ypos);       //new fireball at xpos, ypos
        void moveDown();                //moves fireball downw 1
        void move(int, int);                //moves fireball to specific place - not implemented
        int trackDirX(int);

};

#endif // FIREBALL_H
