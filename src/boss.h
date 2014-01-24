#ifndef BOSS_H
#define BOSS_H

#include "monster.h"
#include "linkedlist.h"

class Boss: public Monster
{
    public:
        Boss();
        void moveDown();
        int getTimer();
        void spitFireballs(int);
        void setDestroyedBoss();
        void setExplosion();
    private:
        int timerToDeath;       //timer for boss
        char vdirection;    //vertical direction
};

#endif // BOSS_H
