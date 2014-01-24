#ifndef DODGER_H
#define DODGER_H

#include "user.h"
#include "hitbox.h"
#include "boss.h"
#include "monster.h"
#include "zigzagmonster.h"
#include "powerUp.h"
#include "bomb.h"
#include "arrow.h"
#include "shield.h"
#include "explosion.h"
#include "gun.h"
#include "points.h"
#include "health.h"
#include "linkedlist.h"
#include "shooter.h"
#include <vector>
#include <QWidget>
#include <QKeyEvent>
#include <QString>
#include <QPushButton>

class Dodger: public QWidget
{
    Q_OBJECT

public:
    Dodger(QWidget *parent = 0);
    ~Dodger();
    int SCORE; //updating score variable
protected:
    void paintEvent(QPaintEvent *event);        //paints scene
    void timerEvent(QTimerEvent *event);        //loops game
    void keyReleaseEvent(QKeyEvent *);          //helps for smoother movement
    void keyPressEvent(QKeyEvent *event);       //to determine movement

    void level1();  //function to implement level1 objects
    void level2();
    void level3();
    void addBulletMonster(int,int);   //function to add the simple monsters, points and health whcih is used in all the levels
    void addUserButtonSlot();
    void startGame();                           //resets game and starts it
    void pauseToggle();                         //pauses timer
    void endGame();                             //sets game status
    bool checkCollisionBullets();               //check collisions between objects
private:
    HitBox* hitbox;                             //player
   std::vector<Bullet*> bullets;               //npc objects
    LinkedList<Bullet*> bulletList;
    std::vector<fireball*> fireballs;
    gun* shootGun;
    points* point;
    health* healthPoints;
    Bullet* bullet;
    powerUp* powerup;
    shield* Shield;
    explosion* explode;
    Bomb* bomb;
    shooter* shoot;

    QString setColor;

    bool Random;

    //QColor stuff;
    int counter; //helps with counting how long the destoryedBoss picture is on for
    int timerId;                            //timer for the frames
    int bulletTimer, sTimer;                //bulletTimer is the main timer for the implementation, stimer is the shield timer

    int score, scoreOne, scoreTwo ; //score= main score
    int level, powerUps, changeColor, destroyBossNumber, ammos;  //different numbers specific for each level
    bool gameOver, gameWon, gameStarted, gamePaused, gameNew;
    bool invincibleMode, hitboxInvincible, activateShield, getShield, getExplosion; //logic for invincible mode, shield mode and setting explosions
    bool boss, bossOneDestroyed, bossTwoDestroyed,bossThreeDestroyed, hitboxDestroyed; //logic for destroying bosses for each level and hitbox getting hit
    bool gunAppear, bombAppear, arrowAppear,ammoAppear; //logic to add these objects are inserted
    bool keepLeft, keepRight, keepDown, keepUp;
    bool levelOne, levelTwo, levelThree;

    bool newScreen;

};

#endif
