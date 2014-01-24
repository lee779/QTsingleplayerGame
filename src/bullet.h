#ifndef BULLET_H
#define BULLET_H
#include <QImage>
#include <QRect>




class fireball; //temporary link to subclass

class Bullet
{
    public:
        Bullet();
        //Bullet(char);
        ~Bullet();

    protected:
        QRect rect;
        QImage image;

    char shotType;          //type of npc
    int x, y, speed, color;        //position and speed

    public:
   QImage& getImage();          //returns bullet image
   QRect getRect();             //returns QRect for object

   virtual void setRandomColor(int);
   virtual void moveDown(); //moves bullet down 1 space
   virtual void moveLeft();
   virtual void moveRight();

   //virtual LinkedList<fireball*>* getFireballs();
   virtual std::vector<fireball*>* getFireballs();      //pointer to a vector of pointers to fireballs - virtual
   virtual int getTimer();
    virtual void spitFireballs(int);                       //adds another fireball to the vector - virtual
   virtual int trackDirX(int);
   virtual int trackDirY(int);
   virtual void move(int,int);
    int getx();                 //return x position
    int gety();             //returns y position
    int getColor();
    void setx(int);         //set xposition of bullet
    void sety(int);         //set yposition of bullet
    void setSpeed(int);
    virtual void setExplosion();
    char getShotType();     //return shot type
};

#endif
