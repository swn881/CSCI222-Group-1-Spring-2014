ifndef PAPERSUBMIT_H_INCLUDED
#define PAPERSUBMIT_H_INCLUDED

#include <string>
#include <vector>
using namespace std;


class paperSubmit
{
private:
    int id;
    int contributors;
    string inDir;
    string outDirTxt;
    string outDirPdf;
    string description;
    vector<string> authorFirst;
    vector<string> authorLast;
    vector<string> emails;
    vector<string> universities;

public:
    paperSubmit(){};
    ~paperSubmit(){inDir.clear(); outDirTxt.clear(); outDirPdf.clear(); description.clear(); authorFirst.clear(); authorLast.clear(); emails.clear(); universities.clear();};
    void setValues(string, string, vector<string>, vector<string>, vector<string>, vector<string>, int);
    void setID();
    void transferFile();

};

#endif // PAPERSUBMIT_H_INCLUDED
