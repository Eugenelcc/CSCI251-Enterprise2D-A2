#include "./header/Assn2.h"
#include "./header/ShapeTwoD.h"
#include "./header/Square.h"
#include "./header/Rectangle.h"

Rectangle::Rectangle(bool containsWarpSpace, int ShapeId)
    : ShapeTwoD("Rectangle", containsWarpSpace)
{
    this->setShapeId(ShapeId);
}


double Rectangle::computeArea()
{
    int minX = 9999, maxX = -9999;
    int minY = 9999, maxY = -9999;

    for (Point p : this->ShapePoints)
    {
        minX = std::min(minX, p.x);
        minY = std::min(minY, p.y);

        maxX = std::max(maxX, p.x);
        maxY = std::max(maxY, p.y);
    }

    int length = maxX - minX;
    int width = maxY - minY;
    this->area = length * width;
    return this->area;
}


bool Rectangle::isPointInShape(int x, int y) const
{
    int minX = 9999, maxX = -9999;
    int minY = 9999, maxY = -9999;

    for (Point p : this->ShapePoints)
    {
        minX = std::min(minX, p.x);
        minY = std::min(minY, p.y);

        maxX = std::max(maxX, p.x);
        maxY = std::max(maxY, p.y);
    }

    if (x > minX && x < maxX && y > minY && y < maxY)
    {
        return true;
    }
    return false;
}

bool Rectangle::isPointOnShape(int x, int y) const
{
    int minX = 9999, maxX = -9999;
    int minY = 9999, maxY = -9999;

    for (Point p : this->ShapePoints)
    {
        minX = std::min(minX, p.x);
        minY = std::min(minY, p.y);

        maxX = std::max(maxX, p.x);
        maxY = std::max(maxY, p.y);
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



string Rectangle::toString()
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

    int minX = 9999, maxX = -9999;
    int minY = 9999, maxY = -9999;
    for (Point p : this->ShapePoints)
    {

        // if (p.x < minX) {
        //     minX = p.x;
        // }
        minX = std::min(minX, p.x);
        minY = std::min(minY, p.y);

        maxX = std::max(maxX, p.x);
        maxY = std::max(maxY, p.y);
    }
    // cout << "Min: " << minX << ", " << minY << endl;
    // cout << "Max: " << maxX << ", " << maxY << endl;

    int count = 0;
    oss << "Point on perimeter: ";
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
                    (i == maxX && j == maxY))
                    continue;
                oss << "(" << i << ", " << j << "), ";
                count++;
                // cout << "Count perim: " << count << endl;
            }
        }
    }
    if (count == 0)
    {
        oss << "None";
        
    }

    count = 0;
    oss << endl << "Points within shape: ";
    for (int i = minX; i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
        {
            if (isPointInShape(i, j))
            {
                oss << "(" << i << ", " << j << "), ";
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