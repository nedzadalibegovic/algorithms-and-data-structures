#pragma once
#include <iostream>
#include "Queue.h"
#include "Node.h"

template <class T>
class QueuePtr : public Queue<T> {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    void init(const T& data) {
        head = new Node<T>(data);
        tail = head;
    }

public:
    virtual void enqueue(const T& data) override {
        if (head == nullptr) {
            init(data);
        } else {
            tail->next = new Node<T>(data);
            tail = tail->next;
        }
    }

    virtual T dequeue() override {
        if (head == nullptr) {
            throw std::exception("Queue is empty");
        }

        Node<T>* ptr = head;
        T rtrn = head->data;

        head = head->next;
        delete ptr;

        return rtrn;
    }

    virtual void print() override {
        Node<T>* ptr = head;

        while (ptr != nullptr) {
            std::cout << ptr->data << "\n";
            ptr = ptr->next;
        }
    }
};