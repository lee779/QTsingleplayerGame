#ifndef GUN_H
#define GUN_H
#include "bullet.h"
#include <vector>
#include "fireball.h"
#include "linkedlist.h"

class gun : public Bullet
{
protected:
   std::vector <fireball*> fireballs; //projectiles for the monsters!
   // LinkedList <fireball*> fireBallList;
public:
    gun(int);      //default monster
    void spitFireballs(int);               //add fireball to vector
    void moveLeft();
    void moveRight();
    void moveDown();
   // LinkedList <fireball*>* getFireballs();
    std::vector<fireball*>* getFireballs();     //return pointer to vector
};

#endif // GUN_H
