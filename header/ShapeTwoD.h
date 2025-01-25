#ifndef SHAPETWOD_H
#define SHAPETWOD_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

struct Point
{
    int x;
    int y;
};

class ShapeTwoD
{
protected:
    string name;
    bool containsWarpSpace;
    int ShapeId;
    double area;
    vector<Point> Shapepoints;

public:
    ShapeTwoD(string name, bool containsWarpSpace);

    string getName();
    bool getContainsWarpSpace();
    double getArea();

    

    virtual double computeArea();
    virtual bool isPoinOnShape(int x, int y);
    virtual bool isPointInShape(int x, int y);

    void setName(string name); // Shape
    void setContainsWarpSpace(bool containsWarpSpace);
    void setShapeId(int Id);
    void setPoints(vector<Point> points);

     virtual string toString();
};

int displaymenu();

#endif