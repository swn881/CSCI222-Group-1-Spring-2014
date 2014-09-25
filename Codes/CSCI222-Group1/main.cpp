#include <iostream>
#include "UserBoundary.h"

using namespace std;

int main()
{
    int choice = 0;
    UserBoundary userBoundary;

    while (choice != 9)
    {
        cout << "Welcome to the system" << endl;
        cout << ">>> Main Menu <<<" << endl;
        cout << "What would you like to do today?" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "9. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "You have selected register!" << endl;
                userBoundary.registerUser();
            }
            break;
            case 2:
            {
                cout << "You have selected login!" << endl;
            }
            break;
            case 9:
            {
                cout << "Thanks for using the system!" << endl;
            }
            break;
            default:
            {
                cout << "Invalid input! Please try again!" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
