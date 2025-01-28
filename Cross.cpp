#include "./header/Assn2.h"
#include "./header/ShapeTwoD.h"
#include "./header/Square.h"
#include "./header/Rectangle.h"
#include "./header/Circle.h"
#include "./header/Cross.h"
#include <algorithm>

Cross::Cross(bool ContainsWarpSpace, int ShapeId)
    : ShapeTwoD("Cross", ContainsWarpSpace), bigRectangle(false, -1), topLeftRectangle(false, -1), topRightRectangle(false, -1), bottomLeftRectangle(false, -1), bottomRightRectangle(false, -1)
{
    this->setShapeId(ShapeId);
}

double Cross::computeArea()
{
    // bigRectangle
    double bigRectangleArea = this->bigRectangle.computeArea();

    // topLeftRectangle
    double topLeftRectangleArea = this->topLeftRectangle.computeArea();
    // topRightRectangle
    double topRightRectangleArea = this->topRightRectangle.computeArea();
    // bottomLeftRectangle
    double bottomLeftRectangleArea = this->bottomLeftRectangle.computeArea();
    // bottomRightRectangle
    double bottomRightRectangleArea = this->bottomRightRectangle.computeArea();

    this->area = bigRectangleArea - (topLeftRectangleArea + topRightRectangleArea + bottomLeftRectangleArea + bottomRightRectangleArea);

    return this->area;
}

void Cross::setPoints(vector<Point> points)
{

    this->ShapePoints = points;

    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;
    for (Point p : this->ShapePoints)
    {
        minX = std::min(minX, p.x);
        minY = std::min(minY, p.y);

        maxX = std::max(maxX, p.x);
        maxY = std::max(maxY, p.y);
    }

    // cout<<"Check for min and max... Cleared"<<endl;

    // Big Rectangle
    this->bigRectangle = Rectangle(false, -1);
    this->bigRectangle.setPoints({
        Point{minX, minY}, // Bottom left
        Point{minX, maxY}, // Top left
        Point{maxX, minY}, // Bottom right
        Point{maxX, maxY}  // Top right
    });

    // cout<<"Check for Big Rectangle... Cleared"<<endl;

    // vector<Point> TopCrossPoint, BottomCrossPoint, LeftCrossPoint, RightCrossPoint;
    for (Point p : this->ShapePoints)
    {
        if (p.y == maxY)
        {
            TopCrossPoint.emplace_back(p);
        }
        if (p.x == minX)
        {
            LeftCrossPoint.emplace_back(p);
        }
        if (p.y == minY)
        {
            BottomCrossPoint.emplace_back(p);
        }
        if (p.x == maxX)
        {
            RightCrossPoint.emplace_back(p); // << 2 Coord >>
        }
    }

    // cout<<"Check for Cross Points... Cleared"<<endl;

    // Comparing min Point value
    sort(TopCrossPoint.begin(), TopCrossPoint.end(), [](Point a, Point b)
         { return a.x < b.x; });
    sort(BottomCrossPoint.begin(), BottomCrossPoint.end(), [](Point a, Point b)
         { return a.x < b.x; });
    sort(LeftCrossPoint.begin(), LeftCrossPoint.end(), [](Point a, Point b)
         { return a.y < b.y; });
    sort(RightCrossPoint.begin(), RightCrossPoint.end(), [](Point a, Point b)
         { return a.y < b.y; });

    // cout<<"Check for Comparitors... Cleared"<<endl;

    // cout << TopCrossPoint.size() << " " << BottomCrossPoint.size() << " " << LeftCrossPoint.size() << " " << RightCrossPoint.size() << endl;

    // TopLeftRectangle
    this->topLeftRectangle = Rectangle(false, -1);
    this->topLeftRectangle.setPoints({TopCrossPoint[0],
                                      Point{minX, maxY},
                                      LeftCrossPoint[1],
                                      Point{TopCrossPoint[0].x, LeftCrossPoint[1].y}});

    // cout<<"Check for TopLeftRect... Cleared"<<endl;

    // TopRightRectangle
    this->topRightRectangle = Rectangle(false, -1);
    this->topRightRectangle.setPoints({TopCrossPoint[1],
                                       Point{maxX, maxY},
                                       RightCrossPoint[1],
                                       Point{TopCrossPoint[1].x, RightCrossPoint[1].y}});
    //  cout<<"Check for TopRightRect... Cleared"<<endl;

    // BottomLeftRectangle
    this->bottomLeftRectangle = Rectangle(false, -1);
    this->bottomLeftRectangle.setPoints({BottomCrossPoint[0],
                                         Point{minX, minY},
                                         LeftCrossPoint[0],
                                         Point{BottomCrossPoint[0].x, LeftCrossPoint[0].y}});

    //  cout << "Check for BottomLeftRect... Cleared" << endl;

    // BottomRightRectangle
    this->bottomRightRectangle = Rectangle(false, -1);
    this->bottomRightRectangle.setPoints({BottomCrossPoint[1],
                                          Point{maxX, minY},
                                          RightCrossPoint[0],
                                          Point{BottomCrossPoint[1].x, RightCrossPoint[0].y}});

    //  cout << "Check for BottomRight Rect... Cleared" << endl;
}

bool Cross::isPointInShape(int x, int y) const
{
    bool CheckForBigRectangle = bigRectangle.isPointInShape(x, y); // Check for bigRectangle

    bool CheckForTopLeftRectangle = !topLeftRectangle.isPointInShape(x, y) && !topLeftRectangle.isPointOnShape(x, y);    // Check for TopLeftRectangle //
    bool CheckForTopRightRectangle = !topRightRectangle.isPointInShape(x, y) && !topRightRectangle.isPointOnShape(x, y); // Check for TopRightRectangle //

    bool CheckForBottomRightRectangle = !bottomRightRectangle.isPointInShape(x, y) && !bottomRightRectangle.isPointOnShape(x, y); // Check for bottomRightRectangle //
    bool CheckForBottomLeftRectangle = !bottomLeftRectangle.isPointInShape(x, y) && !bottomLeftRectangle.isPointOnShape(x, y);    // Check for BottomLeftRectangle //

    if (CheckForBigRectangle && CheckForTopLeftRectangle && CheckForTopRightRectangle && CheckForBottomRightRectangle && CheckForBottomLeftRectangle)
    {
        return true;
    }
    return false;
}

bool Cross::isPointOnShape(int x, int y) const
{
    // HELP
    const auto IsPointOnLine = [](Point lineStart, Point lineEnd, Point p) -> bool
    {
        // Check collinearity using cross product
        int crossProduct = (p.y - lineStart.y) * (lineEnd.x - lineStart.x) - (p.x - lineStart.x) * (lineEnd.y - lineStart.y);
        if (crossProduct != 0)
        {
            return false;
        }

        // Check if the point is within the bounding box of the segment
        if (p.x < std::min(lineStart.x, lineEnd.x) || p.x > std::max(lineStart.x, lineEnd.x) ||
            p.y < std::min(lineStart.y, lineEnd.y) || p.y > std::max(lineStart.y, lineEnd.y))
        {
            return false;
        }

        return true;
    };

    // TopCrossPoint, BottomCrossPoint, LeftCrossPoint, RightCrossPoint;

    //(1)Top of the cross -  TopCrossPoint[0] ----- TopCrossPoint[1]
    {
        Point TopCrossPoint0XY = TopCrossPoint[0];
        Point TopCrossPoint1XY = TopCrossPoint[1];
        if (IsPointOnLine(TopCrossPoint0XY, TopCrossPoint1XY, Point{x, y}))
        {
            return true;
        }
    }

    //(2)topLeft of the cross  - TopCrossPoint[0] ========= TopCrossPoint[0].X + LeftCrossPoint[1].Y

    {
        Point TopCrossPoint0XY = TopCrossPoint[0];
        Point TopCrossPoint0X_LeftCrossPoint1Y = {TopCrossPoint[0].x, LeftCrossPoint[1].y};
        if (IsPointOnLine(TopCrossPoint0XY, TopCrossPoint0X_LeftCrossPoint1Y, Point{x, y}))
        {
            return true;
        }
    }

    //(3)Leftside of the Cross -   TopCrossPoint[0].X + LeftCrossPoint[1].Y  ===============   LeftCrossPoint[1]
    {
        Point LeftCrossPoint1XY = LeftCrossPoint[1];
        Point TopCrossPoint0X_LeftCrossPoint1Y = {TopCrossPoint[0].x, LeftCrossPoint[1].y};
        if (IsPointOnLine(LeftCrossPoint1XY, TopCrossPoint0X_LeftCrossPoint1Y, Point{x, y}))
        {
            return true;
        }
    }

    //(4)Left of the cross  -- LeftCrissPoint[1] ==========    LeftCrossPoint[0]
    {
        Point LeftCrossPoint1XY = LeftCrossPoint[1];
        Point LeftCrossPoint0XY = LeftCrossPoint[0];
        if (IsPointOnLine(LeftCrossPoint1XY, LeftCrossPoint0XY, Point{x, y}))
        {
            return true;
        }
    }

    //(5)Bottom Left of the cross  --- LeftCrossPoint[0] ========= BottomCrossPoint[0].X , LeftCrossPoint[0].Y
    {
        Point LeftCrossPoint0XY = LeftCrossPoint[0];
        Point BottomCrossPoint0X_LeftCrossPoint0Y = {BottomCrossPoint[0].x, LeftCrossPoint[0].y};
        if (IsPointOnLine(LeftCrossPoint0XY, BottomCrossPoint0X_LeftCrossPoint0Y, Point{x, y}))
        {
            return true;
        }
    }

    //(6)Bottom Left Down of the Cross ----- BottomCrossPoint[0].X , LeftCrossPoint[0].Y ========= BottomCrossPoint[0]
    {
        Point BottomCrossPoint0XY = BottomCrossPoint[0];
        Point BottomCrossPoint0X_LeftCrossPoint0Y = {BottomCrossPoint[0].x, LeftCrossPoint[0].y};
        if (IsPointOnLine(BottomCrossPoint0XY, BottomCrossPoint0X_LeftCrossPoint0Y, Point{x, y}))
        {
            return true;
        }
    }

    //(7)Bottom of the Cross  ---- BottomCrossPoint[0] ========= BottomCrossPoint[1]
    {
        Point BottomCrossPoint0XY = BottomCrossPoint[0];
        Point BottomCrossPoint1XY = BottomCrossPoint[1];
        if (IsPointOnLine(BottomCrossPoint0XY, BottomCrossPoint1XY, Point{x, y}))
        {
            return true;
        }
    }

    //(8)Bottom Right Down of the Cross  --- BottomCrossPoint[1] ========= BottomCrossPoint[1].X , RightCrossPoint[0].Y
    {
        Point BottomCrossPoint1XY = BottomCrossPoint[1];
        Point BottomCrossPoint1X_RightCrossPoint0Y = {BottomCrossPoint[1].x, RightCrossPoint[0].y};
        if (IsPointOnLine(BottomCrossPoint1XY, BottomCrossPoint1X_RightCrossPoint0Y, Point{x, y}))
        {
            return true;
        }
    }

    //(9)Bottom Right Of the Cross ----- BottomCrossPoint[1].X , RightCrossPoint[0].Y ============ RightCrossPoint[0]
    {
        Point BottomCrossPoint1X_RightCrossPoint0Y = {BottomCrossPoint[1].x, RightCrossPoint[0].y};
        Point RightCrossPoint0XY = RightCrossPoint[0];

        if (IsPointOnLine(BottomCrossPoint1X_RightCrossPoint0Y, RightCrossPoint0XY, Point{x, y}))
        {
            return true;
        }
    }

    //(10)Right of the Cross ---- RightCrossPoint[0] ========== RightCrossPoint[1]
    {
        Point RightCrossPoint0XY = RightCrossPoint[0];
        Point RightCrossPoint1XY = RightCrossPoint[1];
        if (IsPointOnLine(RightCrossPoint0XY, RightCrossPoint1XY, Point{x, y}))
        {
            return true;
        }
    }

    //(11)Top Right of Cross -------  RightCrossPoint[1] ================= TopCrossPoint[1].X , RightCrossPoint[1].Y
    {
        Point RightCrossPoint1XY = RightCrossPoint[1];
        Point TopCrossPoint1X_RightCrossPoint1Y = {TopCrossPoint[1].x, RightCrossPoint[1].y};
        if (IsPointOnLine(RightCrossPoint1XY, TopCrossPoint1X_RightCrossPoint1Y, Point{x, y}))
        {
            return true;
        }
    }

    //(12)Top Right Up of Cross ----- TopCrossPoint[1].X , RightCrossPoint[1].Y ================= TopCrossPoint[1]
    {
        Point TopCrossPoint1XY = TopCrossPoint[1];
        Point TopCrossPoint1X_RightCrossPoint1Y = {TopCrossPoint[1].x, RightCrossPoint[1].y};
        if (IsPointOnLine(TopCrossPoint1XY, TopCrossPoint1X_RightCrossPoint1Y, Point{x, y}))
        {
            return true;
        }
    }

    return false;
}

string Cross::toString()
{
    string shapeTwoDData = ShapeTwoD::toString();
    ostringstream oss;

    oss << shapeTwoDData;
    oss << "Vertices: " << endl;
    for (int i = 0; i < 12; i++)
    {
        oss << "Point[" << i + 1 << "] " << "  (" << this->ShapePoints[i].x << "," << this->ShapePoints[i].y << ")" << endl;
    }
    oss << endl;

    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;
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
    oss << "Point on perimeter: "; // point on shape
    for (int i = minX; i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
        {
            if (isPointOnShape(i, j))
            {
                auto shapeIterator = std::find(ShapePoints.cbegin(), ShapePoints.cend(), Point{i, j});
                bool pointFormsShape = shapeIterator != ShapePoints.cend();
                if (pointFormsShape)
                    continue;

                oss << "(" << i << ", " << j << "), ";
                count++;
            }
        }
    }
    if (count == 0)
    {
        oss << "None";
    }

    count = 0;
    oss << endl
        << "Points within shape: "; // Point in Shape
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
