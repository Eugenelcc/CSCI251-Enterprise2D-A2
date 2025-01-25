#include "./header/Assn2.h"
#include "./header/ShapeTwoD.h"

// initialize constructor
ShapeTwoD ::ShapeTwoD(string name, bool containsWarpSpace)
{
    this->name = name; // Shape Name ~ Circle/Rectangle/Cross
    this->containsWarpSpace = containsWarpSpace;   // WS/NS
    this->ShapeId = 0; // Shape ID
    this->area = 0; // Area
}

// getter
string ShapeTwoD ::getName()
{
    return name;
}

bool ShapeTwoD ::getContainsWarpSpace()
{
    return containsWarpSpace;
}

double ShapeTwoD ::getArea()
{
    return area;
}

// setter
void ShapeTwoD ::setName(string name)
{
    this->name = name;
}

void ShapeTwoD ::setContainsWarpSpace(bool containsWarpSpace)
{
    this->containsWarpSpace = containsWarpSpace;
}

void ShapeTwoD ::setShapeId(int Id)
{
    this->ShapeId = Id;
}

void ShapeTwoD ::setPoints(vector<Point> points)
{
    this->Shapepoints = points;
}

// compute area

double ShapeTwoD ::computeArea()
{
    return 0;
}

string ShapeTwoD::toString()
{
    ostringstream oss;
    oss << "Name: " << name << endl
        << "Special Type: " << (containsWarpSpace ? "WS" : "NS") << endl
        << "Area: " << area;
    return oss.str();
}
