#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Node_Stack {
    T data;
    Node_Stack* previous;

    Node_Stack(const T& data) : data(data) {
        previous = nullptr;
    }
};

template <class T>
class Stack {
    Node_Stack<T>* head;
    size_t size;

    void init(const T& data) {
        head = new Node_Stack<T>(data);
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
            Node_Stack<T>* ptr = new Node_Stack<T>(data);

            ptr->previous = head;
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

        Node_Stack<T>* ptr = head->previous;

        delete head;
        head = ptr;
        size -= 1;
    }

    friend ostream& operator<<(ostream& out, const Stack& obj) {
        Node_Stack<T>* ptr = obj.head;

        while (ptr != nullptr) {
            out << ptr->data << "\n";
            ptr = ptr->previous;
        }

        return out;
    }

    ~Stack() {
        Node_Stack<T>* curr = head;
        Node_Stack<T>* next = head->previous;

        while (next != nullptr) {
            delete curr;
            curr = next;
            next = curr->previous;
        }

        delete curr;
    }
};