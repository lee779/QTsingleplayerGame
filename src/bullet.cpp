
#include <stdlib.h>
#include <iostream>
#include "bullet.h"
#include <QTime>
#include "linkedlist.h"

Bullet::Bullet()
    {


    }



Bullet::~Bullet()
{//std::cout<<"Bullet Deleted"<<std::endl;
}

char Bullet::getShotType()
{return shotType;}
QImage& Bullet::getImage(){
    return image;
}

QRect Bullet::getRect(){
    return rect;
}

void Bullet::moveDown()  //moves bullet 1 space if bullet is turned on
{
    y+=speed;
    rect.moveBottom(y);
}

void Bullet::moveLeft()
{}
void Bullet::moveRight()
{}

//LinkedList <fireball*>* Bullet::getFireballs()
//{}

std::vector<fireball*>* Bullet::getFireballs()
{}

void Bullet::setExplosion()
{}

void Bullet::spitFireballs(int)
{}

int Bullet::getTimer()
{}

int Bullet::trackDirX(int)
{}

int Bullet::trackDirY(int)
{}

void Bullet::move(int,int)
{}

int Bullet::getx(){
return x;
}

int Bullet::gety(){
return y;
}

int Bullet::getColor(){
    return color;
}

void Bullet::setx(int newx){
x = newx;
}

void Bullet::sety(int newy){
y = newy;
}

void Bullet::setSpeed(int newspeed){
    speed = newspeed;
}

void Bullet::setRandomColor(int colorSelect)
{
    color = colorSelect;
}
