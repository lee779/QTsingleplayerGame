#ifndef ZIGZAGMONSTER_H
#define ZIGZAGMONSTER_H
#include "bullet.h"
#include <vector>
#include "fireball.h"
//#include "linkedlist.h"

class zigzagMonster : public Bullet
{
protected:
    char hdirection;
    //LinkedList <fireball*> fireBallList;
    std::vector<fireball*> fireballs;
public:
    zigzagMonster();
    void moveDown();
    void spitFireballs(int);
    //LinkedList<fireball*>* getFireballs();
    std::vector<fireball*>* getFireballs();
};

#endif // ZIGZAGMONSTER_H
