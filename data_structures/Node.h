#pragma once

template <class T>
struct Node {
    T data;
    Node* next;

    Node(const T& data, Node<T>* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};