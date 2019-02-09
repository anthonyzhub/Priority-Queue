#include <iostream>
#include <cmath>
#include "LPQ.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Point2D
{
private:
    double x, y;
    
public:
    Point2D(double xcoord, double ycoord)
    {
        x = xcoord;
        y = ycoord;
    }
    
    double getX() const { return x; }
    double getY() const { return y; }
    
    friend ostream& operator<<(ostream& out, const Point2D& q)
    {
        out << q.getX() << " " << q.getY();
        return out;
    }
};

class LeftRight
{
public:
    bool operator()(const Point2D& p, const Point2D& q) const
    {
        return p.getX() < q.getX();
    }
};

class OriginDistance
{
public:
    
    bool operator()(const Point2D& p) const
    {
        return sqrt(pow(p.getX(), 2) + pow(p.getY(), 2));
    }
};

int main(int argc, char** argv)
{
    OriginDistance od;
    
    ListPriorityQueue<Point2D, LeftRight> PList;
    PList.insert(Point2D(2,5));
    PList.insert(Point2D(3,2));
    PList.insert(Point2D(1,9));

    while (!PList.empty())
    {
        cout << PList.min() << endl;
        cout<<"Distance from Origin: "<<od(PList.min())<<endl;
        PList.removeMin();
    }
}
