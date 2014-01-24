#include "user.h"
#include <stdlib.h>
#include <iostream>
#include <vector>

user::user()
{
   idNumber = 0;
   schoolYear = "Freshman";
    score =0;
   userName= "";
   // friendList[0] = "";*/

}

user::~user()
{std::cout<<"user deleted\n";}

int user::getIdNumber()
{
    return (idNumber);
}

std::string user::getSchoolYear()
{
    return(schoolYear);
}

int user::getScore()
{
    return(score);
}

std::string user::getUsername()
{
    return(userName);
}
std::vector<std::string> user::getFriendList()
{
    return friendList;
}

std::vector<int> user::getFriends()
{
    return friends;
}

void user::setFriends(std::vector<int> friendset)
{
   friends  = friendset;
}
void user::addFriend(std::string addfriendname)
{
    friendList.push_back(addfriendname);
}

void user::deleteFriend(std::string delfriendname)
{
    for (int i = 0; i<friendList.size();i++)
    {
        if(friendList.at(i) == delfriendname)
        {
            friendList.erase(friendList.begin()+i);
        }

    }
}
bool user::checkFriend(std::string friendnamecheck)
{
    for (int i = 0; i<friendList.size();i++)
    {
        if (friendList.at(i)==friendnamecheck)
            return true;
    }
    return false;
}

bool user::setIdNumber(std::string verifyId)
{
    int count =0;
    std::string numbers;
    numbers = "1234567890";

    for (int i = 0; i <verifyId.length();i++)
    {
        for (int j = 0; j<numbers.length();j++)
        {
            if(verifyId.at(i) == numbers.at(j))
                count ++; //check if there are only numbers

        }
    }


    if (count == verifyId.length()) //if they are all numbers continue
    {
        int id = atoi(verifyId.c_str());

         try
       {
       if(id<1 || id< 1,000,000,000)
            throw id;

       idNumber = id;
         }
         catch(int x)
        {
       std::cout<<"your ID number "<<x<<" is illegal. Must be between 1 and 1,000,000,000\n";
        return false;
    }
    return true;
    }

    else
    {
        std::cout<<"\nCheck ID number, it contains non numeric character or it's not a positive number\n";
        return false; //if id contains nonnumberic character return false;
    }
}

bool user::setSchoolYear(std::string tabYear)
{
   std::string tab;
   tab="<TAB>";
   int count =0;
   std::string numbers;
   numbers = "1234567890";



   if(tabYear.compare(0,5,tab)==0)
   {
       tabYear.assign(tabYear,5, tabYear.length());

       for (int i = 0; i <tabYear.length();i++)
       {
           for (int j = 0; j<numbers.length();j++)
           {
               if(tabYear.at(i) == numbers.at(j))
                   count ++; //check if there are only numbers
           }
       }


       if (count == tabYear.length()) //if they are all numbers continue
       {

           try
           {

            int  year = atoi(tabYear.c_str());
            if(year<1 || year>5)
                throw year;


            if (year == 1)
                schoolYear = "Freshman";
            else if(year ==2)
                schoolYear = "Sophomore";
            else if(year == 3)
                schoolYear = "Junior";
            else if(year==4)
                schoolYear  = "Senior";
            else
                schoolYear = "5th Year";
            }
            catch(int x)
            {
                 std::cout<<"Your School Year doesn't make sense. Must be between 1 and 5\n";
                return false;
            }

           return true;
        }
       else
       {
           std::cout<<"School year contains non numberic characters\n";
           return false;
       }

   }

   else
   {
       std::cout<<"Format is wrong. There's no <TAB> in the beginning\n";
       return false;
   }

}

bool user::setScore(std::string tabScore)
{
    std::string tab;
    tab="<TAB>";
    int count =0;
    std::string numbers;
    numbers = "1234567890";

    if(tabScore.compare(0,5,tab)==0)
    {
      tabScore.assign(tabScore,5, tabScore.length());

     ////////////////check for non numeric characters////////////
          for (int i = 0; i <tabScore.length();i++)
          {
              for (int j = 0; j<numbers.length();j++)
              {
                  if(tabScore.at(i) == numbers.at(j))
                      count ++; //check if there are only numbers
              }
          }


          if (count == tabScore.length()) //if they are all numbers continue
          {
          try
          {
           int sc = atoi(tabScore.c_str());
           if(sc<0)
             throw sc;
            score = sc;

           }
           catch(int x)
           {
            std::cout<<"Your Score "<<x<<" is invalid. must be a positive integer\n";
            return false;
            }
            return true;
          }
          else
          {
              std::cout<<"Your Score contains non numeric characters\n";
              return false;
          }
    }

    else
    {
        std::cout<<"Format is wrong. There's no <TAB> in the beginning\n";
        return false;
    }
}

bool  user::setUserName(std::string name)
{
    std::string illegalCharacters, tab;
    tab="<TAB>";
    if(name.compare(0,5,tab)==0)
    {
    illegalCharacters = "~`!@#$%^&*()-+=\][|}{';:/.,?>< "; //all the invalid characters for the userName
    try
    {
        for (int i = 5; i <name.length();i++)
        {
            for (int j = 0; j<illegalCharacters.length();j++)
            {
                if(name.at(i) == illegalCharacters.at(j))
                    throw name.at(i);
            }

        }
        userName.assign(name,5,name.length());
     }


    catch(char str)
    {
        std::cout<<"Your UserName   "<<name<<"    is invalid because it contains '"<<str<<"'\n";
        return false;
    }


    return true;
    }
    else
    {
        std::cout<<"Format is wrong. There's no <TAB> in the beginning\n";
        return false;
    }
}



bool user::setFriendList(std::string friends)
{
    std::vector<int> findTab;
    std::string str;
    int found;
    int temp =0;
    str = "<TAB>";
    for (int i= 0 ;i<friends.length();i++)
    {
        found = friends.find(str,i+temp);

        if(found!=std::string::npos)
        {

            findTab.push_back(int(found));  //findTab has all the indices of the first '<' where <TAB> is found
            temp = int(found);
        }
    }

  // std::cout<<findTab.size()<<"\n";


    if (findTab[0]+5==friends.length()) //if it only contains <TAB> with no friends
    {
    }

    else
    {
        std::string temps;
        for (int j = 0;j<findTab.size();j++)
        {
            if ((j+1) != findTab.size())
            {
                temps.assign(friends,findTab[j]+5,findTab[j+1]-(findTab[j]+5));
               friendList.push_back(temps);
            }
            else //first the last tab go from last tab indices to the end of the friend string size
             { temps.assign(friends,findTab[j]+5, friends.length()-1);
                friendList.push_back(temps);
            }


        }
    }

    return true;  //if nothing went wrong

}



