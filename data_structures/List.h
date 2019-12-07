#pragma once

template<class T>
class List {
public:
    virtual void pushFront(const T&) = 0;
    virtual void pushBack(const T&) = 0;

    virtual T popFront() = 0;
    virtual T popBack() = 0;

    virtual void print() = 0;
};