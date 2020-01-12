#pragma once
#include <iostream>
#include <vector>
#include "HashTable.h"

template <class T, int max_size>
class HashTableOpen : HashTable<T> {
    int items[max_size] = { 0 };
    bool occupied[max_size] = { false };
    int size = 0;

    int calculateHash(const T& item) {
        return item % max_size;
    }

public:
    void push(const T& item) override {
        if (size + 1 == max_size) {
            throw std::exception("HashTable is full");
        }

        int index = calculateHash(item);

        while (occupied[index]) {
            index++;

            if (index == max_size) {
                index = 0;
            }
        }

        items[index] = item;
        occupied[index] = true;
        size++;
    }

    bool pop(const T& item) override {
        if (size == 0) {
            throw std::exception("HashTable is empty");
        }

        int index = calculateHash(item);

        while (index != size) {
            if (items[index] == item && occupied[index]) {
                occupied[index] = false;
                size--;
                return true;
            }

            index++;
            if (index == size) {
                index = 0;
            }
        }

        return false;
    }

    void print() override {
        for (size_t i = 0; i < max_size; i++) {
            if (occupied[i]) {
                std::cout << items[i] << " ";
            } else {
                std::cout << "x" << " ";
            }
        }
    }
};