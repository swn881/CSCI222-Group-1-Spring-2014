#ifndef CONFERENCECREATECONTROLLER_H_INCLUDED
#define CONFERENCECREATECONTROLLER_H_INCLUDED

#include <string>
using namespace std;

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

#endif // CONFERENCECREATECONTROLLER_H_INCLUDED
