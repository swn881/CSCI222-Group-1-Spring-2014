#ifndef CONFERENCECREATE_H_INCLUDED
#define CONFERENCECREATE_H_INCLUDED

#include <string>
using namespace std;

//Entity
class conference
{
private:
    int day;
    int month;
    int year;
    string description;

public:
    conference(){day = 0; month = 0; year = 0; description.clear();}
    ~conference(){day = 0; month = 0; year = 0; description.clear();}
    void setConference(int, int, int, string);
    void transfer();

};


//Controller
class conferenceCheck
{
public:
    conferenceCheck(){};
    ~conferenceCheck(){};
    int checkYear(int);
    int checkMonth(int, int);
    int checkDay(int, int, int);
    void checkDates(int&, int&, int&);
    void setDate(int, int, int, string);
};


//Boundry
class conferenceCreate
{
public:
    conferenceCreate(){};
    ~conferenceCreate(){};
    int create();
};

#endif // CONFERENCECREATE_H_INCLUDED
