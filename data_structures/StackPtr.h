#pragma once
#include <iostream>
#include "Stack.h"
#include "Node.h"

template <class T>
class StackPtr : public Stack<T> {
    Node<T>* head = nullptr;

public:
    virtual void push(const T& data) override {
        Node<T>* ptr = new Node<T>(data, head);

        head = ptr;
    }

    virtual T pop() override {
        if (head == nullptr) {
            throw std::exception("Stack is empty");
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