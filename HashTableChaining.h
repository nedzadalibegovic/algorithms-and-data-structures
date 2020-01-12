#pragma once
#include <iostream>
#include "HashTable.h"
#include "ListPtr.h"

template <class T, int max_size>
class HashTableChaining : HashTable<T> {
    ListPtr<T> items[max_size];
    int size = 0;

    int calculateHash(const T& item) {
        return item % max_size;
    }

public:
    void push(const T& item) override {
        int index = calculateHash(item);

        items[index].pushFront(item);
        size++;
    }

    bool pop(const T& item) override {
        int index = calculateHash(item);

        if (items[index].pop(item)) {
            size--;
            return true;
        }

        return false;
    }

    void print() override {
        for (size_t i = 0; i < max_size; i++) {
            std::cout << i << ": [ ";
            items[i].print();
            std::cout << "]\n";
        }
    }
};