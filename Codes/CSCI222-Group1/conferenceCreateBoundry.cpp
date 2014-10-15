#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <ctime>
#include <sstream>
#include <conio.h>
#include "conferenceCreateBoundry.h"
#include "conferenceCreateController.h"
using namespace std;

int conferenceCreate::create()
{

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
                }
            }
        }
    }
    return 0;
}
