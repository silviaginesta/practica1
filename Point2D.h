#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

class Point2D {
public:
    double x;
    double y;

    Point2D(double x = 0, double y = 0) : x(x), y(y) {}

    static double distance(const Point2D& a, const Point2D& b);
};

// == y != como funciones globales
bool operator==(const Point2D& a, const Point2D& b);
bool operator!=(const Point2D& a, const Point2D& b);

// <<
std::ostream& operator<<(std::ostream& out, const Point2D& p);

#endif

