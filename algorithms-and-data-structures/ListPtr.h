#pragma once
#include <iostream>
#include "List.h"
#include "Node.h"

template <class T>
class ListPtr : public List<T> {
    Node<T>* head = nullptr;

public:
    virtual void pushFront(const T& data) override {
        Node<T>* ptr = new Node<T>(data, head);

        head = ptr;
    }

    virtual void pushBack(const T& data) override {
        if (head == nullptr) {
            head = new Node<T>(data);
        } else {
            Node<T>* ptr = head;

            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }

            ptr->next = new Node<T>(data);
        }
    }

    virtual T popFront() override {
        if (head == nullptr) {
            throw std::exception("No elements");
        }

        Node<T>* ptr = head;
        T rtrn = head->data;

        head = head->next;
        delete ptr;

        return rtrn;
    }

    virtual T popBack() override {
        if (head == nullptr) {
            throw std::exception("No elements");
        }

        Node<T>* ptr = head;

        while (ptr->next != nullptr && ptr->next->next != nullptr) {
            ptr = ptr->next;
        }

        T rtrn = ptr->next->data;

        delete ptr->next;
        ptr->next = nullptr;

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