#pragma once
#include <iostream>
#include "node.h"

using namespace std;

template <class T>
class Stack {
    Node<T>* head;
    size_t size;

    void init(const T& data) {
        head = new Node<T>(data);
        size = 1;
    }
public:
    Stack() {
        head = nullptr;
        size = 0;
    }

    void push(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            Node<T>* ptr = new Node<T>(data);

            ptr->next = head;
            head = ptr;
            size += 1;
        }
    }

    void pop() {
        if (size == 0) {
            return;
        }

        if (size == 1) {
            delete head;
            head = nullptr;
            size = 0;
            return;
        }

        Node<T>* ptr = head->next;

        delete head;
        head = ptr;
        size -= 1;
    }

    friend ostream& operator<<(ostream& out, const Stack& obj) {
        Node<T>* ptr = obj.head;

        while (ptr != nullptr) {
            out << ptr->data << "\n";
            ptr = ptr->next;
        }

        return out;
    }

    ~Stack() {
        Node<T>* curr = head;
        Node<T>* next = head->next;

        while (next != nullptr) {
            delete curr;
            curr = next;
            next = curr->next;
        }

        delete curr;
    }
};