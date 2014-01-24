#ifndef MONSTER_H
#define MONSTER_H

#include "bullet.h"
#include <vector>
#include "fireball.h"
//#include "linkedlist.h"

class Monster: public Bullet            //Subclass of Bullet
{
    protected:
        char hdirection;     //horizontal direction that monster is moving in
       //  LinkedList<fireball*> fireBallList;
       std::vector <fireball*> fireballs; //projectiles for the monsters!
    public:
        Monster();      //default monster
        void moveDown();
        void spitFireballs(int);               //add fireball to vector
       //LinkedList<fireball*>* getFireballs();
         std::vector<fireball*>* getFireballs();     //return pointer to vector

};

#endif // MONSTER_H
