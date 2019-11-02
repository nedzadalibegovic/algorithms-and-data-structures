#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Node_LinkedList {
    T data;
    Node_LinkedList* next;

    Node_LinkedList(const T& data) : data(data) {
        next = nullptr;
    }
};

template <class T>
class LinkedList {
    Node_LinkedList<T>* head;
    Node_LinkedList<T>* tail;
    size_t size;

    void init(const T& data) {
        head = new Node_LinkedList<T>(data);
        tail = head;
        size = 1;
    }
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void pushFront(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            Node_LinkedList<T>* ptr = new Node_LinkedList<T>(data);

            ptr->next = head;
            head = ptr;
            size += 1;
        }
    }

    void pushBack(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            tail->next = new Node_LinkedList<T>(data);
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

        Node_LinkedList<T>* itr = head;
        Node_LinkedList<T>* ptr = itr;

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

        Node_LinkedList<T>* ptr = head->next;

        delete head;
        head = ptr;
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

        Node_LinkedList<T>* before = head;
        Node_LinkedList<T>* after = nullptr;

        for (size_t i = 0; i < index - 1; i++) {
            before = before->next;
        }

        after = before->next;

        before->next = new Node_LinkedList<T>(data);
        before->next->next = after;

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

        Node_LinkedList<T>* before = head;
        Node_LinkedList<T>* after = nullptr;

        for (size_t i = 0; i < index - 1; i++) {
            before = before->next;
        }

        after = before->next->next;

        delete before->next;
        before->next = after;

        size -= 1;
    }

    friend ostream& operator<<(ostream& out, const LinkedList& list) {
        Node_LinkedList<T>* ptr = list.head;

        while (ptr != nullptr) {
            out << ptr->data << "\n";
            ptr = ptr->next;
        }

        return out;
    }

    size_t getSize() { return size; }

    T& operator[](size_t index) {
        if (index >= size || index < 0) {
            throw exception("Invalid index!");
        }

        Node_LinkedList<T>* ptr = head;

        for (size_t i = 0; i < index; i++) {
            ptr = ptr->next;
        }

        return ptr->data;
    }

    ~LinkedList() {
        Node_LinkedList<T>* curr = head;
        Node_LinkedList<T>* next = head->next;

        while (next != nullptr) {
            delete curr;
            curr = next;
            next = curr->next;
        }

        delete curr;
    }
};