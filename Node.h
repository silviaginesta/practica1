#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node() : data{}, next(nullptr) {}
    Node(const T& data_in, Node<T>* next_in = nullptr) : data(data_in), next(next_in) {}
};

// Para poder imprimir un nodo con cout (si lo necesitas en los tests)
template <typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
    os << node.data;
    return os;
}

#endif

