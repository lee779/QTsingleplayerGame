#include <stdlib.h>
#include <QPainter>
#include <QApplication>
#include <QFont>
#include <QImage>
#include <vector>
#include <iostream>
#include "Dodger.h"

using namespace std;


//constructor for Dodger class
Dodger::Dodger(QWidget *parent): QWidget(parent)
{

SCORE = 0;

gameNew = true;
gameStarted = false;
gamePaused = false;
gameOver = false;
gameWon = false;
hitbox = new HitBox(); //create player object hitbox
hitbox->setColorChange(2);
//bullets.pushfront(new Bullet); //create bullet and push it into the vector of class Bullet
bulletList.destroy();


activateShield =false;
hitboxInvincible  = false;
invincibleMode = true; ///MODIFIED THIS
hitboxDestroyed = false;

newScreen =false;

boss = false; //when boss dies level is completed
bossOneDestroyed =false;
bossTwoDestroyed = false;
bossThreeDestroyed = false;
gunAppear =false;
bombAppear = false;
arrowAppear = false;
ammoAppear = true;

getExplosion =false;
getShield = true; //provide a shield just one time during the final part of each level
sTimer =0 ; //shield life timer


score = 0;
scoreOne= 0;
scoreTwo = 0;

bulletTimer = 0;
level = 1; // modified this //////////////////////////
powerUps = 0; //powerUps to kill the boss
destroyBossNumber=0;
ammos = 5;


keepLeft = false;
keepRight = false;
keepDown = false;
keepUp = false;


levelOne= false;
levelTwo = false;
levelThree= true;///CHANGED HERE

}

Dodger::~Dodger()
{delete hitbox;}

void Dodger::paintEvent(QPaintEvent *event)    //makes display
{

/////different colors for the different levels//////
    if (levelOne)
    {
        setColor = "steelblue";
    }

    if(levelTwo)
    {
        setColor = "peru";
    }

    if(levelThree)
    {
        setColor = "lightcoral";
    }
///////////////////////////////////////////////////////////

    QPainter painter(this);
    QColor pencolor(setColor);
    QPen pen;
    pen.setColor(pencolor);
    pen.setWidth(8);
    painter.setPen(pen);




    if (gameOver){                                                //if game over
        QFont font("Arial", 15, QFont::AllUppercase);
        QFontMetrics text(font);
        SCORE = score;//this updates the score to the logIn class

        if (gameWon){                                         //if boss is dead
        int textWidth = text.width("You win!");
        painter.setFont(font);
       // painter.setFont(font);
        int h = height();
        int w = width();

        painter.translate(QPoint (w/2, h/2));
        painter.drawText(-textWidth/2, 0, "You win!");

        }

        else                //if boss is still alive or you died before the boss
        {

            int textWidth = text.width("Game Over. You Lose.");

            font.setPixelSize(10);
            int h = height();
            int w = width();

            painter.translate(QPoint (w/2, h/2));
            painter.drawText(-textWidth/2, 0, "Game Over. You Lose.");
        }
        QString str;
        str.setNum(score);
        painter.drawText(-100, 30, "Final Score: ");                            //prints final score
        painter.drawText(25, 30,  str);
        painter.drawText(-110, 90, "Press 'Space' to Restart");
        painter.drawText(-110,120, "Press 'I' for invincible mode");

    }
    else if(newScreen)
    {

        painter.drawText(300, 300, "DOES THIS WORK?");
    }
    else {                                          //if game still going on, draw sidebar
                   //draw sidebar
        QImage blueHitbox;
        blueHitbox.load("images/hitbox_blue.jpg");
        QPoint blueHitboxPoint(50, 270);

        QImage redHitbox;
        redHitbox.load("images/hitbox_red.jpg");
        QPoint redHitboxPoint(125, 270);

        QImage yellowHitbox;
        yellowHitbox.load("images/hitbox_yellow.jpg");
        QPoint yellowHitboxPoint(50, 300);

        QImage purpleHitbox;
        purpleHitbox.load("images/hitbox_purple.jpg");
        QPoint purpleHitboxPoint(125, 300);





        QRect statusBox(5, 5, 190, 690);
        painter.drawRect(statusBox);

        QFont font("Arial", 15, QFont::AllUppercase);
        setFont(font);
        painter.drawText(25, 40, "How to Play:");
        painter.drawText(25, 70, "1) Collect Points");
        painter.drawText(25, 90, "2) Don't Die");
        painter.drawText(25,110,"3) Defeat the Boss");
        painter.drawText(25,130, "  in each level");

        painter.drawImage(redHitboxPoint, redHitbox);
         painter.drawImage(blueHitboxPoint, blueHitbox);
         painter.drawImage(purpleHitboxPoint, purpleHitbox);
          painter.drawImage(yellowHitboxPoint, yellowHitbox);

        painter.drawLine(5, 150, 192, 150);
        painter.drawText(25, 170, "Controls:");
        painter.drawText(25, 200, "Up, Down, Left");
        painter.drawText(25, 230, "Right Keys");
        painter.drawText(25,260,"R: to shoot");
        painter.drawText(25,290, "F: ");
        painter.drawText(100,290, "D: " );
        painter.drawText(25,320, "S: ");
        painter.drawText(100,320, "A: " );


        painter.drawText(25, 420, "'P' to Pause");
        painter.drawText(25, 450, "'[x] top left to Quit");
        painter.drawText(25,480, "'I' for Invincible");
        QString str;
        str.setNum(ammos);
        painter.drawText(25, 540, "Ammos:");
        painter.drawText(110, 540, str);
        str.setNum(level);
        painter.drawText(25, 570, "Level:");
        painter.drawText(110, 570, str);
        str.setNum(score);
        painter.drawText(25, 600, "Score:");
        painter.drawText(110, 600, str);
        str.setNum(hitbox->getHP());
        painter.drawText(25, 630, "HP Left:");
        painter.drawText(110, 630, str);


        if (boss)
        {
         str.setNum(destroyBossNumber);
         painter.drawText(25,680, "Boss Life: ");
         painter.drawText(130,680, str);
        }
        if(activateShield)
        {
        str.setNum(sTimer);
        painter.drawText(25,660, "Shield life: ");
        painter.drawText(130,660, str);
        }



        if(bossOneDestroyed)
        {
            painter.drawText(235,400,"boss 1 destroyed! move on to level2");
        }

        if(bossTwoDestroyed)
        {
            painter.drawText(235,400,"boss 2 destroyed! move on to level3");
        }




        if (gameNew)
        { //write the instruction here!

            QImage bomb;
            bomb.load("images/bomb.png");
            QPoint bombPoint(210, 155);

            QImage arrow;
            arrow.load("images/followMe.png");
            QPoint arrowPoint(210, 120);

            QImage gun;
            gun.load("images/gun.png");
            QPoint gunPoint(210, 200);

            QImage powerblue;
            powerblue.load("images/powerup_blue.jpg");
            QPoint powerbluepoint(210,250);
            QImage powerred;
            powerred.load("images/powerup_red.jpg");
            QPoint powerredpoint(240,250);
            QImage powerpurple;
            powerpurple.load("images/powerup_purple.jpg");
            QPoint powerpurplepoint(210,280);
            QImage poweryellow;
            poweryellow.load("images/powerup_yellow.jpg");
            QPoint poweryellowpoint(240,280);
            QImage destroyMon;
            destroyMon.load("images/destroyMonster.png");
            QPoint destroyMonPoint(210,320);
            QImage shield;
            shield.load("images/shield.jpg");
            QPoint shieldPoint(210,365);
            QImage point;
            point.load("images/score_up.jpg");
            QPoint pointPoint(210,400);
            QImage health;
            health.load("images/HP_up.jpg");
            QPoint healthPoint(240,400);


            painter.drawImage(arrowPoint, arrow);
            painter.drawImage(bombPoint,bomb);
            painter.drawImage(gunPoint,gun);
            painter.drawImage(gunPoint,gun);
            painter.drawImage(powerbluepoint,powerblue);
            painter.drawImage(powerredpoint,powerred);
            painter.drawImage(powerpurplepoint,powerpurple);
            painter.drawImage(poweryellowpoint,poweryellow);
            painter.drawImage(destroyMonPoint, destroyMon);
            painter.drawImage(shieldPoint,shield);
            painter.drawImage(pointPoint,point);
            painter.drawImage(healthPoint,health);

            painter.drawText(320,20,"Eat and Dodge Game");
            painter.drawText(340,40,"Instructions");
            painter.drawText(210,60,"1. move the up, down, left, right keys to");
            painter.drawText(210, 80,"move the player");
            painter.drawText(210,100,"2. dodge Monsters, fireballs, bombs");


            painter.drawText(230,140,"      will follow you so dodge them");
            painter.drawText(230,190,"      will explode when it reaches bottom");
            painter.drawText(230,230,"      will shoot at you");
            painter.drawText(230,270,"         eat them by changing yourself into");
            painter.drawText(230,290,"         that color to destroy the boss");

            painter.drawText(230,330,"      eating these will stop the creation");
            painter.drawText(230,350,"      of more monsters and fireballs ");

            painter.drawText(230,380,"    gives you protection for a limited time");
            painter.drawText(230,415,"          gives you points/life");

            painter.drawText(210,460,"3. Press 'R' to shoot and destroy monsters");
            painter.drawText(210,480, " be mindful of how many ammos");

            painter.drawText(210, 510,"4. Don't let yourself scroll down off");
            painter.drawText(210,530, "   it results in instant death");

            painter.drawText(210,560, "destroy the 3 bosses and win the game");
            painter.drawText(210, 600,"Press 'space' to start");
            painter.drawText(210, 630,"Press 'I' for invincible mode");


        }


        else
        {
        painter.drawImage(hitbox->getRect(), hitbox->getImage());           //draw user
        for (int i=0; i< bulletList.size(); i++)
            {

                 painter.drawImage(bulletList.at(i)->getRect(), bulletList.at(i)->getImage());       //draw npcs
                 if (bulletList.at(i)->getShotType() == 'B')
                 {
                   vector<fireball*>* projectiles = bulletList.at(i)->getFireballs();            //draw fireballs
                    for (int i = 0; i < (*projectiles).size(); i++)
                    painter.drawImage((*projectiles)[i]->getRect(), (*projectiles)[i]->getImage());
                 }

                 if (bulletList.at(i)->getShotType() == 'G')
                 {
                    vector<fireball*>* projectiles = bulletList.at(i)->getFireballs();            //draw fireballs
                    for (int j = 0; j < (*projectiles).size(); j++)
                        painter.drawImage((*projectiles)[j]->getRect(), (*projectiles)[j]->getImage());
                 }


             }
         }

    }
}//end



void Dodger::addBulletMonster(int changeDroppingSpeed, int changeBulletSpeed)   //changeDroppingSpeed is how often they fall, and changeBulletSpeed is the differerent speeds (only 2)
{

    if (bulletTimer%changeDroppingSpeed == 0){                 //creates new bullet every 100 run-throughs
        int setrole = qrand()%100;

        if (setrole < 70)       //70% chance of Monster
            bulletList.push_front(new Monster());
        if (setrole >= 70 && setrole < 79)  //9% chance of points
        {
            point = new points;
            point->setSpeed(qrand()%changeBulletSpeed +1); // different speeds of them dropping
            bulletList.push_front(point);
        }
        if (setrole>=79 && setrole<80) //1% chance of health
        {
            healthPoints = new health;
            healthPoints->setSpeed(qrand()%changeBulletSpeed +1); // different speeds of them dropping
            bulletList.push_front(healthPoints);
        }
    }

}


void Dodger::level1()
{
    level =1;
    if (bulletTimer%5 == 0){   //constant scrolling down of the hitbox in level 1 (every 5 frame for level1)
        hitbox->moveDown();
    }

  /*  if (score <150) //190 //game progresses depending on score
    {
        addBulletMonster(120, 1); //create monster, health or point every 120 frame and set one speed for the health and points
    }

    if (score > 150 && score < 350) //200-490
    {
        addBulletMonster(200,2); // create monster, health or point every 200 frame and set two speeds

        if (bulletTimer%500 == 0){
            bulletList.push_front(new zigzagMonster);
        }

        if (arrowAppear ==false)  //level 1 part 2 special monster that follows
        {
            arrowAppear= true;
            bulletList.push_front(new arrow());
        }

    }*/

    if(score)
   // if (score >= 350)
    {

        addBulletMonster(200,2);

        if (boss== false)
           { boss = true;                           //creates new boss
             destroyBossNumber = 10; //number of powerups needed to destroy the boss (boss life point)
            bulletList.push_front(new Boss());
            }
        if (bulletTimer%100 == 0) // determines how often fireballs are going to be shot
        {
            if (bulletTimer%300 == 0)         //determines how often fireball are going to be shot
            {
            for (int i=0; i< bulletList.size(); i++)
            {
               if (bulletList.at(i)->getShotType() == 'B') // shoots fireballs
               {bulletList.at(i)->spitFireballs(2);} //shoots two fireball at a time

            }
            }
        }

        if (bulletTimer%500 == 0)  //create powerup to kill the boss
        {
            powerup = new powerUp;
            powerup->setRandomColor(qrand()%2 + 1);
            bulletList.push_front(powerup);
        }


        if (getShield) //create one shield during boss stage and you only have one HP
        {
        if (hitbox->getHP() == 1)
        {
            Shield = new shield();
            bulletList.push_front(Shield);
            getShield = false;
        }}
    }

}

void Dodger::level2()
{
   // std::cout<<scoreOne<<endl;
    level =2;


    if (bulletTimer%4 == 0){   //constant scrolling down of the hitbox in level 1 (every 4 frame for level2)
        hitbox->moveDown();
    }

    if (scoreOne <150) //190 //game progresses depending on score
    {
        addBulletMonster(120, 2); //create monster, health or point every 120 frame and set one speed for the health and points
        if (bulletTimer%450 == 0){
            bulletList.push_front(new zigzagMonster);

        }
        if (arrowAppear ==false)  //level 1 part 2 special monster that follows
        {
            arrowAppear= true;
            bulletList.push_front(new arrow());
        }

    }

    if (scoreOne > 150 ) //200-490
    {
        if(!getExplosion)
        {
        addBulletMonster(150,2); // create monster, health or point every 200 frame and set two speeds
        }
        if (gunAppear ==false)
        {
            gunAppear= true;
            bulletList.push_front(new gun(hitbox->getx()));
        }
        if (bulletTimer%500 == 0)                   //gun shoots fireballs every 500 frames
        {

            for (int i = 0; i <bulletList.size(); i++)
            {
                if (bulletList.at(i)->getShotType() == 'G') // shoots fireballs
                {
                    int setrole = qrand()%100;
                    if (setrole < 70)       //70% chance of Monster
                    {
                    if(!getExplosion){
                    bulletList.at(i)->spitFireballs(40);} }//how often fireballs are fired}
                }
            }

         }

    }

    if (scoreOne >= 350)
    {

        //addBulletMonster(200,2);

        if (boss== false)
           { boss = true;                           //creates new boss
             destroyBossNumber = 15; //number of powerups needed to destroy the boss (boss life point)
            bulletList.push_front(new Boss());
            }
        if (bulletTimer%200 == 0) // determines how often fireballs are going to be shot
        {
            if (bulletTimer%300 == 0)         //determines how often fireball are going to be shot
            {
            for (int i=0; i< bulletList.size(); i++)
            {
               if (bulletList.at(i)->getShotType() == 'B') // shoots fireballs
                   if(!getExplosion){
               {bulletList.at(i)->spitFireballs(3);}} //shoots two fireball at a time

            }
            }
        }

        if (bulletTimer%500 == 0)  //create powerup to kill the boss
        {
            powerup = new powerUp;
            powerup->setRandomColor(qrand()%3 + 1);
            bulletList.push_front(powerup);
        }



        if(bulletTimer%1000 == 0){

            {
            explode =new explosion();
            bulletList.push_front(explode);
            getExplosion = false;
            }
        }

        if (getShield) //create one shield during boss stage and you only have one HP
        {
        if (hitbox->getHP() == 1)
        {
            Shield = new shield();
            bulletList.push_front(Shield);
            getShield = false;
        }}
    }


} //end of level 2

void Dodger::level3(){

    level =3;


    if (bulletTimer%3 == 0){   //constant scrolling down of the hitbox in level 1 (every 3 frame for level3)
        hitbox->moveDown();
    }

    if (scoreTwo <70) //190 //game progresses depending on score
    {
        addBulletMonster(120, 2); //create monster, health or point every 120 frame and set one speed for the health and points
        if (bulletTimer%450 == 0){
            bulletList.push_front(new zigzagMonster);

        }
        if (gunAppear ==false)  //level 1 part 2 special monster that follows
        {
            gunAppear= true;
            bulletList.push_front(new gun(hitbox->getx()));
        }
        if (bulletTimer%500 == 0)                   //gun shoots fireballs every 500 frames
        {

            for (int i = 0; i <bulletList.size(); i++)
            {
                if (bulletList.at(i)->getShotType() == 'G') // shoots fireballs
                {
                    int setrole = qrand()%100;
                    if (setrole < 80)       //70% chance of Monster
                    {
                    bulletList.at(i)->spitFireballs(40);} //how often fireballs are fired}
                }
            }

         }

    }

    if (scoreTwo > 70 && scoreTwo<200) //200-490
    {

        addBulletMonster(150,2); // create monster, health or point every 200 frame and set two speeds
        if (bombAppear == false)
        {
            hitboxDestroyed = false;
            bombAppear =true;
            bulletList.push_front(new Bomb(hitbox->getx()));
        }



    }

    if (scoreTwo >= 200)
    {

        //addBulletMonster(200,2);

        if (boss== false)
           { boss = true;                           //creates new boss
             destroyBossNumber = 20; //number of powerups needed to destroy the boss (boss life point)
            bulletList.push_front(new Boss());
            }
        if (bulletTimer%200 == 0) // determines how often fireballs are going to be shot
        {
            if (bulletTimer%300 == 0)         //determines how often fireball are going to be shot
            {
            for (int i=0; i< bulletList.size(); i++)
            {
               if (bulletList.at(i)->getShotType() == 'B') // shoots fireballs
                   if(!getExplosion){
               {bulletList.at(i)->spitFireballs(3);}} //shoots two fireball at a time

            }
            }
        }

        if (bulletTimer%500 == 0)  //create powerup to kill the boss
        {
            powerup = new powerUp;
            powerup->setRandomColor(qrand()%4 + 1);
            bulletList.push_front(powerup);
        }






        if (getShield) //create one shield during boss stage and you only have one HP
        {
        if (hitbox->getHP() == 1)
        {
            Shield = new shield();
            bulletList.push_front(Shield);
            getShield = false;
        }}
    }





}

void Dodger::timerEvent(QTimerEvent *event){        //for 1 loop of the game

    bulletTimer++;
    if (levelOne)
    {
    level1();
    for(int i=0; i <bulletList.size(); i++)
    {
        if (bulletList.at(i)->getShotType() == 'B')       //moves boss and his bullets -checks if he's still alive
        {
            if (destroyBossNumber!=0) //destroyBossNumber is going to decrease and when it equals to zero(boss life point) boss is destroyed
            {
                if (bulletTimer%5  == 0)
                {
                bulletList.at(i)->moveDown();  //move the boss
                }

                if (bulletTimer%2 == 0)
                {
                vector<fireball*>* projectiles = bulletList.at(i)->getFireballs();

                for (int j = 0; j < projectiles->size(); j++)
                (*projectiles)[j]->moveDown();
                }
            }
            else                //if you get enough powerUps boss dies// boss's energy timer runs out, you win!
            {
                boss = false;
                bossOneDestroyed = true;
                counter =200;
                //gameWon = true;
            }
        }

        else if (bulletList.at(i)->getShotType()=='A')
        {
            if(bulletTimer%3 ==0) //how fast the arrow is going to move
            {
                bulletList.at(i)->move((bulletList.at(i)->trackDirX((hitbox->getRect()).x())),(bulletList.at(i)->trackDirY((hitbox->getRect()).y())));
            }
        }


        else
        bulletList.at(i)->moveDown();            //moves all other npcs ("automove")

    }
    }//end of level two

    if(levelTwo)
    {
        level2();
        for(int i=0; i <bulletList.size(); i++)
        {
            if (bulletList.at(i)->getShotType() == 'B')       //moves boss and his bullets -checks if he's still alive
            {
                if (destroyBossNumber!=0) //destroyBossNumber is going to decrease and when it equals to zero(boss life point) boss is destroyed
                {
                    if (bulletTimer%4  == 0)
                    {
                    bulletList.at(i)->moveDown();  //move the boss
                    }

                    if (bulletTimer%2 == 0)
                    {
                    vector<fireball*>* projectiles = bulletList.at(i)->getFireballs();

                    for (int j = 0; j < projectiles->size(); j++)
                    (*projectiles)[j]->moveDown();
                    }
                }
                else                //if you get enough powerUps boss dies// boss's energy timer runs out, you win!
                {
                    boss = false;
                    bossTwoDestroyed = true;
                    counter =200;
                    //gameWon = true;
                }
            }

            else if (bulletList.at(i)->getShotType()=='A')
            {
                if(bulletTimer%3 ==0) //how fast the arrow is going to move
                {
                    bulletList.at(i)->move((bulletList.at(i)->trackDirX((hitbox->getRect()).x())),(bulletList.at(i)->trackDirY((hitbox->getRect()).y())));
                }
            }

            else if (bulletList.at(i)->getShotType()== 'G')
            {
                if (keepLeft)
                    bulletList.at(i)->moveLeft();
                if (keepRight)
                    bulletList.at(i)->moveRight();

                if (bulletTimer%5 == 0)
                {
                        vector<fireball*>* projectiles = bulletList.at(i)->getFireballs();//
                        for (int i = 0; i< projectiles ->size(); i++)
                        (*projectiles)[i]->move((*projectiles)[i]->trackDirX((hitbox->getRect()).x()),2);
                }

            }



            else
            bulletList.at(i)->moveDown();            //moves all other npcs ("automove")

    }}

    if(levelThree)
    {
        level3();

        for(int i=0; i <bulletList.size(); i++)
        {
            if (bulletList.at(i)->getShotType() == 'B')       //moves boss and his bullets -checks if he's still alive
            {
                if (destroyBossNumber!=0) //destroyBossNumber is going to decrease and when it equals to zero(boss life point) boss is destroyed
                {
                    if (bulletTimer%4  == 0)
                    {
                    bulletList.at(i)->moveDown();  //move the boss
                    }

                    if (bulletTimer%2 == 0)
                    {
                    vector<fireball*>* projectiles = bulletList.at(i)->getFireballs();

                    for (int j = 0; j < projectiles->size(); j++)
                    (*projectiles)[j]->moveDown();
                    }
                }
                else                //if you get enough powerUps boss dies// boss's energy timer runs out, you win!
                {
                    boss = false;
                    bossThreeDestroyed = true;
                    counter =200;
                    gameWon = true;
                }
            }

            else if (bulletList.at(i)->getShotType()== 'G')
            {
                if (keepLeft)
                    bulletList.at(i)->moveLeft();
                if (keepRight)
                    bulletList.at(i)->moveRight();

                if (bulletTimer%5 == 0)
                {
                        vector<fireball*>* projectiles = bulletList.at(i)->getFireballs();//
                        for (int i = 0; i< projectiles ->size(); i++)
                        (*projectiles)[i]->move((*projectiles)[i]->trackDirX((hitbox->getRect()).x()),2);
                }

            }
            else if (bulletList.at(i)->getShotType()=='@')
            {

                if(bulletTimer%3 == 0)
                    bulletList.at(i)->move(bulletList.at(i)->trackDirX((hitbox->getRect()).x()),3);

            }



            else
            bulletList.at(i)->moveDown();            //moves all other npcs ("automove")





    }
      }




    if (ammoAppear ==false)  //level 1 part 2 special monster that follows
    {
        ammoAppear= true;
        bulletList.push_front(new shooter((hitbox->getx()),(hitbox->gety())));//hitbox->getRect().top()));
    }

      if (sTimer != 0) //Shield got activated
      {
          hitboxInvincible = true; //set hitbox to be invincinble (collisions don't affect hitbox)
          sTimer= sTimer-1;
          cout<<sTimer<<endl;
      }
      else
      {
         hitboxInvincible =false;
         activateShield =false;
      }



    if (keepLeft)
        hitbox->moveLeft();

    if (keepRight)
        hitbox->moveRight();

    if (keepUp)
        hitbox->moveUp();

    if (keepDown)
        hitbox->moveDown();


    if (!hitboxInvincible)
       hitbox->setColorChange(changeColor);
    else
       hitbox->setShield(changeColor);


    checkCollisionBullets();


    if ((hitbox->getHP())== 0 || (!boss && gameWon))          //if you lost all HP, game ends or if boss is dead and game is won
        endGame();
    if (bulletTimer% 20 == 0)          //point increment timer
    {score++; scoreOne++; scoreTwo++;}

    repaint();
}

//aids in making smoother movements
void Dodger::keyReleaseEvent(QKeyEvent *event){

    if(!event->isAutoRepeat())
    {
    switch(event->key()){
    case Qt::Key_Left:
    {
        keepLeft = false;
        break;
    }
    case Qt::Key_Right:
    {
       keepRight = false;
       break;
    }
    case Qt::Key_Up:
    {
        keepUp = false;
        break;
    }
    case Qt::Key_Down:
    {
        keepDown = false;
        break;
    }
    }
    }
}

//basic movement and game-functions
void Dodger::keyPressEvent(QKeyEvent *event){

    if (!gamePaused){
        switch(event->key()){
        case Qt::Key_Left:
        {
            keepLeft = true;
            break;
        }
        case Qt::Key_Right:
        {
           keepRight = true;
            break;
        }
        case Qt::Key_Up:
        {
            keepUp = true;
            break;
        }
        case Qt::Key_Down:
        {
            keepDown = true;
            break;
             }
        case Qt::Key_F:
        {
            changeColor =1;
            break;
        }
        case Qt::Key_D:
        {
            if (levelOne || levelTwo || levelThree)
                changeColor = 2;
            break;
        }
        case Qt::Key_S:
        {
            if (levelTwo || levelThree)
                changeColor =3;
            break;
        }
        case Qt::Key_A:
        {
            if (levelThree)
                 changeColor = 4;
            break;
        }
        case Qt::Key_R:
        {
            if(ammos !=0)
            {ammoAppear = false;
            ammos--;}
        }
            break;
        case Qt::Key_0:
        {
            newScreen = true;
        }
            break;
       case Qt::Key_Space:
       {startGame();
           gameNew= false;
       }
       break;
       case Qt::Key_I:
        {
            invincibleMode =true;
            startGame();
            gameNew = false;

        }
            break;
       case Qt::Key_P:
       {pauseToggle();
       }
           break;

       break;
      default:
           QWidget::keyPressEvent(event);
    }
   }
    else                //prevents user from "teleporting" while game paused
    {
        switch(event->key())
        {
        case Qt::Key_P:
        {pauseToggle();
        }
            break;

        break;
        default:
            QWidget::keyPressEvent(event);
        }
    }
}

void Dodger::startGame(){
    if (!gameStarted){
        if (gameOver)       //if the game reset, reset the game properties
        {

            //invincibleMode = false;
            ammos = 5;
            level =1;
            levelOne = true;
            levelTwo = false;
            levelThree =false;
            getShield =true;
            hitboxInvincible = false;
            changeColor =1;
            score = 0;
            sTimer = 0;
            activateShield =false;
             hitbox->reset();                           //reset hitbox hp and position

             bulletList.destroy();
        //for (int i = 0; i < bulletList.size(); i++)        //clear out vector of npcs
          /*  delete bullets[i];
        bullets.clear();
        bullets.push_front(new Bullet);*/
        }

        gameOver = false;   //reset game status
        gameWon = false;
        gameStarted = true;
        boss = false;
        gunAppear =false;
        timerId=startTimer(5);   //start looping
    }
}

void Dodger::pauseToggle(){
    if (gamePaused){                    //unpauses game
        timerId = startTimer(5);
        gamePaused = false;
    }
        else{                       //pauses game
     gamePaused = true;
    killTimer(timerId);
    }
    }

void Dodger::endGame(){
    killTimer(timerId);         //ends loop
    gameOver = true;
    gameStarted = false;
    gameNew = true;
    getShield =false;
    levelOne =true;
    levelTwo = false;
    levelThree= false;
    activateShield =false;
     invincibleMode = false;
    sTimer = 0;

}

bool Dodger::checkCollisionBullets(){
    for (int i = 0; i <bulletList.size(); i++)         //checks if hitbox and bullets collide
        {
        if ((hitbox->getRect()).intersects(bulletList.at(i)->getRect()))
            {
            if ((bulletList.at(i)->getShotType()) == 'V' || (bulletList.at(i)->getShotType()) == 'Z' || (bulletList.at(i)->getShotType())=='A')     //lose 1 HP if collides with normal Monsters
            {if (!hitboxInvincible && (!invincibleMode))
                hitbox->setHP((hitbox->getHP())-1);}
            else
                if ((bulletList.at(i)->getShotType()) == '+')     //gain 1 HP
                    hitbox->setHP((hitbox->getHP())+1);
                else
                    if ((bulletList.at(i)->getShotType())=='E' && (!hitboxDestroyed) )
                    {if (!hitboxInvincible && (!invincibleMode))
                        hitbox->setHP((hitbox->getHP())-1); hitboxDestroyed =true;}

                    else
                    if ((bulletList.at(i)->getShotType())=='!')
                        getExplosion = true;
                    else
                    if ((bulletList.at(i)->getShotType()) == '*' && (bulletList.at(i)->getColor()== hitbox->getColor()))
                    { score += 50;destroyBossNumber--;}
                    else
                        if ((bulletList.at(i)->getShotType())== 'S')
                        { activateShield = true;sTimer = 1000 ; }
                        else
                            if ((bulletList.at(i)->getShotType()) == 'P')     //gains 50 points
                                score+=50;
                            else
                                if  ((bulletList.at(i))->getShotType() == 'B')//|| (!invincibleMode))                    //auto-lose if collides with boss
                                {

                                    {if (!hitboxInvincible && (!invincibleMode))
                                            gameOver = true;
                                           gameWon = false;
                                           }break;

                            }

            if(bulletList.at(i)->getShotType() != '@' && bulletList.at(i)->getShotType()!='E' && bulletList.at(i)->getShotType()!='>')
            {
                    bulletList.erase(i);
                    std::cout<<"hit!"<<std::endl;}
                    return true;
               }
        if (bulletList.at(i)->getShotType() == 'B' || bulletList.at(i)->getShotType()=='G')                //check boss-type's vector of fireball for collisions
        {
            vector<fireball*>* shotsfired = bulletList.at(i)->getFireballs();
            for (int i = 0; i < shotsfired->size(); i++)
            {
                if (hitbox->getRect().intersects((*shotsfired)[i]->getRect()))      //if user collides with fireball
                {
                    if(!hitboxInvincible && (!invincibleMode))
                        hitbox->setHP((hitbox->getHP())-1);                         //decrease HP

                    delete (*shotsfired)[i];                                        //delete fireball
                    (*shotsfired)[i] = (*shotsfired)[shotsfired->size()-1];
                    (*shotsfired).pop_back();

                    std::cout<<"bulletshot hit!"<<std::endl;
                    return true;
                }




                if(((*shotsfired)[i]->getRect().top()) > 700)    //if fireball at bottom of screen, delete it
                {
                delete (*shotsfired)[i];
                (*shotsfired)[i] = (*shotsfired)[shotsfired->size()-1];
                  (*shotsfired).pop_back();
                }
            }

        }




        for (int j =0 ; j<bulletList.size(); j++)
         {
            if( bulletList.at(i)->getShotType()=='>' && bulletList.at(j)->getShotType()!='>')
             {
                 if (bulletList.at(i)->getRect().intersects(bulletList.at(j)->getRect()))
                 {
                     if(bulletList.at(j)->getShotType()=='A')
                     {
                         arrowAppear =false; //appears again
                     }
                     if(bulletList.at(j)->getShotType()!='B'&&bulletList.at(j)->getShotType()!='G')
                        bulletList.erase(j);

                     return true;
                 }
             }

         }


    } //end of check with hitbox and bullet objects collide


    for(int i = 0; i <bulletList.size(); i++)
    {

        if((bulletList.at(i)->getRect().bottom()) == 700)    //if bullet at bottom of screen, delete it
         {
            if(bulletList.at(i)->getShotType()=='@')
                    bulletList.at(i)->setExplosion();
        }
       if((bulletList.at(i)->getRect().top()) > 700)    //if bullet at bottom of screen, delete it
        {
                bulletList.erase(i);
        }
    }

   /* for(int i = 0; i <bulletList.size(); i++)
    {
        if (bulletList.at(i)->getShotType()=='>')
            if((bulletList.at(i)->getRect().bottom())<0)
                bulletList.erase(i);
    }*/



    for (int i =0; i<bulletList.size();i++)
    {

       if(bulletList.at(i)->getShotType()=='E' && bulletList.at(i)->getTimer() == 0)
       {
           bombAppear = false;
           bulletList.erase(i);
       }

    }

    for (int j = 0;j<bulletList.size(); j++)
{

       if(bulletList.at(j)->getShotType()=='B')
        {
           if(bossOneDestroyed)
           {
            boss =false;
            levelOne =false;
             if(counter!=0)
             {
             bulletList.at(j)->setExplosion();
             counter --;
             }
             else
             {
                 bulletList.destroy(); //erase everything
                 if (bulletList.empty())
                 {
                     std::cout<<"I'm empty!"<<endl;
                 }
                 levelTwo =true;
                  scoreOne= 0;
                  ammos = 8; //for level 2
                  bossOneDestroyed =false;
             }
           }
           if(bossTwoDestroyed)
           {
               boss =false;
               levelTwo =false;
                if(counter!=0)
                {
                bulletList.at(j)->setExplosion();
                counter --;
                }
                else
                {
                    bulletList.destroy(); //erase everything
                    levelThree =true;
                     scoreTwo= 0;
                     ammos = 10;
                     bossTwoDestroyed =false;
                }
           }

         }



        }



    if (hitbox->getRect().bottom()>700)   // if hitbox goes out of screen, gameOver
     {
        if (invincibleMode)  //if invincible, doesn't go off the screen and die.
             hitbox->moveUp();
        else
        {
       gameOver =true;
        endGame();}
        }
    return false;
}


// end of collide
