#include <iostream>
#include "UserBoundary.h"

using namespace std;

void UserBoundary::registerUser()
{
    string tempUN;
    string tempFN;
    string tempLN;
    string tempEmail;
    string tempUni;
    string tempExp;
    string tempPw;
    cout << "Please input as stated..." << endl << endl;

    cout << "User name: ";
    cin >> tempUN;
    cout << "First name: ";
    cin >> tempFN;
    cout << "Last name: ";
    cin >> tempLN;
    cout << "Email: ";
    cin >> tempEmail;
    cout << "University: ";
    cin >> tempUni;
    cout << "Expertise: ";
    cin >> tempExp;
    cout << "Password: ";
    cin >> tempPw;

    userControl.registerUser(tempUN, tempFN, tempLN, tempEmail, tempUni, tempExp, tempPw);
}

void UserBoundary::login()
{
    string tempUN;
    string tempPw;
    cout << "Please key in your username and password. . ." << endl << endl;
    cout << "Username: ";
    cin >> tempUN;
    cout << "Password: ";
    cin >> tempPw;

    userControl.login(tempUN, tempPw);
}
