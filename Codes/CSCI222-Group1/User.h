#include <iostream>
#include <string>

#ifndef _USER_
#define _USER_

class User
{
    private:
        std::string userID;
        std::string firstName;
        std::string lastName;
        std::string userName;
        std::string email;
        std::string university;
        std::string expertise;
        std::string password;
    public:
        User() {userID = ""; firstName = ""; lastName = ""; email = ""; university = ""; password = "";}
        void setUserID(std::string tempID) {userID = tempID;}
        void setFirstName(std::string tempFN) {firstName = tempFN;}
        void setLastName (std::string tempLN) {lastName = tempLN;}
        void setUserName (std::string tempUN) {userName = tempUN;}
        void setEmail (std::string tempEmail) {email = tempEmail;}
        void setUniversity (std::string tempUni) {university = tempUni;}
        void setExpertise (std::string tempExp) {expertise = tempExp;}
        void setPassword (std::string tempPw) {password = tempPw;}
};

#endif
