#ifndef SQUARE_H
#define SQUARE_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>

#include "ShapeTwoD.h"

using namespace std;

class Square : public ShapeTwoD
{
public:
    Square(bool ContainsWarpSpace, int ShapeId);
    double computeArea() override;
    bool isPointInShape(int x, int y) const override;
    bool isPointOnShape(int x, int y) const override;

    string toString() override;
};

#endif
