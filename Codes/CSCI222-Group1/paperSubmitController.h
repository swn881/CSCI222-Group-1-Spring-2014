#ifndef PAPERSUBMITCONTROLLER_H_INCLUDED
#define PAPERSUBMITCONTROLLER_H_INCLUDED

#include <string>
using namespace std;

class paperCheck
{
private:

public:
    paperCheck(){};
    ~paperCheck(){};
    void setData(string, string, vector<string>, vector<string>, vector<string>, vector<string>, int);
    void checkFile(string&);

};

#endif // PAPERSUBMITCONTROLLER_H_INCLUDED
