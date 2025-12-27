#include "Shape.h"

Shape::Shape() : color("red") {}

Shape::Shape(std::string c) {
    if (!valid_color(c)) {
        throw std::invalid_argument("invalid color");
    }
    color = c;
}

std::string Shape::get_color() const {
    return color;
}

void Shape::set_color(std::string c) {
    if (!valid_color(c)) {
        throw std::invalid_argument("invalid color");
    }
    color = c;
}

