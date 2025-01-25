#include "./header/Assn2.h"
#include "./header/ShapeTwoD.h"
#include "./header/Square.h"

// initialize constructor

Square::Square(bool ContainsWarpSpace, int Id, int x, int y, int _Length)
    : ShapeTwoD("Square", ContainsWarpSpace), PositionX(x), PositionY(y), Length(_Length)
{
    setShapeId(Id);
    area = Length * Length;
    ShapePoints.push_back(Point{PositionX, PositionY});                   // Square -bottom-left
    ShapePoints.push_back(Point{PositionX + Length, PositionY});          // Square -bottom-right
    ShapePoints.push_back(Point{PositionX + Length, PositionY + Length}); // Square -top-right
    ShapePoints.push_back(Point{PositionX, PositionY + Length});          // Square -top-left
}

double Square::computeArea()
{
    return area;
}

bool Square::isPointInShape(int x, int y) const
{
    if (x > PositionX && x < PositionX + Length && y > PositionY && y < PositionY + Length)
    {
        return true;
    }
    return false;
}

bool Square::isPointOnShape(int x, int y) const
{
    if (x == PositionX || x == PositionX + Length)
    {
        if (y >= PositionY && y <= PositionY + Length)
        {
            return true;
        }
    }
    if (y == PositionY || y == PositionY + Length)
    {
        if (x >= PositionX && x <= PositionX + Length)
        {
            return true;
        }
    }
    return false;
}

string Square::toString()
{
    string shapeTwoDData = ShapeTwoD::toString();
    ostringstream oss;

    oss << shapeTwoDData;
    oss << "Vertices: " << endl;
    oss << "Point[0] " << "(" << this->ShapePoints[0].x << "," << this->ShapePoints[0].y << ")" << endl;
    oss << "Point[1] " << "(" << this->ShapePoints[1].x << "," << this->ShapePoints[1].y << ")" << endl;
    oss << "Point[2] " << "(" << this->ShapePoints[2].x << "," << this->ShapePoints[2].y << ")" << endl;
    oss << "Point[3] " << "(" << this->ShapePoints[3].x << "," << this->ShapePoints[3].y << ")" << endl;
    oss << endl;

    oss << "Point on perimeter: " << endl;
    
    int count = 0;
    for (int i = PositionX; i <= PositionX + Length; i++)
    {
        for (int j = PositionY; j <= PositionY + Length; j++)
        {
            if (isPointOnShape(i, j))
            {
                if ((i == PositionX && j == PositionY) ||
                    (i == PositionX && j == PositionY + Length) ||
                    (i == PositionX + Length && j == PositionY) ||
                    (i == PositionX + Length && j == PositionY + Length))
                {
                    continue;
                }
                oss << "(" << i << ", " << j << "), ";
            }
        }
    }

    if (count == 0)
        oss << "none!\n";
    else
        oss << "\b\b \n";
    oss << endl;

    oss << "Points within shape: " << endl;
    count = 0;

    for (int i = PositionX; i <= PositionX + Length; i++)
    {
        for (int j = PositionY; j <= PositionY + Length; j++)
        {
            if (isPointInShape(i, j))
            {
                oss << "(" << i << ", " << j << "), ";
                count++;
            }
        }
    }
    if (count == 0)
        oss << "none!\n";
    else
        oss << "\b\b \n";

    return oss.str();
}