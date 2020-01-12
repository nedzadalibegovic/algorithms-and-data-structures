#pragma once

template <class T>
class HashTable {
public:
    virtual void push(const T&) = 0;
    virtual bool pop(const T&) = 0;
    virtual void print() = 0;
};