#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <cstddef>
#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* data_;
    std::size_t size_;
    std::size_t cap_;

    void ensure_capacity(std::size_t minCap) {
        if (cap_ >= minCap) return;
        std::size_t newCap = (cap_ == 0) ? 4 : cap_;
        while (newCap < minCap) newCap *= 2;

        T* newData = new T[newCap];
        for (std::size_t i = 0; i < size_; ++i) newData[i] = data_[i];

        delete[] data_;
        data_ = newData;
        cap_ = newCap;
    }

    void check_index_get(int index) const {
        if (index < 0 || static_cast<std::size_t>(index) >= size_) {
            throw std::out_of_range("index out of range");
        }
    }

    void check_index_insert(int index) const {
        // insert permite index == size_ (insertar al final)
        if (index < 0 || static_cast<std::size_t>(index) > size_) {
            throw std::out_of_range("index out of range");
        }
    }

public:
    ListArray() : data_(nullptr), size_(0), cap_(0) {}
    ~ListArray() override { delete[] data_; }

    // Regla de 3 (recomendable)
    ListArray(const ListArray& other) : data_(nullptr), size_(other.size_), cap_(other.cap_) {
        data_ = (cap_ == 0) ? nullptr : new T[cap_];
        for (std::size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
    }

    ListArray& operator=(const ListArray& other) {
        if (this == &other) return *this;
        delete[] data_;
        size_ = other.size_;
        cap_ = other.cap_;
        data_ = (cap_ == 0) ? nullptr : new T[cap_];
        for (std::size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
        return *this;
    }

    // ===== Métodos de List<T> =====
    bool empty() const override { return size_ == 0; }
    std::size_t size() const override { return size_; }

    void clear() override { size_ = 0; }

    void push_front(const T& value) override { prepend(value); }
    void push_back(const T& value) override { append(value); }

    void pop_front() override { (void)remove(0); }
    void pop_back() override { (void)remove(static_cast<int>(size_) - 1); }

    T& front() override { return get(0); }
    const T& front() const override { return get(0); }

    T& back() override { return get(static_cast<int>(size_) - 1); }
    const T& back() const override { return get(static_cast<int>(size_) - 1); }

    // ===== API que usa el test =====
    void insert(int index, const T& value) {
        check_index_insert(index);
        ensure_capacity(size_ + 1);

        for (std::size_t i = size_; i > static_cast<std::size_t>(index); --i) {
            data_[i] = data_[i - 1];
        }

        data_[index] = value;
        ++size_;
    }

    T remove(int index) {
        check_index_get(index);
        T removed = data_[index];

        for (std::size_t i = static_cast<std::size_t>(index); i + 1 < size_; ++i) {
            data_[i] = data_[i + 1];
        }

        --size_;
        return removed;
    }

    T& get(int index) {
        check_index_get(index);
        return data_[index];
    }

    const T& get(int index) const {
        check_index_get(index);
        return data_[index];
    }

    void append(const T& value) {
        insert(static_cast<int>(size_), value);
    }

    void prepend(const T& value) {
        insert(0, value);
    }

    int search(const T& value) const {
        for (std::size_t i = 0; i < size_; ++i) {
            if (data_[i] == value) return static_cast<int>(i);
        }
        return -1;
    }

    T& operator[](int index) { return get(index); }
    const T& operator[](int index) const { return get(index); }

    friend std::ostream& operator<<(std::ostream& os, const ListArray<T>& list) {
        os << "[";
        for (std::size_t i = 0; i < list.size_; ++i) {
            os << list.data_[i];
            if (i + 1 < list.size_) os << ", ";
        }
        os << "]";
        return os;
    }
};

#endif

