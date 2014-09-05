#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <sstream>
#include <conio.h>

using namespace std;

void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
    SetConsoleTitle("CONFERENCE MANAGEMENT SYSTEM v1.0"); // Change title for Console Window.
}



int main()
{
	/***********************************************************************/

    SetWindow(80,50);\

	/***********************************************************************/

    system("cmd"    "dir/w");
	system("color 17"); //This is for the background colour of command prompt
	system("cls");

	//Declare Area
	int choice; //Option for main window
	char* dt; //String for Time
	bool checkOption; //Check for "TRUE" on options

	checkOption = false;

	do
	{
	    // current date/time based on current system
        time_t now = time(0);
        // convert now to string form
        dt = ctime(&now);
        string DateTime(dt); //For conversion from char* to string

		cout << "Version 1.0                                             " << DateTime;
		cout << "\n\n";
		cout << "\t\t  ********************************************  \n";
        cout << "\t\t ********************************************** \n";
		cout << "\t\t****                                        ****\n";
		cout << "\t\t***                                          ***\n";
		cout << "\t\t**     CCCCCC    MM           MM   SSSSSS     **\n";
		cout << "\t\t**    C      C   MMM         MMM  S      S    **\n";
		cout << "\t\t**   C           M MM       MM M   S          **\n";
		cout << "\t\t**   C           M  MM     MM  M    S         **\n";
		cout << "\t\t**   C           M   M     M   M     SSS      **\n";
		cout << "\t\t**   C           M   MM   MM   M        S     **\n";
		cout << "\t\t**   C           M    M   M    M         S    **\n";
		cout << "\t\t**    C      C   M     M M     M   S      S   **\n";
		cout << "\t\t**     CCCCCC    M      M      M    SSSSSS    **\n";
		cout << "\t\t***                                          ***\n";
		cout << "\t\t****                                        ****\n";
        cout << "\t\t ********************************************** \n";
        cout << "\t\t  ********************************************  \n";
		cout << "\n\n\n\n";

		cout << "                               Welcome  To  C M S\n\n\n";
		cout << "-------------------------------------------------------------------------------\n";
		cout << "------------------------       ##################       -----------------------\n";
		cout << "---------------                #                #                --------------\n";
		cout << "---------                      #  0. About CMS  #                      --------\n";
		cout << "----                           #  1. Login      #                           ---\n";
		cout << "-                              #  2. Register   #                             -\n";
		cout << "----                           #  3. Help       #                           ---\n";
		cout << "---------                      #  4. Exit       #                      --------\n";
		cout << "---------------                #                #                --------------\n";
		cout << "------------------------       ##################       -----------------------\n";
        cout << "-------------------------------------------------------------------------------\n\n";
		cout << "              >>                                                    <<\n";
		cout << "              >>>                                                  <<<\n";
		cout << "              >>>>                                                <<<<\n";
		cout << "              >>>>>                                              <<<<<\n";
		cout << "              >>>>                                                <<<<\n";
		cout << "              >>>                                                  <<<\n";
        cout << "              >>                                                    <<\n";
        cout << "                        Please enter your option ( 0-4 ): ";

        char input;

        //Input character to buffer
        input = getch();
        //accept any valuea

        putch(input);

        //Convert char to to integer;
        choice = input - '0';

		/*if(cin.fail())
		{
			cin.clear();
			cin.ignore(100,'\n');
			checkOption = false;
			cout << "Invalid Option!!! Please select between ( 0-4 ) \n";
			system("pause");
			system("cls");
		}*/

		if( (choice < 0) || (choice > 4) )
		{
			checkOption = false;
			cout << "\nInvalid Option!!! Please select between ( 0-4 ) \n";
			system("pause");
			system("cls");

		}

		else if( choice == 4 )
		{
			cout << "\nThank you for using BMS system!!!!\n";
			cout << "GoodBye!!!\n";
			checkOption = true;
			system("pause");
			system("cls");
		}

		else
		{
			checkOption = true;

			switch(choice)
			{
				case '0': system("color E5"); //This is for the background colour of command prompt

				    //Running Functions or Classes

				break;

				case '1': system("color E5"); //This is for the background colour of command prompt
				    //Running Functions or Classes

				break;

				case '2': system("color E5"); //This is for the background colour of command prompt
				    //Running Functions or Classes


				break;

				case '3': system("color E5"); //This is for the background colour of command prompt
				    //Running Functions or Classes

				break;
			}
		}

	}while(checkOption != true);
}


void _Option1()
{

}

void _Option2()
{

}

void _Option3()
{

}

