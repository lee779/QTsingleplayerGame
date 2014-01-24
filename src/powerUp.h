#ifndef POWERUP_H
#define POWERUP_H
#include "bullet.h"
#include <QImage>
#include <QRect>

class powerUp : public Bullet
{

public:
    powerUp();
    void moveDown();
    void setRandomColor(int);

};
#endif // POWERUP_H
