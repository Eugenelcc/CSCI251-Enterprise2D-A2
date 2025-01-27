#include "./header/Assn2.h"
#include "./header/ShapeTwoD.h"
#include "./header/Square.h"
#include "./header/Rectangle.h"
#include "./header/Circle.h"
#include "./header/Cross.h"

Cross::Cross(bool ContainsWarpSpace, int ShapeId)
    : ShapeTwoD("Cross", ContainsWarpSpace), bigRectangle(false, -1),topLeftRectangle(false,  -1), topRightRectangle(false,  -1), bottomLeftRectangle(false,  -1), bottomRightRectangle(false,  -1)
{
    this->setShapeId(ShapeId);
}


double Cross::computeArea()
{
    //bigRectangle
    double bigRectangleArea = this->bigRectangle.computeArea();

    //topLeftRectangle
    double topLeftRectangleArea = this->topLeftRectangle.computeArea();
    //topRightRectangle
    double topRightRectangleArea = this->topRightRectangle.computeArea();
    //bottomLeftRectangle
    double bottomLeftRectangleArea = this->bottomLeftRectangle.computeArea();
    //bottomRightRectangle
    double bottomRightRectangleArea = this->bottomRightRectangle.computeArea();

    
    this->area = bigRectangleArea - (topLeftRectangleArea + topRightRectangleArea + bottomLeftRectangleArea + bottomRightRectangleArea);


    return this->area;
}

void Cross::setPoints(vector<Point> points) {
   
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


    //cout<<"Check for min and max... Cleared"<<endl;

    // Big Rectangle
    this->bigRectangle = Rectangle(false,  -1);
    this->bigRectangle.setPoints({
        Point {minX, minY}, //Bottom left
        Point {minX, maxY}, //Top left
        Point {maxX, minY}, //Bottom right
        Point {maxX, maxY} //Top right
    });


      //cout<<"Check for Big Rectangle... Cleared"<<endl;

    vector<Point>TopCrossPoint, BottomCrossPoint, LeftCrossPoint, RightCrossPoint;
    for(Point p : this->ShapePoints){
        if(p.y == maxY){
        TopCrossPoint.emplace_back(p);
        }
        if(p.x == minX){
        LeftCrossPoint.emplace_back(p);
        }
        if(p.y == minY){
            BottomCrossPoint.emplace_back(p);
        }
        if(p.x == maxX){
            RightCrossPoint.emplace_back(p); // << 2 Coord >>
        }
    }

       //cout<<"Check for Cross Points... Cleared"<<endl;

    // Comparing min Point value
    sort(TopCrossPoint.begin(), TopCrossPoint.end(), [](Point a, Point b) { return a.x < b.x; });
    sort(BottomCrossPoint.begin(), BottomCrossPoint.end(), [](Point a, Point b) { return a.x < b.x; });
    sort(LeftCrossPoint.begin(),LeftCrossPoint.end() , [] (Point a , Point b) { return a.y < b.y; });
    sort(RightCrossPoint.begin(), RightCrossPoint.end(), [] (Point a , Point b) { return a.y < b.y; }); 
    




      // cout<<"Check for Comparitors... Cleared"<<endl;

    cout <<TopCrossPoint.size() << " " << BottomCrossPoint.size() << " " << LeftCrossPoint.size() << " " << RightCrossPoint.size() << endl;


    
    //TopLeftRectangle
    this->topLeftRectangle = Rectangle(false,  -1);
    this->topLeftRectangle.setPoints({
        TopCrossPoint[0],
        Point {minX, maxY},
        LeftCrossPoint[1],
        Point{TopCrossPoint[0].x,LeftCrossPoint[1].y}
    });

  // cout<<"Check for TopLeftRect... Cleared"<<endl;

    //TopRightRectangle
    this-> topRightRectangle = Rectangle(false,  -1);
    this-> topRightRectangle.setPoints({
        TopCrossPoint[1],
        Point{maxX, maxY},
        RightCrossPoint[1],
        Point{TopCrossPoint[1].x, RightCrossPoint[1].y}
    });
  //  cout<<"Check for TopRightRect... Cleared"<<endl;
    


    //BottomLeftRectangle
    this->bottomLeftRectangle = Rectangle(false,  -1);
    this->bottomLeftRectangle.setPoints({
        BottomCrossPoint[0],
        Point{minX, minY},
        LeftCrossPoint[0],
        Point{BottomCrossPoint[0].x, LeftCrossPoint[0].y}
    });

  //  cout << "Check for BottomLeftRect... Cleared" << endl;
    
    //BottomRightRectangle
    this->bottomRightRectangle = Rectangle(false,-1);
    this->bottomRightRectangle.setPoints({
        BottomCrossPoint[1],
        Point{maxX, minY},
        RightCrossPoint[0],
        Point{BottomCrossPoint[1].x, RightCrossPoint[0].y}
    });

   //  cout << "Check for BottomRight Rect... Cleared" << endl;
}



bool Cross::isPointInShape(int x, int y) const
{
    //Check if point is in any of the rectangles
   
    return true ;
}

bool Cross::isPointOnShape(int x, int y) const
{
    return true;
}

string Cross::toString(){
    string shapeTwoDData = ShapeTwoD::toString();
    ostringstream oss;

    oss << shapeTwoDData;
    oss << "Vertices: " << endl;
    for(int i = 0 ; i < 12 ; i++){
        oss << "Point[" << i+1 << "] " << "  (" << this->ShapePoints[i].x << "," << this->ShapePoints[i].y << ")" << endl;
    }
    oss<< endl;

 

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
    oss << "Point on perimeter: ";
    for (int i = minX; i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
        {
            if (isPointOnShape(i, j))
            {
           
            
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