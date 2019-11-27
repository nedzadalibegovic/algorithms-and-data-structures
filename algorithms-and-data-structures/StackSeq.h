#pragma once
#include <iostream>
#include "Stack.h"

template <class T>
class StackSeq : public Stack<T> {
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
    virtual void push(const T& data) override {
        if (size >= max) {
            resize();
        }

        arr[size++] = data;
    }

    virtual T pop() override {
        if (size == 0) {
            throw std::exception("Stack is empty");
        }

        return arr[size--];
    }

    virtual void print() {
        for (size_t i = size - 1; i > 0; i--) {
            std::cout << arr[i] << "\n";
        }
    }
};