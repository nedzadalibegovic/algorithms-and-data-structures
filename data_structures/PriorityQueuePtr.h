#pragma once
#include <iostream>
#include "Queue.h"
#include "Node.h"

template <class T>
class PriorityQueuePtr : public Queue<T> {
    Node<T>* head = nullptr;

public:
    virtual void enqueue(const T& data) {
        Node<T>* ptr = head;
        Node<T>* bfr = nullptr;

        while (ptr != nullptr && ptr->data > data) {
            bfr = ptr;
            ptr = ptr->next;
        }

        Node<T>* temp = new Node<T>(data, ptr);

        if (bfr != nullptr) {
            bfr->next = temp;
        } else {
            head = temp;
        }
    }

    virtual T dequeue() {
        if (head == nullptr) {
            throw std::exception("PriorityQueue is empty");
        }

        Node<T>* ptr = head;
        T rtrn = head->data;

        head = head->next;
        delete ptr;

        return rtrn;
    }

    virtual void print() {
        Node<T>* ptr = head;

        while (ptr != nullptr) {
            std::cout << ptr->data << "\n";
            ptr = ptr->next;
        }
    }
};