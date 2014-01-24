#ifndef SHOOTER_H
#define SHOOTER_H
#include "bullet.h"

class shooter : public Bullet
{
public:
    shooter(int, int);
    void moveDown();

};

#endif // SHOOTER_H
