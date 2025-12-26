#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <cstddef>      // size_t
#include <stdexcept>    // std::out_of_range
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* data;
    std::size_t n;
    std::size_t cap;

    void ensure_capacity(std::size_t minCap) {
        if (cap >= minCap) return;
        std::size_t newCap = (cap == 0) ? 4 : cap;
        while (newCap < minCap) newCap *= 2;

        T* newData = new T[newCap];
        for (std::size_t i = 0; i < n; ++i) newData[i] = data[i];

        delete[] data;
        data = newData;
        cap = newCap;
    }

public:
    // Constructor / destructor
    ListArray() : data(nullptr), n(0), cap(0) {}
    ~ListArray() override { delete[] data; }

    // Copia (regla de 3 básica)
    ListArray(const ListArray& other) : data(nullptr), n(other.n), cap(other.cap) {
        data = (cap == 0) ? nullptr : new T[cap];
        for (std::size_t i = 0; i < n; ++i) data[i] = other.data[i];
    }

    ListArray& operator=(const ListArray& other) {
        if (this == &other) return *this;
        delete[] data;
        n = other.n;
        cap = other.cap;
        data = (cap == 0) ? nullptr : new T[cap];
        for (std::size_t i = 0; i < n; ++i) data[i] = other.data[i];
        return *this;
    }

    // ---- Métodos heredados (AJUSTA nombres a tu List.h) ----
    bool empty() const override { return n == 0; }
    std::size_t size() const override { return n; }

    void clear() override {
        // No hace falta liberar memoria; basta con “vaciar”
        n = 0;
    }

    void push_back(const T& value) override {
        ensure_capacity(n + 1);
        data[n] = value;
        ++n;
    }

    void push_front(const T& value) override {
        ensure_capacity(n + 1);
        for (std::size_t i = n; i > 0; --i) data[i] = data[i - 1];
        data[0] = value;
        ++n;
    }

    void pop_back() override {
        if (n == 0) throw std::out_of_range("pop_back on empty ListArray");
        --n;
    }

    void pop_front() override {
        if (n == 0) throw std::out_of_range("pop_front on empty ListArray");
        for (std::size_t i = 0; i + 1 < n; ++i) data[i] = data[i + 1];
        --n;
    }

    T& front() override {
        if (n == 0) throw std::out_of_range("front on empty ListArray");
        return data[0];
    }

    const T& front() const override {
        if (n == 0) throw std::out_of_range("front on empty ListArray");
        return data[0];
    }

    T& back() override {
        if (n == 0) throw std::out_of_range("back on empty ListArray");
        return data[n - 1];
    }

    const T& back() const override {
        if (n == 0) throw std::out_of_range("back on empty ListArray");
        return data[n - 1];
    }
};

#endif

