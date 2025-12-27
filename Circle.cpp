#include "Circle.h"

static const double PI = 3.141592;

Circle::Circle() : Shape(), center(0,0), radius(1) {}

Circle::Circle(std::string c, Point2D cen, double r)
    : Shape(c), center(cen), radius(r) {}

Point2D Circle::get_center() const { return center; }
void Circle::set_center(Point2D p) { center = p; }

double Circle::get_radius() const { return radius; }
void Circle::set_radius(double r) { radius = r; }

double Circle::area() const {
    return PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * PI * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() const {
    std::cout << "[Circle: color = " << color
              << "; center = " << center
              << "; radius = " << radius << "]";
}

std::ostream& operator<<(std::ostream& out, const Circle& c) {
    c.print();
    return out;
}

