#include "Point2D.h"

double Point2D::distance(const Point2D& a, const Point2D& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx*dx + dy*dy);
}

bool operator==(const Point2D& a, const Point2D& b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point2D& a, const Point2D& b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& out, const Point2D& p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

