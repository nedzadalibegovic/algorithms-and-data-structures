#pragma once
#include "List.h"

template <class T>
class ListSeq : public List<T> {
    size_t size = 0;
    size_t max = 100;
    T* arr = new T[max];

    void resize() {
        T* temp = new T[max * 2];
        max *= 2;

        for (size_t i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

public:
    virtual void pushFront(const T& data) override {
        if (size >= max) {
            resize();
        }

        for (size_t i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = data;
        size++;
    }

    virtual void pushBack(const T& data) override {
        if (size >= max) {
            resize();
        }

        arr[size - 1] = data;
        size++;
    }

    virtual T popFront() override {
        if (size == 0) {
            throw std::exception("List is empty");
        }

        T rtrn = arr[0];

        for (size_t i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;

        return rtrn;
    }

    virtual T popBack() override {
        if (size == 0) {
            throw std::exception("List is empty");
        }

        return arr[--size];
    }

    virtual void print() override {
        for (size_t i = 0; i < size; i++) {
            std::cout << arr[i] << "\n";
        }
    }
};