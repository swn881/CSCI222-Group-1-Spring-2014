#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <ctime>
#include <sstream>
#include <conio.h>
#include "conferenceCreate.h"
#include "setWindow.h"
using namespace std;

void conference::setConference(int nDay, int nMon, int nYr, string desc)
{
    day = nDay;
    month = nMon;
    year = nYr;
    description = desc;
}


void conference::transfer()
{
    ofstream fout;
    fout.open("conference\\Conference.txt");
    fout << "Date: " << day << "/" << month << "/" << year << endl;
    fout << "Description: " << endl;
    fout << description << endl;
    fout << endl;
    fout.close();
}


int conferenceCheck::checkYear(int last)
{
    time_t current;
    time(&current);
    tm * now = localtime(&current);

    //issue: return is wrong: fix
    int curr = (now->tm_year + 1900);

    if (last < curr)
        return 0; //Used to return not a valid year (last year or beforehand)
    else if (last == curr)
        if ((last % 4) == 0)
            return 1; //Used to return value to say if year is current and a leap year
        else
            return 2; //Used to return value to say if year is current and not a leap year
    else
    {
        if((last % 4) == 0)
            return 3; //Used to return if value is valid and a leap year
        else
            return 4; //Used to return if value is valid and not a leap year
    }
}


int conferenceCheck::checkMonth(int then, int yr)
{
    time_t current;
    time(&current);
    tm * now = localtime(&current);

    //issue: return is wrong: fix
    int urre = 2 + now->tm_mon;

    if ((then <= 0) || (then > 12))
        return 0; //Invalid month value
    if ((yr == 1) || (yr == 2))
    {
        if (then < urre)
            return 9; //Invalid month in current year
        else if (then == urre)
        {
            if (then == 2)
                return 8; //Current month (feburary)
            else
                return 7; //Current month (not feburary)
        }
        else
        {
            if (then == 2)
                return 1; //month is feburary
            else if ((then == 4) || (then == 6) || (then == 9) || (then == 11))
                return 2; //month has 30 days
            else
                return 3; //month has 31 days
        }
    }
    else
    {
        if (then == 2)
            return 1; //month is feburary
        else if ((then == 4) || (then == 6) || (then == 9) || (then == 11))
            return 2; //month has 30 days
        else
            return 3; //month has 31 days
    }
}


int conferenceCheck::checkDay(int first, int mon, int yr)
{
    time_t current;
    time(&current);
    tm * now = localtime(&current);

    //issue: return is wrong: fix
    int rent = now->tm_mday;

    if ((first <= 0) || (first > 31))
        return 0; //Invalid day
    if ((yr == 1) || (yr == 2))
    {
        if (mon == 8)
        {
            if (first <= rent)
                return 9; //Invalid day in current year
            else
                return 1; //Valid day
        }
    }

    if ((mon == 1) && (yr == 3))
    {
        if (first > 29)
            return 0; //Invalid day
    }
    else if ((mon == 1) && (yr == 4))
    {
        if (first > 28)
            return 0;
    }
    else if (mon == 2)
    {
        if (first > 30)
            return 0;
    }

    return 1;
}


void conferenceCheck::checkDates(int& day, int& month, int& year)
{
    int checkOne = 0, checkTwo = 0, checkThree = 0;
    bool success = true;
    bool check = false;

    //For time visual check
    time_t current;
    time(&current);
    tm * now = localtime(&current);

    while (check == false)
    {
        //Check for year
        checkOne = checkYear(year);

        if (checkOne == 0)
        {
            while (checkOne == 0)
            {
                //Check
                cout << "Today's date is: " << now->tm_mday << "/" << 1 + now->tm_mon << "/" << 1900 + now->tm_year << endl;
                cout << "Invalid year. Please enter a valid year (number): ";
                cin >> year;
                checkOne = checkYear(year);
            }
        }

        //Check for month
        checkTwo = checkMonth(month, checkOne);

        if (checkTwo == 0 || checkTwo == 9)
        {
            while (checkTwo == 0 || checkTwo == 9)
            {
                //Check
                cout << "Today's date is: " << now->tm_mday << "/" << 1 + now->tm_mon << "/" << 1900 + now->tm_year << endl;
                cout << "Invalid month. Please enter a valid month (number): ";
                cin >> month;
                checkTwo = checkMonth(month, checkOne);
            }
        }

        //Check for day
        checkThree = checkDay(day, checkTwo, checkOne);

        if (checkThree == 0 || checkThree == 9)
        {
            while(checkThree == 0 || checkThree == 9)
            {
                //Check
                cout << "Today's date is: " << now->tm_mday << "/" << 1 + now->tm_mon << "/" << 1900 + now->tm_year << endl;
                cout << "Invalid day. Please enter a valid day (number): ";
                cin >> day;
                checkThree = checkDay(day, checkTwo, checkOne);
            }

        }

        success = true;

        if (success == true)
        {
            check = true;
        }
        else
        {
            cout << "Unknown error. Re-enter required!" << endl;
            cout << "Re-enter day (number): ";
            cin >> day;
            cout << "Re-enter month (number): ";
            cin >> month;
            cout << "Re-enter year (number): ";
            cin >> year;
        }
    }
}


void conferenceCheck::setDate(int d, int m, int y, string desc)
{
    conference newCon;
    newCon.setConference(d, m, y, desc);
    newCon.transfer();
    return;
}


int conferenceCreate::create()
{
    SetWindow(80,50);

    bool select = false;
    while (select == false)
    {
        int one = 0; //day
        int two = 0; //month
        int three = 0; //year
        string four; //description
        four.clear();
        cout << "Please enter the day (number) of the conference: ";
        cin >> one;
        cout << "Please enter the month (number) of the conference: ";
        cin >> two;
        cout << "Please enter the year (number) of the conference: ";
        cin >> three;

        conferenceCheck check;
        check.checkDates(one, two, three);

        cout << "Please enter the description of the conference (Press enter when finished): " << endl;
        cin.ignore();
        getline(cin, four, '\n');

        int next;
        cout << "Are these details correct?" << endl;
        cout << "Date: " << one << "/" << two << "/" << three << endl;
        cout << "Description: " << endl;
        cout << four << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "3. Cancel" << endl;
        cin >> next;

        if (next == 1)
            select = true;
        else if (next == 2)
            select = false;
        else if (next == 3)
        {
            cout << "Conference creation unsuccessful!" << endl;
            return 1;
        }
        else
        {
            while ((next != 1) && (next != 2) && (next != 3))
            {
                cout << "Are these details correct?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "3. Cancel" << endl;
                cin >> next;

                if (next == 1)
                    select = true;
                else if (next == 2)
                    select = false;
                else if (next == 3)
                {
                    cout << "Conference creation unsuccessful!" << endl;
                    return 1;
                }
            }
        }
    }

    return 0;
}
