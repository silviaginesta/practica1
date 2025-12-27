#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

class Shape {
protected:
    std::string color;

    static bool valid_color(const std::string& c) {
        return c == "red" || c == "green" || c == "blue";
    }

public:
    Shape();                       // color rojo por defecto
    Shape(std::string color);      // lanza invalid_argument si color inválido
    virtual ~Shape() = default;

    std::string get_color() const;
    void set_color(std::string c);

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() const = 0;
};

#endif

