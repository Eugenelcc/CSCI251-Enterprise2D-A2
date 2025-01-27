#include <set> // Add this line
#include "./header/Assn2.h"
#include "./header/ShapeTwoD.h"
#include "./header/Square.h"
#include "./header/Rectangle.h"
#include "./header/Circle.h"
#include <iostream>
#include <vector>

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

        else if (userchoice == 2)
        {
            cout << "Option 2 selected" << endl;
            computeArea();
        }
        // OPTION 3  - Print Shape Report
        else if (userchoice == 3)
        {
            cout << "Option 3 selected" << endl;
            reportShapes();
        }

        // OPTION 4  - Sort Shape data
        else if (userchoice == 4)
        {
            cout << "Option 4 selected" << endl;
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

    if (ShapeName == "SQUARE")
    {
        vector<Point> vectorOfPoints;
        for (int i = 0; i < 4; ++i)
        {
            Point newPoint;
            cout << "Please enter x-ordinate of pt." << (i + 1) << ": ";
            cin >> newPoint.x;
            cout << "Please enter y-ordinate of pt." << (i + 1) << ": ";
            cin >> newPoint.y;
            cout << endl;
            vectorOfPoints.emplace_back(newPoint);
        }

        Square *square = new Square(warpSpace, shapes.size()); // true , id
        square->setPoints(vectorOfPoints);
        shapes.emplace_back(square);
    }
    else if (ShapeName == "RECTANGLE")
    {

        vector<Point> vectorOfPoints;
        for (int i = 0; i < 4; ++i)
        {
            Point newPoint;
            cout << "Please enter X-ordinate of pt." << (i + 1) << ": ";
            cin >> newPoint.x;
            cout << "Please enter Y-ordinate of pt." << (i + 1) << ": ";
            cin >> newPoint.y;
            cout << endl;
            vectorOfPoints.emplace_back(newPoint);
        }

        Rectangle *rectangle = new Rectangle(warpSpace, shapes.size()); // true , id
        rectangle->setPoints(vectorOfPoints);
        shapes.emplace_back(rectangle);
    }

    else if (ShapeName == "CIRCLE")
    {
        vector<Point> vectorOfPoints;
        int radius;
        Point newPoint; // << Array >>
        cout << "Please enter x-ordinate of center: ";
        cin >> newPoint.x;
        cout << "Please enter y-ordinate of center: ";
        cin >> newPoint.y;

        cout << "Please enter radius (Units) : ";
        cin >> radius;

        vectorOfPoints.emplace_back(newPoint);

        Circle *circle = new Circle(warpSpace, shapes.size(), radius, vectorOfPoints);
        shapes.emplace_back(circle);




    }

    else if (ShapeName == "CROSS")
    {
        // cout << "Cross coordinates are: (" << x[0] << ", " << y[0] << ")" << endl;
        // Cross *cross = new Cross(flag, shapes.size(), x[0], y[0], x[1], y[1]);
        // shapes.push_back(cross);
    }
    cout << "Entry Saved" << endl;
}

void computeArea()
{
    int numRecordsUpdataed = 0;
    for (size_t i = 0; i < shapes.size(); i++)
    {
        if (shapes[i]->areaHasBeenComputed == false)
        {
            shapes[i]->computeArea();
            shapes[i]->areaHasBeenComputed = true;
            numRecordsUpdataed++;
        }
    }
    cout << "\nComputation completed! (" << numRecordsUpdataed << " records were updated)" << endl;
}

void reportShapes()
{
    // Check if there are any shapes to report
    if (shapes.empty())
    {
        cout << "\nNo shapes available to report." << endl;
        return;
    }

    // Display the total number of records
    cout << "\nTotal number of records available = " << shapes.size() << endl;
    cout << endl;
    // Iterate through the shapes and display their details
    for (size_t i = 0; i < shapes.size(); i++)
    {
        cout << shapes[i]->toString();
        cout << endl;
    }
}
