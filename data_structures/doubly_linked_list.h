#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Node_DL {
    T data;
    Node_DL* next;
    Node_DL* previous;

public:
    Node_DL(const T& data) : data(data) {
        next = nullptr;
        previous = nullptr;
    }
};

template <class T>
class DoublyLinkedList {
    Node_DL<T>* head;
    Node_DL<T>* tail;
    size_t size;

    void init(const T& data) {
        head = new Node_DL<T>(data);
        tail = head;
        size = 1;
    }

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void pushFront(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            Node_DL<T>* ptr = new Node_DL<T>(data);

            ptr->next = head;
            head->previous = ptr;
            head = ptr;
            size += 1;
        }
    }

    void pushBack(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            tail->next = new Node_DL<T>(data);
            tail->next->previous = tail;
            tail = tail->next;
            size += 1;
        }
    }

    void popBack() {
        if (size <= 0) {
            return;
        }

        if (size == 1) {
            delete head;
            size = 0;
            return;
        }

        Node_DL<T>* itr = head;
        Node_DL<T>* ptr = nullptr;

        while (itr != tail) {
            ptr = itr;
            itr = itr->next;
        }

        delete tail;
        tail = ptr;
        ptr->next = nullptr;
        size -= 1;
    }

    void popFront() {
        if (size <= 0) {
            return;
        }

        if (size == 1) {
            delete head;
            size = 0;
            return;
        }

        Node_DL<T>* ptr = head->next;

        delete head;
        head = ptr;
        head->previous = nullptr;
        size -= 1;
    }

    void insert(const T& data, size_t index) {
        if (index >= size || index < 0) {
            throw exception("Invalid index!");
        }

        if (index == 0) {
            pushFront(data);
            return;
        }

        if (index == size - 1) {
            pushBack(data);
            return;
        }

        Node_DL<T>* before = head;
        Node_DL<T>* after = nullptr;

        for (size_t i = 0; i < index - 1; i++) {
            before = before->next;
        }

        after = before->next;

        before->next = new Node_DL<T>(data);
        before->next->next = after;

        after->previous = before->next;
        before->next->previous = before;

        size += 1;
    }

    void erase(size_t index) {
        if (index >= size || index < 0) {
            throw exception("Invalid index!");
        }

        if (index == 0) {
            popFront();
            return;
        }

        if (index == size - 1) {
            popBack();
            return;
        }

        Node_DL<T>* before = head;
        Node_DL<T>* after = nullptr;

        for (size_t i = 0; i < index - 1; i++) {
            before = before->next;
        }

        after = before->next->next;

        delete before->next;
        before->next = after;
        after->previous = before;

        size -= 1;
    }

    friend ostream& operator<<(ostream& out, const DoublyLinkedList& list) {
        Node_DL<T>* ptr = list.head;

        while (ptr != nullptr) {
            out << ptr->data << "\n";
            ptr = ptr->next;
        }

        return out;
    }

    ~DoublyLinkedList() {
        Node_DL<T>* curr = head;
        Node_DL<T>* next = head->next;

        while (next != nullptr) {
            delete curr;
            curr = next;
            next = curr->next;
        }

        delete curr;
    }
};