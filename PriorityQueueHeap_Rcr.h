#pragma once
#include <iostream>
#include <vector>
#include "Queue.h"

template <class T>
class PriorityQueueHeap_Rcr : public Queue<T> {
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
        int parent = getIndexOfParent(index);

        if (index == 0) {
            return;
        }

        if (items[index] < items[parent]) {
            return;
        }

        std::swap(items[index], items[getIndexOfParent(index)]);
        bubbleUp(getIndexOfParent(index));
    }

    void bubbleDown(int index) {
        int leftChild = getIndexOfLeftChild(index);
        int rightChild = getIndexOfRightChild(index);
        int swap_index = index;

        if (!hasLeftChild(index)) {
            return;
        }

        if (items[leftChild] > items[swap_index]) {
            swap_index = leftChild;
        }

        if (hasRightChild(index)) {
            if (items[rightChild] > items[swap_index]) {
                swap_index = rightChild;
            }
        }

        if (index != swap_index) {
            std::swap(items[index], items[swap_index]);
            bubbleDown(swap_index);
        }
    }

public:
    void enqueue(const T& item) override {
        items.push_back(item);
        bubbleUp(items.size() - 1);
    }

    T dequeue() override {
        if (items.empty()) {
            throw std::exception("Queue is empty");
        }

        T rtrn = items[0];

        std::swap(items[0], items[items.size() - 1]);
        items.pop_back();
        bubbleDown(0);

        return rtrn;
    }

    void print() override {
        for (size_t i = 0; i < items.size(); i++) {
            std::cout << items[i] << "\n";
        }
    }
};