#ifndef SHAPETWOD_H
#define SHAPETWOD_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <cmath>

using namespace std;

struct Point
{
    int x;
    int y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class ShapeTwoD
{
protected:
    string name;
    bool containsWarpSpace;
    int ShapeId;
    double area;
    vector<Point> ShapePoints;
    
public:
    bool areaHasBeenComputed  = false;

public:
    ShapeTwoD(string name, bool containsWarpSpace);

    string getName();
    bool getContainsWarpSpace();
    double getArea();
    int getShapeId();

    virtual double computeArea();
    virtual bool isPointInShape(int x, int y) const = 0;
    virtual bool isPointOnShape(int x, int y) const = 0;

    void setName(string name); // Shape
    void setContainsWarpSpace(bool containsWarpSpace);
    void setShapeId(int Id);

    
    virtual void setPoints(vector<Point> points);

    virtual string toString();
};

#endif