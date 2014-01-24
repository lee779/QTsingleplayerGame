#ifndef HITBOX_H
#define HITBOX_H

#include <QImage>
#include <QRect>

class HitBox
{
//Data Members
private:
    int HP;
    int x, y, color, shieldTimer;
       QImage image;            //user image
        QRect rect;             //collision box
//constructors
public:
    HitBox();
    ~HitBox();
//commands
public:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void reset();           //reset position and HP


//getters and setters
    int getHP();
    void setHP(int);
    int getx();
    int gety();
    int getColor();
    int getShieldTimer();
    QRect getRect();
    QImage& getImage();
    void setx(int);
    void sety(int);
    void setColorChange(int);
    void setShield(int);


};

#endif
