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



int ShapeTwoD::getShapeId() 
{
  return this->ShapeId;
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
    this->ShapePoints = points;
}

// compute area

double ShapeTwoD ::computeArea()
{
    return area;
}

string ShapeTwoD::toString()
{ 
    ostringstream oss;
    oss << "Shape[" << getShapeId() << "]" << endl;
    oss << "Name: " << getName() << endl
        << "Special Type: " << (getContainsWarpSpace() ? "WS" : "NS") << endl
        << "Area: " << RoundToDecimalPlaces(getArea(),2) << " units square" << endl;  
    return oss.str();
}

double ShapeTwoD::RoundToDecimalPlaces(double value, int decimalPlaces) {
    double scale = std::pow(10.0, decimalPlaces);
    return std::round(value * scale) / scale;
}
 