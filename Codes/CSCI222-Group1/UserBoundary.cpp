#include <iostream>
#include "UserBoundary.h"

using namespace std;

void UserBoundary::registerUser()
{
    string tempUserName;
    string tempFirstName;
    string tempLastName;
    string tempEmail;
    string tempUniversity;
    string tempPassword;

    cout << "Please input as stated..." << endl << endl;

    cout << "Username: ";
    cin >> tempUserName;
    cout << "First name: ";
    cin >> tempFirstName;
    cout << "Last name: ";
    cin >> tempLastName;
    cout << "Email: ";
    cin >> tempEmail;
    cout << "University: ";
    cin >> tempUniversity;
    cout << "Password: ";
    cin >> tempPassword;
}
