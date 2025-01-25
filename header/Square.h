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
private:
    bool containsWarpSpace;
    int PositionX;
    int PositionY;
    int Length;

public:
    Square(bool ContainsWarpSpace, int Id, int x, int y, int Length);
    double computeArea() override;
   bool isPointInShape(int x, int y) const override;
  bool isPointOnShape(int x, int y) const override;

    
    string toString();
};

#endif
