#include "hitbox.h"
#include <iostream>


HitBox::HitBox() //constructors and deconstructors
    {
    x = 350;
    y = 600;
    image.load("images/hitbox_blue.jpg");
    rect = image.rect();
    rect.moveTo(x, y);
    HP = 3;
    color = 1;

}

HitBox::~HitBox()
{
    std::cout <<"hitbox deleted"<<std::endl;
}

//move character 1 space
    void HitBox::reset(){
        HP = 3;
        x = 350;
        y = 600;
        rect.moveTo(x, y);
         }

    void HitBox::moveLeft(){
        if (rect.left() >=202 )
            rect.moveTo((--x), rect.top());
        }
    void HitBox::moveRight(){
        if (rect.right() <=600 )
             rect.moveTo((++x), rect.top());
        }
    void HitBox::moveUp(){
        if (rect.top() >=2 )
            rect.moveTo(rect.left(), (--y));
        }
    void HitBox::moveDown(){
        //if (rect.bottom() <= 700 )
            rect.moveTo(rect.left(), (++y));
        }

//getters
    int HitBox::getHP()
    { return HP;}
    int HitBox::getx()
    { return x;}
    int HitBox::gety()
    { return y;}
    int HitBox::getColor()
    { return color;}
    int HitBox::getShieldTimer()
    {return shieldTimer;}
    QRect HitBox::getRect()
    {return rect;}
    QImage& HitBox::getImage()
    {return image;}



//setters
    void HitBox::setHP(int h)
    { HP = h;}
    void HitBox::setx(int newx)
    {x = newx;}
    void HitBox::sety(int newy)
    {y = newy;}
    void HitBox::setColorChange(int colorChange)
    {
        color = colorChange;
        if(colorChange ==1)
            image.load("images/hitbox_blue.jpg");
        if(colorChange ==2)
            image.load("images/hitbox_red.jpg");
        if(colorChange ==3)
            image.load("images/hitbox_yellow.jpg");
        if(colorChange ==4)
            image.load("images/hitbox_purple.jpg");

    }
    void HitBox::setShield(int shieldChange)
    {
        color = shieldChange;
        if(shieldChange ==1)
            image.load("images/shield_blue.jpg");
        if(shieldChange ==2)
            image.load("images/shield_red.jpg");
        if(shieldChange ==3)
            image.load("images/shield_yellow.jpg");
        if(shieldChange ==4)
            image.load("images/shield_purple.jpg");

    }


