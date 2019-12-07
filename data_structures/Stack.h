#pragma once

template <class T>
class Stack {
    virtual void push(const T&) = 0;

    virtual T pop() = 0;

    virtual void print() = 0;
};