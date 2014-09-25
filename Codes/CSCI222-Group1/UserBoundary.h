#include <iostream>
#include "UserControl.h"

#ifndef _USERBOUNDARY_
#define _USERBOUNDARY_

class UserBoundary
{
    private:
        UserControl userControl;
    public:
        void registerUser();
};

#endif // _USERBOUNDARY_
