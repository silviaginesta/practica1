#include <iostream>
#include "Point2D.h"
    
int main(){
    std::cout << std::boolalpha; // config. para mostrar true/false en lugar de 0/1.
    Point2D a(0,0);
    Point2D b(1,1);
    std::cout << "a = " << a << "; b = " << b << std::endl;
    std::cout << "d(a,b) = " << Point2D::distance(a, b) << std::endl; // 1.41421 
    std::cout << "a==b --> " << (a == b) << std::endl; // false
    std::cout << "a!=b --> " << (a != b) << std::endl; // true

    std::cout << std::endl;
    a = b;
    std::cout << "a = " << a << "; b = " << b << std::endl;
    std::cout << "d(a,b) = " << Point2D::distance(a, b) << std::endl; // 0
    std::cout << "a==b --> " << (a == b) << std::endl; // true
    std::cout << "a!=b --> " << (a != b) << std::endl; // false
}

