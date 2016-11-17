#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int b, int c):  x(b), y(c) {}

    bool operator <(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
int cross(const Point &O, const Point &A, const Point &B)
{
    return (long)(A.x - O.x) * (B.y - O.y) - (long)(A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> createLowerConvexHull(vector<Point> & P)
{
    int n = P.size(), k = 0;
    vector<Point> H(2*n);

    // Sort points lexicographically
    sort(P.begin(), P.end());

    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
/*    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    } */
    H.resize(k);
    return H;
}

vector<Point> createUpperConvexHull(vector<Point> & P)
{
    int n = P.size(), k = 0;
    vector<Point> H(2*n);

    // Sort points lexicographically
    sort(P.begin(), P.end());

    // Build upper hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    
    H.resize(k);
    return H;
}

bool isIntersect(Point& p1, Point& p2, Point& p3, Point& p4)
{
    cout << "nerd: " << p1 << " , " << p2;
    cout << "not nerd: " << p3 << " , " << p4;
    // Store the values for fast access and easy
    // equations-to-code conversion
    float x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
    float y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;
     
    float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    // If d is zero, there is no intersection
    if (d == 0) return false;
     
    // Get the x and y
    float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
    float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
    float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;
     
    // Check if the x and y coordinates are within both lines
    if ( x < min(x1, x2) || x > max(x1, x2) ||
            x < min(x3, x4) || x > max(x3, x4) ) return false;
    if ( y < min(y1, y2) || y > max(y1, y2) ||
            y < min(y3, y4) || y > max(y3, y4) ) return false;
     
    // Return the point of intersection
    return true;
}

bool areIntersect(vector<Point>& theNerdPoints, vector<Point>& theNotNerdPoints)
{
    for ( int i = 0; i < theNerdPoints.size() - 1; ++i)
    {
        for ( int  j = 0 ; j < theNotNerdPoints.size() -1 ; ++j)
        {
            if( isIntersect(theNerdPoints[i], theNerdPoints[i+1], theNotNerdPoints[j], theNotNerdPoints[j+1]))
                return true;
        }
    }
    return false;
}

bool isTheorySatisfied(vector<Point> & theNerdPoints, vector<Point> & theNotNerdPoints)
{
    vector<Point> nerdLowerConvexHull = createLowerConvexHull(theNerdPoints);
    vector<Point> notnerdUpperConvexHull = createUpperConvexHull(theNotNerdPoints);

    return !areIntersect(theNerdPoints, theNotNerdPoints);
}

int main(int argc, char** argv)
{
    int numTests = 0;
    vector<int> numPoly;

    cin >> numTests;
    for (int test = 0; test < numTests; ++test)
    {
        int input;
        cin >> input;
        vector<Point> nerdPoints;
        vector<Point> notNerdPoints;
        for (int numPoints = 0; numPoints < input; ++numPoints)
        {
            int isNerd, x, y;
            cin >> isNerd >> x >> y;
            if ( isNerd)
                nerdPoints.push_back(Point(x, y));
            else
                notNerdPoints.push_back(Point(x, y));
        }
//        cout << " nerd points " << nerdPoints.size() << " not nerd points " << notNerdPoints.size() << endl;
        if (isTheorySatisfied(nerdPoints, notNerdPoints))
            cout << "THEORY HOLDS" << endl;
        else
            cout << "THEORY IS INVALID" << endl;
    }
    return 0;
}

