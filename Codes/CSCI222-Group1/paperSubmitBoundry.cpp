#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <conio.h>
#include "paperSubmitController.h"
#include "paperSubmitBoundry.h"
using namespace std;

void paperView::submit()
{
    string newAuthorFirst, newAuthorLast, newEmail, newUni, descr, dir;
    vector<string> currAuthorFirst;
    vector<string> currAuthorLast;
    vector<string> currEmail;
    vector<string> currUni;
    int selection = 1;
    cout << "Enter the details of the paper (do not include authors):" << endl;
    getline(cin, descr);

    paperCheck newPaper;
    //for contributors
    int counting = 0;

    while(selection != 1)
    {
        cout << "Please enter the first name of the author: ";
        getline(cin, newAuthorFirst);
        cout << "Please enter the last name of the author: ";
        getline(cin, newAuthorLast);
        cout << "Please enter the author's email address: ";
        getline(cin, newEmail);
        cout << "Please enter the author's University (abbreviation is fine): ";
        getline(cin, newUni);
        cout << "Adding author to paper!" << endl;
        counting++;
        currAuthorFirst.push_back(newAuthorFirst);
        currAuthorLast.push_back(newAuthorLast);
        currEmail.push_back(newEmail);
        currUni.push_back(newUni);
        cout << "Author + details added to paper description!" << endl;
        newAuthorFirst.clear();
        newAuthorLast.clear();
        newEmail.clear();
        newUni.clear();

        cout << "Would you like to add a new author?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> selection;

		if (selection != 1 && selection != 2)
		{
			while (selection != 1 && selection != 2)
			{
				cout << "Invalid input! ";
				cout << "Would you like to add a new author?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cin >> selection;
			}
		}
    }

	cout << "Please enter the file directory (including file + extension) where your paper in pdf format is located" << endl;
	cout << "For example: if your file (example.pdf) is located in your My Documents folder in your user login the directory is:" << endl;
	cout << "C:/Users/(your user name)/My Documents/example.pdf" << endl;
	cout << "Please enter the file directory and file:" << endl;
	getline(cin, dir);
	newPaper.checkFile(dir);

	newPaper.setData(dir, descr, currAuthorFirst, currAuthorLast, currEmail, currUni, counting);

	cout << "Successful submission of paper!" << endl;
}
