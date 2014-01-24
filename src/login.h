#ifndef LOGIN_H
#define LOGIN_H
#include <vector>
#include <QWidget>
#include <QKeyEvent>
#include <QString>
#include "user.h"
#include <iostream>
#include <fstream>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <Dodger.h>

//this is the crux of the menu driven interface, the game interface dodger is also inherited//

class LogIn: public QWidget
{

    Q_OBJECT
public:
    LogIn();
    ~LogIn();

    void paintEvent(QPaintEvent *event);        //prints some of the lists, etc, on screen
    void timerEvent(QTimerEvent *event);        //loops game

    bool readDataBase();  // return true if all the variables in db.txt is verified
    bool checkUniqueness(); //check the uniqueness username and id number and make sure your friends exist in the database as a user
    void createFriendList(); //creates an array of indices of the friends for each class User

    void mainMenu();//creates all the buttons and lineedits and sets the initial menu screen

    void center(QWidget &widget); //some parameters for the Dodger game
    void rewriteDataBase();   //function that rewrites the database in the output. this gets executed when user quits

public slots:

    void end(); // ending the menu interface
    void deleteUserFunction(); //create the interface to delete user: enter the username to delete
    void logOnFunction();// log on function which creates an interface for logging in
    void listScoresFunction();//list the scores of all users
    void addUserFunction(); //create the adding user interface with enter username and school year
    void getUserData(); //given the input from the addUserFunction, actual function that enters the data and stores it, creating arbitrary ids,etc
    void deleteUserData();  //obtaining input from deleteUserFunction and actually deleting the user and deleting the user's name in other user's friend lists

    void loggedInFunction(); //obtaining data from logOnFunction and verify username exists and create the interface for the second screen when user is logged on

    void listUserFunction();   //sets the boolean for listUser and sends it to paintevent so that usernames can be listed on the screen
    void addFriendFunction(); //function to set the add friend interface
    void deFriendFunction();  //function to set the delete a friend interface
    void sortScoreFunction(); // sets the boolean for sortFriendScore so that in paintevent, the sorted friend's score is listed on the screen
    void shortestFunction();  // sets the boolean for bfs shortest path and print them out (couldn't get this to work)
    void playFunction(); // play the game: creates the game class Dodger called game/ sets boolean to the paintevent so that score can be updated if highscore was achieved

    void addThisFriend();  //gets input from addFriendFunction and adds the new friend (first verify if the friend exists in the database and you are not adding yourself)
    void deleteThisFriend();  //gets input from deleteThisFriend and verifies that friend exists and then delete the friend as well as delete your name from that friend's friendlist.


private:
    QLineEdit
    *userNameLineEdit,          //for add username input
    *userYearLineEdit,          //for school year input
    *userDeleteNameLineEdit,    //for username to delete input
    *userLogLineEdit,           //for username to log in input
    *userFriendLineEdit,        //for adding friend input
    *userDeFriendLineEdit;      //for de friending input


    Dodger game; //actual game
    QFormLayout *layout; //layout of how button and line edits are layed out
    QValidator *v, *t; //Qvalidators for lineedit


    QPushButton
        *addSchool, //button for adding users
        *enterUser, //button to get the new user information
        *enterDeleteUser, //button to  get the username for deleting
        *enterUserLog,    //button to enter the user's name for login
        *enterFriendAdd,  //button to enter the new friend's information
        *enterFriendDel,  //button to get the friend's username for deleting

        *listUserButton,  //button to list usernames
        *addFriendButton, //button to add a friend
        *DeFriendButton,  //button to de friend
        *ShortestButton,  //button for shortest path
        *PlayButton,      //button to play
        *sortFriendsButton,//button to sort user's friends scores

        *addUser,           //button to add user
        *deleteUser,        //button to delete
        *logOn,             //button to log in
        *listHighScores,    //button to list everyone's score by descending order
        *quit;              //button to quit


    std::vector<user*> userList;                //vector of class User
    std::vector<std::string> userFriends;       // vector of a user's friends
    std::vector<std::string> userNames;         //vector of just the user's usernames

    user* User;  //user class


    QString setColor;

    int userIndex,      //index of the selected user when logged in
    timerId,            //set the timer to run paintevent in a loop
    numberUsers;        //number of users to be displayed on the main menu screen

    bool listUserScores,// lists all the users and their scores in order
    listUsers,          // lists all the users
    sortFriendScore,    //sorts all the user's friend scores and prints them out
    shortestPath,       //shortest path
    playGame,           //update the highscore
    mainMenuScreen,     //print the number of users and relations on the main menu page
    loggedIn;           //sets the paintevent for logged in screen, prints out the user's information

    std::ifstream	ins;  //read from inputfile
    std::ofstream	outs; //write on outputfile
};

#endif // LOGIN_H
