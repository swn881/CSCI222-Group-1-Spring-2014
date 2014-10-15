#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <conio.h>
#include "paperSubmitBoundry.h"
#include "paperSubmitController.h"
#include "paperSubmitEntity.h"
using namespace std;

void paperCheck::setData(string in, string descr, vector<string> authorF, vector<string> authorL, vector<string> email, vector<string> uni, int con)
{
	paperSubmit nPaper;
	nPaper.setValues(in, descr, authorF, authorL, email, uni, con);
	nPaper.transferFile();
}

void paperCheck::checkFile(string& directory)
{
	ifstream fin;
	fin.open(directory.c_str(), ios::binary);

	//Check to see if file exists
	if (!fin.good())
	{
		//for checking
		fin.close();
		bool good = false;
		while (good == false)
		{
				cout << "Invalid file/directory!" << endl;
				cout << "Please enter the file directory and file:" << endl;
				getline(cin, directory);
				fin.open(directory.c_str(), ios::binary);
				if(fin.good())
					good = true;
				else
					fin.close();
		}
	}
	fin.close();
}
