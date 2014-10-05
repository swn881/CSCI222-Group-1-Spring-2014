#include <iostream>
#include "UserControl.h"

#ifndef _USERBOUNDARY_
#define _USERBOUNDARY_

class UserBoundary
{
    private:
        UserControl userControl;
        std::string currentLoggedIn;
    public:
        UserBoundary() {currentLoggedIn = "";};
        void registerUser();
        void login();
        void changePassword();
        void changeDetails();
};

#endif // _USERBOUNDARY_
