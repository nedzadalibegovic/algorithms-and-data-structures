#pragma once
#include <iostream>
#include "Queue.h"

template <class T>
class QueueSeq : public Queue<T> {
    size_t size = 0;
    size_t max = 10;
    size_t front = 0;
    size_t rear = 0;
    T* arr = new T[max];

    void resize() {
        T* temp = new T[max * 2];

        int i = 0;
        int j = front;

        while (i < size) {
            temp[i++] = arr[j++];

            if (j == max) {
                j = 0;
            }
        }

        front = 0;
        rear = size;
        max *= 2;

        delete[] arr;
        arr = temp;
    }

public:
    virtual void enqueue(const T& data) override {
        if (size == max) {
            resize();
        }

        arr[rear++] = data;

        if (rear == max) {
            rear = 0;
        }

        size++;
    }

    virtual T dequeue() override {
        if (size == 0) {
            throw std::exception("Queue is empty!");
        }

        T rtrn = arr[front++];

        if (front == max) {
            front = 0;
        }

        size--;

        return rtrn;
    }

    virtual void print() override {
        int i = 0;
        int j = front;

        for (size_t i = 0; i < size; i++) {
            std::cout << arr[j++] << "\n";

            if (j == max) {
                j = 0;
            }
        }
    }
};