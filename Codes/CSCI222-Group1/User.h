#include <iostream>
#include <string>

#ifndef _USER_
#define _USER_

class User
{
    friend std::ostream& operator<<(std::ostream&,const User &);
    friend std::istream& operator>>(std::istream&,User &);
    private:
        std::string userName;
        std::string firstName;
        std::string lastName;
        std::string email;
        std::string university;
        std::string expertise;
        std::string password;
    public:
        User() {userName = ""; firstName = ""; lastName = ""; email = ""; university = ""; password = "";}
        ~User();
        void setAll(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
        void setUserName (std::string);
        void setFirstName(std::string);
        void setLastName (std::string);
        void setEmail (std::string);
        void setUniversity (std::string);
        void setExpertise (std::string);
        void setPassword (std::string);
        std::string getUsername();
        std::string getPassword();
};

#endif
