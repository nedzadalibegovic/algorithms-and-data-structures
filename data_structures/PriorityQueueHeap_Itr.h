#pragma once
#include <iostream>
#include <vector>
#include "Queue.h"

template <class T>
class PriorityQueueHeap_Itr : public Queue<T> {
    std::vector<T> items;

    static int getIndexOfLeftChild(int index) {
        return 2 * index + 1;
    }

    static int getIndexOfRightChild(int index) {
        return 2 * index + 2;
    }

    static int getIndexOfParent(int index) {
        return index > 2 ? (index - 1) / 2 : 0;
    }

    bool hasLeftChild(int index) {
        return getIndexOfLeftChild(index) < items.size();
    }

    bool hasRightChild(int index) {
        return getIndexOfRightChild(index) < items.size();
    }

    bool hasParent(int index) {
        return getIndexOfParent(index) < items.size();
    }

    void bubbleUp(int index) {
        if (items.size() <= 1) {
            return;
        }

        while (items[index] > items[getIndexOfParent(index)]) {
            std::swap(items[index], items[getIndexOfParent(index)]);
            index = getIndexOfParent(index);
        }
    }

    void bubbleDown() {
        int index = 0;

        while (hasLeftChild(index)) {
            if (hasRightChild(index)) {
                if (items[getIndexOfLeftChild(index)] > items[getIndexOfRightChild(index)]) {
                    std::swap(items[getIndexOfLeftChild(index)], items[index]);
                    index = getIndexOfLeftChild(index);
                } else {
                    std::swap(items[getIndexOfRightChild(index)], items[index]);
                    index = getIndexOfRightChild(index);
                }
            } else {
                if (items[getIndexOfLeftChild(index)] > items[index]) {
                    std::swap(items[getIndexOfLeftChild(index)], items[index]);
                    index = getIndexOfLeftChild(index);
                } else {
                    break;
                }
            }
        }
    }

public:
    virtual void enqueue(const T& data) {
        items.push_back(data);
        bubbleUp(items.size() - 1);
    }

    virtual T dequeue() {
        if (items.empty()) {
            throw std::exception("Queue is empty");
        }

        T rtrn = items[0];

        items[0] = items[items.size() - 1];
        items.pop_back();
        bubbleDown();

        return rtrn;
    }

    virtual void print() {
        for (size_t i = 0; i < items.size(); i++) {
            std::cout << items[i] << "\n";
        }
    }
};