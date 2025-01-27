#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>


#include "ShapeTwoD.h"

using namespace std;

class Circle : public ShapeTwoD
{
    private:
    int radius;

    public:
    Circle(bool ContainsWarpSpace, int ShapeId, int radius , vector<Point> points);
    double computeArea() override;
    bool isPointInShape(int x, int y) const override;
    bool isPointOnShape(int x, int y) const override;

    string toString() override;


};


#endif