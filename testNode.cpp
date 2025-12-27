#include <iostream>
#include "Node.h"

int main() {
    Node<char> n1('A');
    Node<char> n2('B');
    Node<char> n3('C');

    n1.next = &n2;
    n2.next = &n3;

    Node<char>* p = &n1;
    while (p != nullptr) {
        std::cout << p->data;
        if (p->next != nullptr) std::cout << " -> ";
        p = p->next;
    }
    std::cout << std::endl;

    return 0;
}

