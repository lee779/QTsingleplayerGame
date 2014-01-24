#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

class user
{
public:
    user();
    ~user();

    //getters
    int getIdNumber();
    std::string getSchoolYear();
    int getScore();
    std::string getUsername(); //return username
    std::vector<std::string> getFriendList(); //returns vector of friends in strings
    std::vector<int> getFriends();  //returns vector of friends' indices
    //////////////////


    //setters
    bool setIdNumber(std::string);
    bool setSchoolYear(std::string);
    bool setScore(std::string);
    bool setUserName(std::string);
    bool setFriendList(std::string); //string of friends not sorted, containing <TAB>
    //theseinputs are entered as string for easier way to verify data
    //also they return boolean becasue it's incorporated in the readDataBase (see login.h)

    void setFriends(std::vector<int>); //storing indices of the friends



    void addFriend(std::string);   //gets string and add it in to the friendList
    void deleteFriend(std::string);//gest string and delete it in the friendlist
    bool checkFriend(std::string); //returns a boolean for checking if the friend exists in friendlist


private:

    int idNumber;
    std::string schoolYear;
    int score;
    std::string userName;
    std::vector <std::string> friendList; //stores friend's username
    std::vector<int>  friends; //stores the indices of the friends in userList
};

#endif // USER_H
