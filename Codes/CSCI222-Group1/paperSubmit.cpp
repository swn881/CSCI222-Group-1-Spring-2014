#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <conio.h>
#include "paperSubmitController.h"
#include "paperSubmit.h"
using namespace std;

void paperSubmit::setValues(string in, string descr, vector<string> authF, vector<string> authL, vector<string> em, vector<string> uni, int con)
{
	inDir = in;
	outDirTxt = "System/Papers/";
	outDirPdf = "System/Papers/";
	setID();
	string identity;
    stringstream oID;
    oID << id;
    identity = oID.str();
	outDirTxt.assign(identity);
	outDirTxt.assign(".txt");
	outDirPdf.assign(identity);
	outDirPdf.assign(".pdf");
	contributors = con;
	description = descr;
	authorFirst = authF;
	authorLast = authL;
	emails = em;
	universities = uni;
}


void paperSubmit::setID()
{
    int testID = 10000;
    string testFile = "System/Papers/";
    string tIn;
    stringstream tOut;
    tOut << testID;
    tIn = tOut.str();
    testFile.assign(tIn);
    testFile.assign(".txt");
    ifstream test;
    test.open(testFile.c_str());
    while (test.good())
    {
        test.close();
        testID++;
        testFile = "System/Papers/";
        tOut << testID;
        tIn = tOut.str();
        testFile.assign(".txt");
        ifstream test;
        test.open(testFile.c_str());
    }
    test.close();
    id = testID;
}



void paperSubmit::transferFile()
{
	ifstream fin;
	fin.open(inDir.c_str(), ios::binary);
    ofstream fout;
    fout.open(outDirPdf.c_str(), ios::binary);
    while(!fin.eof())
    {
        char buf[1000];
        fin.read(buf, sizeof(buf));
        fout.write(buf, sizeof(buf));
    }
    fin.close();
    fout.close();

    fout.open(outDirTxt.c_str());
    fout << "ID: " << id << "          ";
    fout << "Contributors: " << contributors << endl;
    fout << "Author Details:" << endl;
    int counting = authorFirst.size();
    while (counting != 0)
    {
        fout << "Name: " << authorFirst.back() << " " << authorLast.back() << endl;
        authorFirst.pop_back();
        fout << "Email: " << emails.back() << endl;
        emails.pop_back();
        fout << "University: " << universities.back() << endl;
        universities.pop_back();
        fout << endl;
        counting--;
    }
    fout << "Paper Details:" << endl;
    fout << description << endl;
    fout << endl;
    fout.close();
    cout << "Your paper ID number is: " << id << endl;
    cout << "Please do not forget this (maybe write it down), as it will help in identify what paper you to view/modify." << endl;
}
