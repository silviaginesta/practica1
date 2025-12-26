#ifndef LIST_H
#define LIST_H

#include <cstddef>  // size_t

template <typename T>
class List {
public:
    virtual ~List() = default;

    // Consultores
    virtual bool empty() const = 0;
    virtual std::size_t size() const = 0;

    // Operaciones
    virtual void clear() = 0;
    virtual void push_front(const T& value) = 0;
    virtual void push_back(const T& value) = 0;
    virtual void pop_front() = 0;
    virtual void pop_back() = 0;

    // Acceso (ejemplo)
    virtual T& front() = 0;
    virtual const T& front() const = 0;
    virtual T& back() = 0;
    virtual const T& back() const = 0;
};

#endif

