#ifndef SHAPETWOD_H
#define SHAPETWOD_H
#include <string>


using namespace std;


class ShapeTwoD{
    protected:
    string name;
    bool containsWarpSpace; 

    public:
    ShapeTwoD(string name, bool containsWarpSpace);
    
    string getName();
    bool getContainsWarpSpace();
    string tostring();

    double computeArea();
    bool isPointIshape(int x , int y );
    bool isPoinOnShape(int x , int y);

    void setName(string name); //Shape
    void setContainsWarpSpace(bool containsWarpSpace);



};


#endif 