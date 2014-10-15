#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <ctime>
#include <sstream>
#include <conio.h>
#include "conferenceCreateController.h"
#include "conferenceCreate.h"
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
    fout.open("System\\Conference\\Conference.txt");
    fout << "Date: " << day << "/" << month << "/" << year << endl;
    fout << "Description: " << endl;
    fout << description << endl;
    fout << endl;
    fout.close();
}
