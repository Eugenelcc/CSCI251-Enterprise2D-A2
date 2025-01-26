#include "./header/Assn2.h"
#include "./header/ShapeTwoD.h"
#include "./header/Square.h"

// initialize constructor

Square::Square(bool containsWarpSpace, int ShapeId)
    : ShapeTwoD("Square", containsWarpSpace)
{
    this->setShapeId(ShapeId);
}

double Square::computeArea()
{
    // cout << this->ShapePoints.size() << endl;
    int minX = INT_MAX, maxX = INT_MIN;
    for (Point p : this->ShapePoints)
    {
        if (p.x < minX)
        {
            minX = p.x;
        }
        if (p.x > maxX)
        {
            maxX = p.x;
        }
    }
    int length = maxX - minX;
    area = length * length;
    return area;
}

bool Square::isPointInShape(int x, int y) const
{

    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;

    for (Point p : this->ShapePoints)
    {
        if (p.x < minX && p.y < minY)
        {
            minX = p.x;
            minY = p.y;
        }
        if (p.x > maxX && p.y > maxY)
        {
            maxX = p.x;
            maxY = p.y;
        }
    }

    if (x > minX && x < maxX && y > minY && y < maxY)
    {
        return true;
    }
    return false;

    //     if (x > PositionX && x < PositionX + Length && y > PositionY && y < PositionY + Length)
    //     {
    //         return true;
    //     }
    //     return false;
}

bool Square::isPointOnShape(int x, int y) const
{

    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;

    for (Point p : this->ShapePoints)
    {
        if (p.x < minX && p.y < minY)
        {
            minX = p.x;
            minY = p.y;
        }
        if (p.x > maxX && p.y > maxY)
        {
            maxX = p.x;
            maxY = p.y;
        }
    }

    if ((x == minX || x == maxX) && (y >= minY && y <= maxY))
    {
        return true;
    }
    if ((y == minY || y == maxY) && (x >= minX && x <= maxX))
    {
        return true;
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
    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;

    for (Point p : this->ShapePoints)
    {
        if (p.x < minX && p.y < minY)
        {
            minX = p.x;
            minY = p.y;
        }
        if (p.x > maxX && p.y > maxY)
        {
            maxX = p.x;
            maxY = p.y;
        }
    }

    for (int i = minX; i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
        {
            if (isPointOnShape(i, j))
            {
                // minX, minY - // BOTTOM LEFT
                // minX, maxY - // TOP LEFT
                // maxX, minY - // BOTTOM RIGHT
                // maxX, maxY - // TOP RIGHT
                if ((i == minX && j == minY) ||
                    (i == minX && j == maxY) ||
                    (i == maxX && j == minY) ||
                    (i = maxX && j == maxY))
                    continue;
            }
            oss << "(" << i << ", " << j << "), ";
        }
    }
}

// if (count == 0)
//     oss << "none!\n";
// else
//     oss << "\b\b \n";
// oss << endl;

// oss << "Points within shape: " << endl;
// count = 0;

// for (int i = PositionX; i <= PositionX + Length; i++)
// {
//     for (int j = PositionY; j <= PositionY + Length; j++)
//     {
//         if (isPointInShape(i, j))
//         {
//             oss << "(" << i << ", " << j << "), ";
//             count++;
//         }
//     }
// }
// if (count == 0)
//     oss << "none!\n";
// else
//     oss << "\b\b \n";

// return oss.str();
return "";
}