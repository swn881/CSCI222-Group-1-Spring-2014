#ifndef CONFERENCECREATE_H_INCLUDED
#define CONFERENCECREATE_H_INCLUDED

#include <string>
using namespace std;

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


#endif // CONFERENCECREATE_H_INCLUDED
