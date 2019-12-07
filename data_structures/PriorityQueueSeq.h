#pragma once
#include <iostream>
#include "Queue.h"

template <class T>
class PriorityQueueSeq : public Queue<T> {
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
    virtual void enqueue(const T& data) override {
        if (size >= max) {
            resize();
        }

        arr[size++] = data;
    }

    virtual T dequeue() override {
        T biggest = arr[0];
        size_t index = 0;

        for (size_t i = 0; i < size; i++) {
            if (arr[i] > biggest) {
                biggest = arr[i];
                index = i;
            }
        }

        std::swap(arr[index], arr[--size]);

        return biggest;
    }

    virtual void print() override {
        for (size_t i = 0; i < size; i++) {
            std::cout << arr[i] << "\n";
        }
    }
};