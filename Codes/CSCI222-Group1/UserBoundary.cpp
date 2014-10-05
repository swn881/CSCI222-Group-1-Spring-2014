#include <iostream>
#include "UserBoundary.h"
#include <cstring>

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
    bool check = false;
    cout << "Please input as stated..." << endl << endl;

    //check if username exists
    while(check == false)
    {
        cout << "User name: ";
        cin >> tempUN;
        if (userControl.checkUN(tempUN))
        {
            check = false;
            cout << "\n>> You have entered an existing username or a username too short! <<" << endl;
            cout << ">> Please try again! <<" << endl;
        }
        else
        {
            check = true;
        }
    }
    check = false;
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
    while(check == false)
    {
        cout << "Password: ";
        cin >> tempPw;
        if(!userControl.checkPW(tempPw))
        {
            check = false;
            cout << ">> The password you have entered is not long enough or too long! <<" << endl;
            cout << ">> Please enter a longer password! << " << endl;
        }
        else
        {
            check = true;
        }
    }

    userControl.registerUser(tempUN, tempFN, tempLN, tempEmail, tempUni, tempExp, tempPw);
}

void UserBoundary::login()
{
    bool loginCheck = false;
    string tempUN;
    string tempPw;
    while (loginCheck == false)
    {
        cout << "Please key in your username and password. . ." << endl << endl;
        cout << "Username: ";
        cin >> tempUN;
        cout << "Password: ";
        cin >> tempPw;

        if(userControl.login(tempUN, tempPw)) //login successful
        {
            loginCheck = true;
            cout << "Welcome " << tempUN << " to the system!" << endl;
            currentLoggedIn = tempUN;
        }
        else
        {
            loginCheck = false;
            cout << ">> Invalid username or password! <<" << endl;
            cout << ">> Please try again! <<" << endl;
        }
    }
}

void UserBoundary::changePassword()
{
    //user must be logged in to change password;
    bool loginCheck = false;
    string tempPassword;
    string tempUsername;


    while (loginCheck == false)
    {
        cout << "For security reasons, please input your username and password again!" << endl;
        cout << "Username: " ;
        cin >> tempUsername;
        cout << "Password: ";
        cin >> tempPassword;

        if(userControl.login(tempUsername, tempPassword)) //login successful
        {
            char newPassword[100];
            loginCheck = true;
            bool passwordCheck = false;
            while (passwordCheck == false)
            {
                cout << "Please enter your new password! " << endl;
                cout << "Password: ";
                cin >> newPassword;

                if (newPassword == tempPassword)
                {
                    passwordCheck = false;
                    cout << "Your new password cannot be similar to your old password!" << endl;
                    cout << ">> Please try again! <<" << endl;
                }
                else if (!userControl.checkPW(newPassword))
                {
                    passwordCheck = false;
                    cout << ">> The password you have entered is not long enough or too long! <<" << endl;
                    cout << ">> Please enter a longer password! << " << endl;
                }
                else
                {
                    passwordCheck = true;
                }
            }
            //change password function
            userControl.changePassword(tempUsername, tempPassword, newPassword);
        }
        else
        {
            loginCheck = false;
            cout << ">> Invalid username or password! <<" << endl;
            cout << ">> Please try again! <<" << endl;
        }
    }
}

void UserBoundary::changeDetails()
{
    if (currentLoggedIn == "")
    {
        cout << "No users are currently logged in" << endl;
    }
    else
    {
        cout << "Now currently modifying details for " << currentLoggedIn << endl;

        int choice = 0;
        while(choice != 9)
        {
            cout << "1. Update email" << endl;
            cout << "2. Update university" << endl;
            cout << "3. Update expertise" << endl;
            cout << "9. Quit updating" << endl;
            cout << "Choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    string tempEmail;
                    cout << "Updating email . . ." << endl;
                    cout << "\nPlease input your new email" << endl;
                    cout << "Email: " ;
                    cin >> tempEmail;
                    userControl.updateEmail(currentLoggedIn, tempEmail);
                }
                break;
                case 2:
                {
                    string tempUniversity;
                    cout << "Updating university. . ." << endl;
                    cout << "\nPlease input your new university" << endl;
                    cout << "University: " << endl;
                    cin >> tempUniversity;
                }
                break;
                case 3:
                {
                    string tempExpertise;
                    cout << "Updating expertise. . ." << endl;
                    cout << "\nPlease input your new expertise" << endl;
                    cout << "Expertise: " << endl;
                    cin >> tempExpertise;
                }
                break;
                case 9:
                {
                    cout << "Going back to main menu. . ." << endl;
                }
                break;
                default:
                {
                    cout << "Option does not exist!" << endl;
                    cout << "Please try again!" << endl;
                }
            }
        }
    }

}
