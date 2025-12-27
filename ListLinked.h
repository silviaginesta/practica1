#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

    void check_pos_get(int pos) const {
        if (pos < 0 || pos >= n) throw std::out_of_range("pos out of range");
    }

    void check_pos_insert(int pos) const {
        if (pos < 0 || pos > n) throw std::out_of_range("pos out of range");
    }

    Node<T>* node_at(int pos) const {
        Node<T>* p = first;
        for (int i = 0; i < pos; ++i) p = p->next;
        return p;
    }

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() override {
        this->clear();
    }

    // ===== Implementación completa de List<T> =====

    // Interfaz principal
    void insert(int pos, T e) override {
        check_pos_insert(pos);
        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = node_at(pos - 1);
            prev->next = new Node<T>(e, prev->next);
        }
        ++n;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        check_pos_get(pos);
        Node<T>* to_delete;
        if (pos == 0) {
            to_delete = first;
            first = first->next;
        } else {
            Node<T>* prev = node_at(pos - 1);
            to_delete = prev->next;
            prev->next = to_delete->next;
        }
        T value = to_delete->data;
        delete to_delete;
        --n;
        return value;
    }

    T get(int pos) const override {
        check_pos_get(pos);
        return node_at(pos)->data;
    }

    int search(T e) const override {
        Node<T>* p = first;
        int i = 0;
        while (p != nullptr) {
            if (p->data == e) return i;
            p = p->next;
            ++i;
        }
        return -1;
    }

    bool empty() const override { return n == 0; }
    std::size_t size() const override { return static_cast<std::size_t>(n); }

    // Métodos extra que exige tu List.h
    void clear() override {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
        n = 0;
    }

    void push_front(const T& value) override {
        prepend(value);
    }

    void push_back(const T& value) override {
        append(value);
    }

    void pop_front() override {
        (void)remove(0);
    }

    void pop_back() override {
        (void)remove(n - 1);
    }

    T& front() override {
        check_pos_get(0);
        return node_at(0)->data;
    }

    const T& front() const override {
        check_pos_get(0);
        return node_at(0)->data;
    }

    T& back() override {
        check_pos_get(n - 1);
        return node_at(n - 1)->data;
    }

    const T& back() const override {
        check_pos_get(n - 1);
        return node_at(n - 1)->data;
    }

    // operator[]
    T operator[](int pos) const {
        return get(pos);
    }

    // operator<<
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "[";
        Node<T>* p = list.first;
        int i = 0;
        while (p != nullptr) {
            out << p->data;
            if (i + 1 < list.n) out << ", ";
            p = p->next;
            ++i;
        }
        out << "]";
        return out;
    }
};

#endif

