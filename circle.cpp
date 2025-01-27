#include "./header/Assn2.h"
#include "./header/ShapeTwoD.h"
#include "./header/Square.h"
#include "./header/Rectangle.h"
#include "./header/Circle.h"


Circle::Circle(bool containsWarpSpace, int ShapeId, int radius, vector<Point> points)
    : ShapeTwoD("Circle", containsWarpSpace)
{
    this->setShapeId(ShapeId);
    this->radius = radius;
    this->setPoints(points);
}


double Circle::computeArea()
{
    double pi  = 3.14159;
    this-> area = pi * pow(this->radius, 2);
    return this->area;
};


bool Circle::isPointInShape(int x, int y) const{

    int centerX = this->ShapePoints[0].x;
    int centerY = this->ShapePoints[0].y;

    int distance = pow((x - centerX), 2) + pow((y - centerY), 2); //A* + b* = c*


    int radiusSquared = pow(this->radius, 2);
    if (distance < radiusSquared){
        return true;
    }
    return false;
}

bool Circle::isPointOnShape(int x, int y) const
{
    int centerX = this->ShapePoints[0].x;
    int centerY = this->ShapePoints[0].y;

    int distance = pow((x - centerX), 2) + pow((y - centerY), 2); //A* + b* = c*

    int radiusSquared = pow(this->radius, 2);
    if (distance == radiusSquared){
        return true;
    }
    return false;
}

 

string Circle::toString()
{
    string shapeTwoDData = ShapeTwoD::toString();
    ostringstream oss;

    oss << shapeTwoDData;
    oss << "Center: " << "(" << this->ShapePoints[0].x << "," << this->ShapePoints[0].y << ")" << endl;
    oss << "Radius: " << this->radius << endl;
    oss << endl;

    int centerX = this->ShapePoints[0].x;
    int centerY = this->ShapePoints[0].y;

    int minX = centerX - this->radius;
    int maxX = centerX + this->radius;
    int minY = centerY - this->radius;
    int maxY = centerY + this->radius;

    int count = 0;
    oss << "Point on perimeter: ";
    for (int i = minX; i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
        {
            if (isPointOnShape(i, j))
            {
                oss << "(" << i << "," << j << ")";
                count++;
            
            }
        }
    }
    if (count == 0)
    {
        oss << "None";
        
    }


    count =0;
     oss << endl << "Points within shape: ";
    for (int i = minX; i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
        {
            if (isPointInShape(i, j))
            {
                oss << "(" << i << "," << j << "), ";
                count++;
            }
        }
    }
    if (count == 0)
    {
        oss << "None";
    }
     oss << endl;
    return oss.str();



 
}