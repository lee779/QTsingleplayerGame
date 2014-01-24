#include <stdlib.h>
#include <QPainter>
#include <QApplication>
#include <QFont>
#include <QImage>
#include <vector>
#include <iostream>
#include "login.h"
#include <QtGui>
#include <sstream>

 #include <QSound>
using namespace std;

LogIn::LogIn()
{

mainMenuScreen = true;
userIndex = 0;
numberUsers = 0;
loggedIn = false;
listUserScores =false;
listUsers = false;

sortFriendScore = false;
shortestPath =false;
playGame = false;

mainMenu(); //set up the buttons

}



void LogIn::mainMenu()

{
     timerId=startTimer(20);
     userNameLineEdit = new QLineEdit;
     userYearLineEdit = new QLineEdit;
     userDeleteNameLineEdit = new QLineEdit;
     userLogLineEdit = new QLineEdit;
     userFriendLineEdit = new QLineEdit;
     userDeFriendLineEdit = new QLineEdit;


    QRegExp rx("\\w{0,50}");
    // the validator treats the regexp as only alphanumeric characters
    QRegExpValidator v(rx, 0);

    QValidator *validator = new QRegExpValidator(rx, this);
    userNameLineEdit->setValidator(validator);
    userDeleteNameLineEdit ->setValidator(validator);
    userLogLineEdit->setValidator(validator);
    userFriendLineEdit->setValidator(validator);
    userDeFriendLineEdit->setValidator(validator);


    QRegExp rx2("[12345]\\d{0,0}"); //only gets one integer and it's between 1 and 5
    QRegExpValidator t(rx2, 0);
    validator = new QRegExpValidator(rx2,this);
    userYearLineEdit->setValidator(validator);

    //creating all the buttons and line edits//

    enterUser = new QPushButton("Enter");
    enterDeleteUser = new QPushButton("Enter");
    enterUserLog = new QPushButton("Enter");
    enterFriendAdd = new QPushButton("Enter");
    enterFriendDel = new QPushButton("Enter");

    addUser = new QPushButton("Add User Account");
    deleteUser = new QPushButton("Delete user account");
    logOn = new QPushButton("Log on to user account");
    listHighScores = new QPushButton("list all users sorted by high scores");
    quit = new QPushButton("Quit");

    listUserButton = new QPushButton("List all usernames");
    addFriendButton = new QPushButton();
    DeFriendButton = new QPushButton();
    ShortestButton = new QPushButton();
    PlayButton = new QPushButton("PLAY GAME");
    sortFriendsButton = new QPushButton();

    ///////////////////////////////////////////////

    ///add them all//
    layout = new QFormLayout;

    layout->addWidget(listUserButton);
    layout->addWidget(addFriendButton);
    layout->addWidget(DeFriendButton);
    layout->addWidget(sortFriendsButton);
    layout->addWidget(addUser);
    layout->addWidget(deleteUser);
    layout->addWidget(logOn);
    layout->addWidget(listHighScores);
    layout->addWidget(ShortestButton);
    layout->addWidget(PlayButton);
    layout->addWidget(quit);

    layout->addRow(userNameLineEdit);
    layout->addRow(userYearLineEdit);
    layout->addRow(enterUser);
    layout->addRow(userDeleteNameLineEdit);
    layout->addRow(enterDeleteUser);
    layout->addRow(userLogLineEdit);
    layout->addRow(enterUserLog);
    layout->addRow(userFriendLineEdit);
    layout->addRow(enterFriendAdd);
    layout->addRow(userDeFriendLineEdit);
    layout->addRow(enterFriendDel);

    setLayout(layout);

    ////////////////////////////////////////////////

   ///set things as invisible and set some to visible to be shown in the main screen
    listUserButton->hide();
    addFriendButton->hide();
    DeFriendButton->hide();
    ShortestButton->hide();
    PlayButton->hide();
    userNameLineEdit->hide();
    userYearLineEdit->hide();
    userDeleteNameLineEdit->hide();
    enterUser->hide();
    enterDeleteUser->hide();
    enterUserLog->hide();
    userLogLineEdit->hide();
    sortFriendsButton->hide();
    userFriendLineEdit->hide();
    enterFriendAdd->hide();
    userDeFriendLineEdit->hide();
    enterFriendDel->hide();
    setWindowTitle(tr("Main Menu"));

    ////////////////////////////////////////////////////////////////
    //connecting buttons for the buttons in main screen//////////////////
    QObject::connect( quit, SIGNAL(clicked()),this, SLOT(end()));
    QObject::connect(addUser, SIGNAL(clicked()),this, SLOT(addUserFunction()));
    QObject::connect(deleteUser,SIGNAL(clicked()),this, SLOT(deleteUserFunction()));
    QObject::connect(logOn,SIGNAL(clicked()),this, SLOT(logOnFunction()));
    QObject::connect(listHighScores,SIGNAL(clicked()),this, SLOT(listScoresFunction()));

    ////////////////////////////////////////////////////////////////

}



LogIn::~LogIn()
{
}


void LogIn::end()
{
 rewriteDataBase();
 qApp->exit();
}

void LogIn::rewriteDataBase()
{

   std::string filename,tab;
   tab = "<TAB>";
   filename = "db.txt";
   outs.open(filename.c_str());
   outs<<userNames.size()<<"\n";
   //open db.txt to rewrite file///

   //loop for all the users
   for (int i= 0; i<userNames.size(); i++)
   {
       int schoolyear;
       outs<<userList.at(i)->getIdNumber()<<"\n";
       outs<<tab<<userList.at(i)->getUsername()<<"\n";

       if(userList.at(i)->getSchoolYear() == "Freshman")
           schoolyear =1;
       else if(userList.at(i)->getSchoolYear() == "Sophomore")
           schoolyear = 2;
       else if(userList.at(i)->getSchoolYear() == "Junior")
           schoolyear =3;
       else if (userList.at(i)->getSchoolYear() == "Senior")
           schoolyear =4;
       else
           schoolyear= 5;

       outs<<tab<<schoolyear<<"\n";
       outs<<tab<<userList.at(i)->getScore()<<"\n";
       if(userList.at(i)->getFriendList().empty())//if empty just print out <TAB>
       {
           outs<<tab;
       }
       else
       {
        for (int j = 0;j<userList.at(i)->getFriendList().size();j++)
        {
           outs<<tab<<userList.at(i)->getFriendList().at(j);
        }
       }

       outs<<"\n";
   }
   ins.close();
   outs.close();

}

void LogIn::addUserFunction()
{

listUserScores= false; //dont want scores to be displayed when this function is called
userDeleteNameLineEdit->hide();
enterDeleteUser->hide();
userLogLineEdit->hide();
enterUserLog->hide();

userNameLineEdit->setVisible(true);
userYearLineEdit->setVisible(true);
enterUser->setVisible(true);

userNameLineEdit->setText("Enter new username");
userYearLineEdit->setText("enter your school year (number)");


   layout->addRow(enterUser);
   QObject::connect(enterUser, SIGNAL(clicked()),this, SLOT(getUserData())); //add the enterUser

}

void LogIn::getUserData()
{
    QString username, useryear, tab;
    tab = "<TAB>";
    username = userNameLineEdit->text();

    int count= 0;
    for (int i = 0; i<userNames.size();i++)
    {
        std::cout<<"\n"<<userNames.at(i);
        if (username.toStdString() == userNames.at(i)) //checks if it already exists
        {
                enterUser->setText("That username already exists");
                break;
        }
        else
        {count ++;} //if it's not in the usernames count up


     }
   // std::cout<<userNames.size();
    if (count==userNames.size())   //if it's not found in usernames, count will equal to username size
    {
        enterUser->setText("user profile entered");


    userNames.push_back(username.toStdString());
    useryear= userYearLineEdit->text();
    useryear.prepend(tab);
    username.prepend(tab);

            User = new user(); //set up new user
            User->setUserName(username.toStdString());
            User->setSchoolYear(useryear.toStdString());
            User->setScore("<TAB>0"); //initialize score until they play

            ///RANDOMNIZE IDNUMBER!!!!!
            int randomId = rand() % 1000000000 + 1;
            int count =0;
           for (int i =0; i<userList.size();i++)
           {

             if (userList.at(i)->getIdNumber() == randomId)
             {
                randomId = randomId+1;
                count = 1;
             }
           }
           if (count == 0) //count == 0 means randomId generated is unique
           {

             //converting int to string
               std::string s;
               std::stringstream out;
               out<<randomId;
               s = out.str();
               User->setIdNumber(s);
           }

           ////PUT NOTHING FOR SET FRIEND///
           User->setFriendList("<TAB>");
            userList.push_back(User);

    }
    else  //if username entered is not valid. enter a new one
    {
        userNameLineEdit->setText("Enter new Username");
        userYearLineEdit->setText("Enter school year (number)");
    }

}


void LogIn::deleteUserFunction()
{

  listUserScores =false;
  userYearLineEdit->hide();
  userNameLineEdit->hide();
  userLogLineEdit->hide();
  enterUserLog->hide();
  enterUser->hide();

  userDeleteNameLineEdit->setVisible(true);
  enterDeleteUser->setVisible(true);


    userDeleteNameLineEdit->setText("enter Username you wish to delete");
    QObject::connect(enterDeleteUser, SIGNAL(clicked()),this, SLOT(deleteUserData()));

}

void LogIn::deleteUserData()
{
   int check;
    QString username;
    //tab = "<TAB>";
    username = userDeleteNameLineEdit->text();

    check = userList.size();
    for (int i = 0; i<userNames.size();i++)
    {
        if (userNames.at(i)== username.toStdString())  //find the username in the userName
        {
            userList.erase(userList.begin()+i); //delete in userList
            userNames.erase(userNames.begin()+i); //delete in userNAme
             enterDeleteUser->setText("deleted");
               // delete userList.at(i);
            break;
        }


    }
    ///delete users in friend lists
    for(int i =0; i<userList.size();i++)
    {
       if(userList.at(i)->checkFriend(username.toStdString())) // check if that user is contained in the friend list
        {
            userList.at(i)->deleteFriend(username.toStdString()); //delete the friend from the list
        }
    }


    if (check == userList.size()) //check was set to the size of userList before deleting so if it's still the same size it means, the username doesnt exist in database
    {
        enterDeleteUser->setText("that username does not exist");
    }


}

void LogIn::logOnFunction()
{

    listUserScores= false;

   userDeleteNameLineEdit->hide();
   enterDeleteUser->hide();
   userYearLineEdit->hide();
   userNameLineEdit->hide();
   enterUser->hide();

   userLogLineEdit->setVisible(true);
   enterUserLog->setVisible(true);

    userLogLineEdit->setText("Enter your username");
    enterUserLog->setText("Enter");
    QObject::connect(enterUserLog, SIGNAL(clicked()),this, SLOT(loggedInFunction()));

}

void LogIn::loggedInFunction()
{
    int check =0;
    //int index =0;
     QString username;
     //tab = "<TAB>";
     username = userLogLineEdit->text();
     for (int i = 0; i<userNames.size();i++)
     {
         if (userNames.at(i)== username.toStdString())
         {
            userIndex = i; //when logged in, need to get the index from userList of that specific user
            check = 1;
             break;
         }

     }

     if (check == 0) //check is zero if it didn't find the name
     {
         enterUserLog->setText("that username does not exist");
     }
     else
     {
           loggedIn =true;
           ///////personalizing the button name to add the user's name//////////////////////
           std::string usernameString, addafriend, defriend, shortpath, sortfriends;
           addafriend ="Add a friend for ";
           defriend = "De-friend one of 's friends";
           shortpath = "Shortest-path to  from any user";
           sortfriends = "Sort all 's friends by score";
           usernameString = userNames.at(userIndex);//>getUsername();

           addafriend.append(usernameString);
           defriend.insert(17,usernameString);
           shortpath.insert(17, usernameString);
           sortfriends.insert(9, usernameString);

            QString qadd = QString::fromStdString(addafriend);
            QString qde = QString::fromStdString(defriend);
            QString qshort = QString::fromStdString(shortpath);
            QString qsort = QString::fromStdString(sortfriends);

           /////////////////////////////////////////////////////////


          //sets up the screen for logged in screen//////////////
          userDeleteNameLineEdit->hide();
          enterDeleteUser->hide();
          userYearLineEdit->hide();
          userNameLineEdit->hide();
          enterUser->hide();
          enterUserLog->hide();
          userLogLineEdit->hide();
          addUser->hide();
          deleteUser->hide();
          logOn->hide();

          sortFriendsButton->setText(qsort);
          sortFriendsButton->setVisible(true);
          listUserButton->setVisible(true);
          addFriendButton->setText(qadd);
          addFriendButton->setVisible(true);
          DeFriendButton->setText(qde);
          DeFriendButton->setVisible(true);
          ShortestButton->setText(qshort);
          ShortestButton->setVisible(true);
          PlayButton->setVisible(true);



          QObject::connect(listUserButton, SIGNAL(clicked()),this, SLOT(listUserFunction()));
          QObject::connect(addFriendButton, SIGNAL(clicked()),this, SLOT(addFriendFunction()));
          QObject::connect(DeFriendButton,SIGNAL(clicked()),this, SLOT(deFriendFunction()));
          QObject::connect(sortFriendsButton,SIGNAL(clicked()),this, SLOT(sortScoreFunction()));
          QObject::connect(ShortestButton,SIGNAL(clicked()),this, SLOT(shortestFunction()));
          QObject::connect(PlayButton,SIGNAL(clicked()),this, SLOT(playFunction()));
     }


}


void LogIn::listUserFunction()
{
    userDeFriendLineEdit->hide();
    enterFriendDel->hide();
    listUsers = true;
    listUserScores= false;
    shortestPath = false;
    sortFriendScore =false;
    loggedIn = true;

    userFriendLineEdit->hide();
    enterFriendAdd->hide();
    userDeFriendLineEdit->hide();
    enterFriendDel->hide();
}

void LogIn::addFriendFunction()
{
    listUsers = false;
    listUserScores= false;
    mainMenuScreen = false;
    sortFriendScore = false;
    shortestPath =false;

    loggedIn = true;

    userDeFriendLineEdit->hide();
    enterFriendDel->hide();
    userDeFriendLineEdit->hide();
    enterFriendDel->hide();

    userFriendLineEdit->setVisible(true);
    enterFriendAdd->setVisible(true);
    userFriendLineEdit->setText("add a friend's username");

    QObject::connect(enterFriendAdd,SIGNAL(clicked()),this, SLOT(addThisFriend()));


}

void LogIn::addThisFriend()
{
    QString  friendname;
    friendname = userFriendLineEdit->text();
   // std::cout<<friendname.toStdString();
    vector<string> temp, tempfriend;


            int count= 0;
            int friendIndex =0;
            for (int i = 0; i<userNames.size();i++)
            {
                if (friendname.toStdString() == userNames.at(i)) //find the friend name and get the index
                     {count =1;friendIndex = i;}

            }
            if (count== 0)  //if not found then return
            {
                enterFriendAdd->setText("Friend is not a user");

            }
            else //if found
            {
             int account =0;
                for (int i = 0;i<userList.at(userIndex)->getFriendList().size();i++)
                {
                    if (userList.at(userIndex)->getFriendList().at(i) == friendname.toStdString())
                    {
                        account = 1;

                    }
                    else if(userList.at(userIndex)->getUsername()==friendname.toStdString())
                    {
                        account = 2; // adding yourself
                    }
                }
                if (account == 1)
                {
                    enterFriendAdd->setText("you are already friends");
                  //  userFriendLineEdit->setText("Add a friend");
                }
                else if(account ==2)
                {
                    enterFriendAdd->setText("You are your own friend");
                }
                else
                {
                enterFriendAdd->setText("Friend Added");


                userList.at(userIndex)->addFriend(friendname.toStdString());

                userList.at(friendIndex)->addFriend(userList.at(userIndex)->getUsername());
                }

            }

}

void LogIn::deFriendFunction()
{

    listUsers = false;
    listUserScores= false;
    mainMenuScreen = false;
    shortestPath =false;
    loggedIn = true;
      sortFriendScore = false;
    userFriendLineEdit->hide();
    enterFriendAdd->hide();
    userDeFriendLineEdit->setVisible(true);
    enterFriendDel->setVisible(true);
    userDeFriendLineEdit->setText("Enter a friend you wish to de-friend");

    QObject::connect(enterFriendDel,SIGNAL(clicked()),this, SLOT(deleteThisFriend()));


}
void LogIn::deleteThisFriend()
{
    int friendIndex = 0;
     QString friendname;
     //tab = "<TAB>";
     friendname = userDeFriendLineEdit->text();

     if(userList.at(userIndex)->checkFriend(friendname.toStdString())) //if user is in fact friend
     {
         enterFriendDel->setText("Goodbye friend");
         userList.at(userIndex)->deleteFriend(friendname.toStdString());
        for(int i = 0; i<userNames.size(); i++)   //also find the friend and defriend the user as well
        {
         if(userNames.at(i) == friendname.toStdString())
         {friendIndex = i;}

        }

        userList.at(friendIndex)->deleteFriend(userNames.at(userIndex));
     }
     else
         enterFriendDel->setText("You are not friends with this person actally");

      std::cout<<"\nsize: "<<userList.at(userIndex)->getFriendList().size();


}

void LogIn::sortScoreFunction()
{
    listUsers = false;
    listUserScores= false;
    mainMenuScreen = false;
    shortestPath = false;
    loggedIn = true;
    createFriendList();
    sortFriendScore = true;
    userDeFriendLineEdit->hide();
    enterFriendDel->hide();
    userFriendLineEdit->hide();
    enterFriendAdd->hide();


}
void LogIn::shortestFunction()
{
    sortFriendScore = false;
    listUsers = false;
    listUserScores= false;
    mainMenuScreen = false;
    loggedIn = true;
    userDeFriendLineEdit->hide();
    enterFriendDel->hide();
    userFriendLineEdit->hide();
    enterFriendAdd->hide();

    shortestPath =  true;
}

void LogIn::playFunction()
{
    userDeFriendLineEdit->hide();
    enterFriendDel->hide();
    userFriendLineEdit->hide();
    enterFriendAdd->hide();
    listUsers = false;
    listUserScores= false;
    mainMenuScreen = false;
    loggedIn = true;

    sortFriendScore = false;
    shortestPath =false;

    playGame =true;

    //create the game class
    game.show();
    QSound bells("sounds/background.mp3");
    bells.play();
    center(game);



}


void LogIn::center(QWidget &widget) //for the game class
{
    int x, y;
    int screenWidth, screenHeight;

    int WIDTH = 600;//600;
    int HEIGHT = 700;

    QDesktopWidget *desktop = QApplication::desktop();
    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;
    widget.setGeometry(x, y, WIDTH, HEIGHT);
    widget.setFixedSize(WIDTH, HEIGHT);

}


void LogIn::listScoresFunction()
{
   sortFriendScore = false;
   listUserScores = true;
   listUsers =false;

    userFriendLineEdit->hide();
    enterFriendAdd->hide();
    userLogLineEdit->hide();
    enterUserLog->hide();
    userNameLineEdit->hide();
    userYearLineEdit->hide();
    enterUser->hide();
    userDeleteNameLineEdit->hide();
    enterDeleteUser->hide();
    userDeFriendLineEdit->hide();
    enterFriendDel->hide();

}


void LogIn::paintEvent(QPaintEvent *event)    //makes display
{



    setColor = "steelblue";

    QPainter painter(this);
    QColor pencolor(setColor);
    QPen pen;
    pen.setColor(pencolor);
    pen.setWidth(8);
    painter.setPen(pen);

    QFont font("Arial", 15, QFont::AllUppercase);
    setFont(font);


    if (loggedIn)
    {
        QString str;
        painter.drawText(10,680,"Number of users: ");
        str.setNum(userList.size());
        painter.drawText(200,680,str);

        int size = userNames.size();
        int total = 0;

        for (int s=0; s<size;s++)
        {
            if (userList.at(s)->getFriendList().empty())
            {
                total  = total;
            }
            else
            total = total +userList.at(s)->getFriendList().size(); //counts the number of relations
        }

        //print user information//////////
        str.setNum(total); ///getting number of relations
        painter.drawText(350,680,"Number of relations: ");
        painter.drawText(550,680,str);

        painter.drawText(10, 570,"User logged on: ");
        painter.drawText(10,590,"User name: ");
        str = QString::fromStdString(userNames.at(userIndex));
        painter.drawText(120,590,str);

        painter.drawText(10,610, "Year: ");
        str = QString::fromStdString(userList.at(userIndex)->getSchoolYear());
        painter.drawText(120,610,str);

        painter.drawText(10,630,"High score: ");
        str.setNum(userList.at(userIndex)->getScore());
        painter.drawText(120,630,str);


        painter.drawText(10,650,"Friends: ");  //print out friends
        string tempfriends;
        for (int i = 0; i<userList.at(userIndex)->getFriendList().size();i++)
        {
            str= QString::fromStdString(userList.at(userIndex)->getFriendList().at(i));
            painter.drawText(120 + i*100,650,str);

        }

        //////////////////////////////////////

        if(listUserScores) //list all the users and their scores sorted
        {
            std::vector<int> indexScore;
            std::vector<string> indexNames;
            for (int i = 0; i<userList.size(); i++)
            {
                indexScore.push_back(userList.at(i)->getScore());
                indexNames.push_back(userList.at(i)->getUsername());

            }

            ///////////selection sort//////////
             QString str, strnum;
              int temp, max;
              std::string tempstring;
              for (int i = 0; i<indexScore.size();i++)
              {
                  max = i;
                  for (int j = 1+i; j < indexScore.size();j++)
                  {
                      if (indexScore.at(j) > indexScore.at(max))
                          max = j;

                  }
                  temp = indexScore.at(max);
                  tempstring = indexNames.at(max);
                  indexScore.at(max) = indexScore.at(i);
                  indexNames.at(max) = indexNames.at(i);
                  indexScore.at(i)= temp;
                  indexNames.at(i)= tempstring;

                  str = QString::fromStdString(indexNames.at(i));  //while sorting print them out
                  strnum.setNum(indexScore.at(i));

                    painter.drawText(350,400+i*20,strnum);
                  painter.drawText(225,400+i*20,str);

                }


        }
        else if (listUsers)
        {
            QString qstrName;
            for (int i= 0;i < userNames.size();i++)
            {
               qstrName = QString::fromStdString(userNames.at(i));
               painter.drawText(275, 400 +i *20, qstrName);
            }
        }

        else if(sortFriendScore)
        {


            std::vector<int> indexScore;   //create temporary scores
            std::vector<string> indexNames; //create temporary names
            ////create these so you don't have to change the format of the userList and can get confusing with different indices

            for (int i = 0; i<userList.at(userIndex)->getFriendList().size(); i++)
            {
                //indexScore.push_back(userList.at(i)->getScore());
                indexNames.push_back(userList.at(userIndex)->getFriendList().at(i));

            }
            int tempIndex;
            for (int i = 0; i<userList.at(userIndex)->getFriends().size(); i++)
            {
                tempIndex = userList.at(userIndex)->getFriends().at(i);
                indexScore.push_back(userList.at(tempIndex)->getScore());
               }

            //insertion sort///

             QString str, strnum;
              int temp, max;
              std::string tempstring;
              for (int i = 0; i<indexScore.size();i++)
              {
                  max = i;
                  for (int j = 1+i; j < indexScore.size();j++)
                  {
                      if (indexScore.at(j) > indexScore.at(max))
                          max = j;

                  }
                  temp = indexScore.at(max);
                  tempstring = indexNames.at(max);
                  indexScore.at(max) = indexScore.at(i);
                  indexNames.at(max) = indexNames.at(i);
                  indexScore.at(i)= temp;
                  indexNames.at(i)= tempstring;

                  str = QString::fromStdString(indexNames.at(i));
                  strnum.setNum(indexScore.at(i));

                    painter.drawText(325,400+i*20,strnum);
                  painter.drawText(225,400+i*20,str);

              }





        }
        else if (shortestPath)
        {
            painter.drawText(300, 500,"Put shortest path here");
        }
        else if (playGame)
        {
            //if score from the game is greater than the user's database score, update!
            if(game.SCORE > userList.at(userIndex)->getScore())
            {
                std::string sc, tab;
                std::stringstream out;
                out<<game.SCORE;
                sc = out.str();
                tab = "<TAB>";
                tab.append(sc);
                userList.at(userIndex)->setScore(tab);
            }
           // painter.drawText(100, 100, "play game");
        }
        else
        {}

    }

    else if(mainMenuScreen) {
  //main screen///////

        ///////////set the users and relations display/////////
        QString str;
        painter.drawText(10,680,"Number of users: ");
        str.setNum(userList.size());
        painter.drawText(200,680,str);

        int size = userNames.size();
        int total = 0;

        for (int s=0; s<size;s++)
        {
            total = total +userList.at(s)->getFriendList().size();
        }
        str.setNum(total); ///getting number of relations
        painter.drawText(350,680,"Number of relations: ");
        painter.drawText(550,680,str);

        //////////////////////////////////


        if(listUserScores)
        {
            std::vector<int> indexScore;
            std::vector<string> indexNames;
            for (int i = 0; i<userList.size(); i++)
            {
                indexScore.push_back(userList.at(i)->getScore());    //create temporary score list
                indexNames.push_back(userList.at(i)->getUsername()); //create temporary name list

            }

            //same as above function//////insertion sort

             QString str, strnum;
              int temp, max;
              std::string tempstring;
              for (int i = 0; i<indexScore.size();i++)
              {
                  max = i;
                  for (int j = 1+i; j < indexScore.size();j++)
                  {
                      if (indexScore.at(j) > indexScore.at(max))
                          max = j;

                  }
                  temp = indexScore.at(max);
                  tempstring = indexNames.at(max);
                  indexScore.at(max) = indexScore.at(i);
                  indexNames.at(max) = indexNames.at(i);
                  indexScore.at(i)= temp;
                  indexNames.at(i)= tempstring;

                  str = QString::fromStdString(indexNames.at(i));
                  strnum.setNum(indexScore.at(i));

                    painter.drawText(350,400+i*20,strnum);
                  painter.drawText(225,400+i*20,str);

              }

        }


    }
    else
    {} //end of paint event only mainscreen and logged in screen

}



bool LogIn::readDataBase() //initial function to read the db.txt and make sure it is good;
{


        bool noError =true;
        std::ifstream ins;

            std::string filename;
            filename = "db.txt";
            ins.open(filename.c_str());

            if (ins.fail())
                {
                std::cout<<"\nBad file name.\n";
                return (false);
                }
            else
            {

                ins>>numberUsers; //firstread the number of users
                if (ins.fail())
                {
                     std::cout<<"\nCheck db.txt wrong format in the # of users\n";
                    return false;
                }
                if(numberUsers<1 || numberUsers>1000000000)   //number must be betwen these set parameters
                {
                    std::cout<<"\nCheck number of users in your db.txt\n";
                    return false;
                }


                while (!(ins.eof())) //while we reach the end of the text file
               //for(int s = 0; s<3;s++)
               {

                    ins.exceptions(std::ifstream::failbit);

                    User = new user();
                    try
                    {
                    //int temp_int;
                    std::string temp_string;

                    ins>>temp_string;
                    noError = User->setIdNumber(temp_string);
                    //std::cout<<"Id: "<<User->getIdNumber();

                    if (!noError)
                     throw(noError);  //if there's error throw them out

                    ins>>temp_string;
                    noError = User->setUserName(temp_string);
                    //std::cout<<"\nuserName  "<<User->getUsername()<<"\n";

                    if (!noError)
                     throw(noError);

                    ins>>temp_string;
                    noError = User->setSchoolYear(temp_string);
                    //std::cout<<"schoolYear   "<<User->getSchoolYear()<<"\n";

                    if (!noError)
                     throw(noError);

                    ins>>temp_string;
                    noError = User->setScore(temp_string);
                    //std::cout<<"score   "<<User->getScore()<<"\n";

                    if (!noError)
                     throw(noError);


                    ins>>temp_string;
                    noError = User->setFriendList(temp_string);

                    if (!noError)
                     throw(noError);

                    ins.ignore(5,'\n');

                    userNames.push_back(User->getUsername());
                    userList.push_back(User); //get all the information



                    }
                    catch(std::ifstream::failure &ex) {

                        break; //basically to check if we had reached the end
                    // return true;
                   }
                    catch(bool noError)
                    {
                        return noError;
                    }

                }
               if (ins.eof())
               {

                  return (checkUniqueness());//checkuniqueness for unique id, username, and see if friends exist //if we reached the end, return true
               }
               else
                   return false; //if we breaked but didnt reach the end, theres an error of some sort, return false
            }


    }

bool LogIn::checkUniqueness()
{
    int count =0 ;
    for (int i = 0; i<userList.size();i++)
    {    //check that username is unique
        for (int j =0; j<userNames.size();j++)
        {

            if ((userList.at(i)->getUsername()== userNames.at(j) && (i!=j))) // cross check with itself to see if theres a repeat of a name
                    return false;

        }
        //check id is unique
        for (int j = 0; j<userList.size(); j++)
        {
            if((userList.at(i)->getIdNumber()== userList.at(j)->getIdNumber()) &&(i!=j))
                return false;


        }


        //check friends exist//
        userFriends = userList.at(i)->getFriendList();
        for (int j = 0; j<userFriends.size();j++)
        {
            count =0;
            for (int s = 0; s<userNames.size();s++)
            {
                if (userFriends.at(j) == userNames.at(s))

                       count ++;

            }
            if (count == 0)
            {
                std::cout<<"\nOne of the friends does not exist as a user\n";
                return false;
            }
            else
                count = 0;
        }


    }

    //check if your friends are friends with you as well
    createFriendList();
    vector<int> userFriendsIndex;
    for (int s = 0; s<userList.size();s++)
    {
        userFriendsIndex = userList.at(s)->getFriends(); //get indices of the user's friends
        for (int t= 0; t<userFriendsIndex.size(); t++)
        {
            if(userList.at(userFriendsIndex.at(t))->checkFriend(userNames.at(s))) // check friend's list of friend to see if the initial user's name is also included
            {} //if it does have it then it's good
            else
            {
                std::cout<<"Your friend is not friend's with you\n";
                return false; //if in the friend's friendlist, user's name doesn't exist, than user's friend is not friends with the user;

            }
        }
    }


    //if all is unique then return true and never had to return false throughout the code, it's good
    return true;

}





void LogIn::createFriendList()
{
//sets the vector of friends' indices for users
   std::vector<int>  temp;

    for (int i = 0; i<userList.size();i++)
    {
        temp.clear();
        userFriends = userList.at(i)->getFriendList();
       for (int j = 0; j<userFriends.size();j++)
        {
           for (int k = 0; k<userNames.size();k++)
            {
                if(userFriends.at(j)==userNames.at(k))
                {
                   temp.push_back(k);
                   }

           }

        }
      userList.at(i)->setFriends(temp);

    }


}

void LogIn::timerEvent(QTimerEvent *event)        //for 1 loop of the game
{

    repaint();

}
