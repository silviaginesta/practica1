#include <iostream>
#include "ListArray.h"

int main(){
    std::cout << std::boolalpha; // configuramos cout para mostrar true/false en lugar de 0/1.

    ListArray<int> list;

    std::cout << list << std::endl; 
    std::cout << "size(): " << list.size() << std::endl; 
    std::cout << "empty(): " << list.empty() << std::endl; 
    std::cout << std::endl; 

    list.insert(0, 0);
    list.insert(1, 10);
    list.insert(0, -5);
    list.insert(2, 5);
    std::cout << list << std::endl; 
    std::cout << "size(): " << list.size() << std::endl; 
    std::cout << "empty(): " << list.empty() << std::endl; 
    std::cout << std::endl; 

    std::cout << "l.get(0) => " << list.get(0) << "; l[0] => " << list[0] << std::endl; 
    std::cout << "l.get(3) => " << list.get(3) << "; l[3] => " << list[3] << std::endl; 
    std::cout << std::endl; 

    int r;
    r = list.remove(3);
    std::cout << "l.remove(3) => " << r << ": " << std::endl; 
    r = list.remove(1);
    std::cout << "l.remove(1) => " << r << ": " << std::endl; 
    r = list.remove(0);
    std::cout << "l.remove(0) => " << r << ": " << std::endl; 
    std::cout << std::endl; 

    std::cout << list << std::endl; 
    std::cout << "size(): " << list.size() << std::endl; 
    std::cout << "empty(): " << list.empty() << std::endl; 
    std::cout << std::endl; 
   
    list.append(14);
    list.prepend(33);
    std::cout << list << std::endl; 
    std::cout << "size(): " << list.size() << std::endl; 
    std::cout << "empty(): " << list.empty() << std::endl; 
    std::cout << std::endl; 

    std::cout << "l.search(14) => " << list.search(14) << std::endl; 
    std::cout << "l.search(55) => " << list.search(55) << std::endl; 

    try{
        list.insert(-1, -99);
    } catch (std::out_of_range &e){
        std::cout << "l.insert(-1, 99) => std::out_of_range: " << e.what() << std::endl; 
    }

    try{
        list.insert(4, -99);
    } catch (std::out_of_range &e){
        std::cout << "l.insert(4, 99) => std::out_of_range: " << e.what() << std::endl; 
    }

    try{
        list.get(-1);
    } catch (std::out_of_range &e){
        std::cout << "l.get(-1) => std::out_of_range: " << e.what() << std::endl; 
    }

    try{
        list.get(3);
    } catch (std::out_of_range &e){
        std::cout << "l.get(3) => std::out_of_range: " << e.what() << std::endl; 
    }

    try{
        list.remove(-1);
    } catch (std::out_of_range &e){
        std::cout << "l.remove(-1) => std::out_of_range: " << e.what() << std::endl; 
    }

    try{
        list.remove(3);
    } catch (std::out_of_range &e){
        std::cout << "l.remove(3) => std::out_of_range: " << e.what() << std::endl; 
    }

}
