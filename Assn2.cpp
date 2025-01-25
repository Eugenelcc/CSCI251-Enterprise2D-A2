#include "./header/Assn2.h"

// Global variable
string student_Name = "Eugene Lay Chai Chun";
string student_ID = "907083";
string divider = "=========================================";


int main(){
    return 0;
}






//Algorithm
int displaymenu()
{
    int userchoice;

    while (true)
    {
        cout << '\n'
             << divider << endl;
        cout << "Student ID: " << student_ID << endl;
        cout << "Student Name: " << student_Name << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Welcome to Assn2 program!" << endl
             << '\n';
        cout << "1)\tInput Sensor Data " << endl;

        cout << "2)\tCompute area (for all records)" << endl;
        cout << "3)\tPrint Shape Report" << endl;
        cout << "4)\tSort Shape data" << endl;
        cout << "5)\tExit" << endl;

        cout << divider << endl;

        cout << "Please enter your choice (1-5): ";
        while (!(cin >> userchoice) || userchoice < 1 || userchoice > 5)
        {
            cout << "Invalid input. Please enter a number between 1 and 5: ";
            cin.clear();             // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore the rest of the input
        }

        // OPTION 1  - Read and process config file
        if (userchoice == 1)
        {
            cout << "[Input senor data]" << endl;
            try
            {

                cout << endl;
            }
            catch (const std::exception &e)
            {
                cout << "Error: " << e.what() << endl;
                cout << "Returning to display menu." << endl;
            }
        }
        // OPTION 2
        else if ((userchoice == 2))
        {
        }
        else if ((userchoice == 3))

        {
        }
        else if ((userchoice == 4)) // Cloud LMH
        {
        }
        else if ((userchoice == 5))
        {
            break;
        }
        else
        {
            cout << "Okay that's it ";
        }
    };
    return 0;
}








