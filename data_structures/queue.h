#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Node_Queue {
    T data;
    Node_Queue* next;

    Node_Queue(const T& data) : data(data) {
        next = nullptr;
    }
};

template <class T>
class Queue {
    Node_Queue<T>* head;
    Node_Queue<T>* tail;
    size_t size;

    void init(const T& data) {
        head = new Node_Queue<T>(data);
        tail = head;
        size = 1;
    }

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void enqueue(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            tail->next = new Node_Queue<T>(data);
            tail = tail->next;
            size += 1;
        }
    }

    void dequeue() {
        if (size <= 0) {
            return;
        }

        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size = 0;
            return;
        }

        Node_Queue<T>* ptr = head->next;

        delete head;
        head = ptr;
        size -= 1;
    }

    friend ostream& operator<<(ostream& out, const Queue& obj) {
        Node_Queue<T>* ptr = obj.head;

        while (ptr != nullptr) {
            out << ptr->data << " ";
            ptr = ptr->next;
        }

        return out;
    }

    ~Queue() {
        Node_Queue<T>* curr = head;
        Node_Queue<T>* next = head->next;

        while (next != nullptr) {
            delete curr;
            curr = next;
            next = curr->next;
        }

        delete curr;
    }
};