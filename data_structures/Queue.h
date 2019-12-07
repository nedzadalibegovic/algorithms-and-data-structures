#pragma once

template <class T>
class Queue {
public:
    virtual void enqueue(const T&) = 0;

    virtual T dequeue() = 0;

    virtual void print() = 0;
};