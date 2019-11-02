#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
struct Node_PriorityQueue {
    T data;
    size_t priority;

    Node_PriorityQueue(const T& data, size_t priority) : data(data), priority(priority) {}
};

template <class T>
class PriorityQueue_Heap {
    vector<Node_PriorityQueue<T>> items;

    static size_t index_leftChild(size_t index) {
        return 2 * index + 1;
    }

    static size_t index_rightChild(size_t index) {
        return 2 * index + 2;
    }

    static size_t index_parent(size_t index) {
        return index > 2 ? (index - 1) / 2 : 0;
    }

    bool index_hasLeftChild(size_t index) {
        return index_leftChild(index) < items.size();
    }

    bool index_hasRightChild(size_t index) {
        return index_rightChild(index) < items.size();
    }

    bool index_hasParent(size_t index) {
        return index_parent(index) < items.size();
    }

    void bubbleUp(size_t index) {
        if (items.size() <= 1) {
            return;
        }

        while (items[index].priority < items[index_parent(index)].priority) {
            swap(items[index], items[index_parent(index)]);
            index = index_parent(index);
        }
    }

    void bubbleDown() {
        size_t index = 0;

        while (index_hasLeftChild(index)) {
            if (index_hasRightChild(index)) {
                if (items[index_leftChild(index)].priority < items[index_rightChild(index)].priority) {
                    swap(items[index_leftChild(index)], items[index]);
                    index = index_leftChild(index);
                } else {
                    swap(items[index_rightChild(index)], items[index]);
                    index = index_rightChild(index);
                }
            } else {
                if (items[index_leftChild(index)].priority < items[index].priority) {
                    swap(items[index_leftChild(index)], items[index]);
                    index = index_leftChild(index);
                }
            }
        }
    }

public:
    void enqueue(const T& data, size_t priority) {
        items.push_back(Node_PriorityQueue<T>(data, priority));
        bubbleUp(items.size() - 1);
    }

    void dequeue() {
        if (items.empty()) {
            return;
        }

        items[0] = items[items.size() - 1];
        items.pop_back();
        bubbleDown();
    }

    friend ostream& operator<<(ostream& out, const PriorityQueue_Heap<T>& obj) {
        for (size_t i = 0; i < obj.items.size(); i++) {
            out << obj.items[i].data << " " << obj.items[i].priority << "\n";
        }

        return out;
    }
};