#include <set> // Add this line
#include "./header/Assn2.h"
#include "./header/ShapeTwoD.h"
#include "./header/Square.h"

// Global variable
string student_Name = "Eugene Lay Chai Chun";
string student_ID = "907083";
string divider = "=========================================";

vector<ShapeTwoD *> shapes;

int main()
{
    displayMenu();
    return 0;
}

int displayMenu()
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
        cout << "5)\tQuit" << endl;

        cout << divider << endl;

        cout << "Please enter your choice (1-5): ";
        while (!(cin >> userchoice) || userchoice < 1 || userchoice > 5)
        {
            cout << "Invalid input. Please enter a number between 1 and 5: ";
            cin.clear();             // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore the rest of the input
        }

        // OPTION 1  - Input Sensor Data
        if (userchoice == 1)
        {
            cout << "[Input sensor data]" << endl;
            try
            {
                displayInfo(); // Call the updated displayInfo function
            }
            catch (const std::exception &e)
            {
                cout << "Error: " << e.what() << endl;
                cout << "Returning to display menu." << endl;
            }
        }
        // Other options...
        else if (userchoice == 5)
        {
            break;
        }
    }
    return 0;
}

// Convert a string to uppercase
void toUpperCase(string &str)
{
    for (char &c : str)
    {
        c = toupper(c);
    }
}

void promptUserToPressEnterToContinue()
{
    cin.ignore(1000, '\n');
    string userInput = "";

    do
    {
        cout << "\nPress <Enter> to go back to main menu";
        getline(cin, userInput);
    } while (userInput.length() != 0);
    cout << endl;
}

void displayInfo()
{
    string ShapeName, SpecialType;
    bool warpSpace;

    cout << "\n[Input Sensor Data]" << endl;
    cout << "Please Enter Name of Shape: ";
    cin >> ShapeName;

    cout << "Please Enter Special Type: ";
    cin >> SpecialType;
    cout << endl;

    toUpperCase(ShapeName);
    toUpperCase(SpecialType);

    const set<string> validShapes = {"SQUARE", "RECTANGLE", "CIRCLE", "CROSS"};
    if (validShapes.find(ShapeName) == validShapes.end())
    {
        cout << "Invalid shape name. Please enter a valid shape name." << endl;
        return;
    }


// SPECIAL TYPE
    if (SpecialType == "WS")
        warpSpace = true;
    else if (SpecialType == "NS")
        warpSpace = false;
    else
    {
        cout << "Invalid special type. Please enter WS or NS." << endl;
        return;
    }

    int x[4], y[4];
    for (int i = 0; i < 4; ++i)
    {
        cout << "Please enter x-ordinate of pt." << (i + 1) << ": ";
        cin >> x[i];
        cout << "Please enter y-ordinate of pt." << (i + 1) << ": ";
        cin >> y[i];
        cout << endl;
    }

    int minX = *min_element(x, x + 4);
    int minY = *min_element(y, y + 4);
    int maxX = *max_element(x, x + 4);
    int maxY = *max_element(y, y + 4);

    if (ShapeName == "SQUARE")
    {
        cout << "Square coordinates are: (" << x[0] << ", " << y[0] << ")" << endl;
        //Square *square = new Square(warpSpace, shapes.size(), minX, minY, maxX - minX);
        //shapes.push_back(square);
    }
    else if (ShapeName == "RECTANGLE")
    {
        cout << "Rectangle coordinates are: (" << x[0] << ", " << y[0] << ")" << endl;
        // Rectangle *rectangle = new Rectangle(flag, shapes.size(), minX, minY, maxX - minX, maxY - minY);
        // shapes.push_back(rectangle);
    }
}
