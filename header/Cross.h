#ifndef CROSS_H
#define CROSS_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>
#include "Rectangle.h"

#include "ShapeTwoD.h"
using namespace std;


class Cross : public ShapeTwoD {
public:
    Cross(bool ContainsWarpSpace, int ShapeId);
    double computeArea() override;
    bool isPointInShape(int x, int y) const override;
    bool isPointOnShape(int x, int y) const override;

    string toString() override;
    void setPoints(vector<Point> points) override;
private:
    Rectangle bigRectangle;
    Rectangle topLeftRectangle, topRightRectangle, bottomLeftRectangle, bottomRightRectangle;
};






#endif