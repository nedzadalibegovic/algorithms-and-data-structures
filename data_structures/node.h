#pragma once

template <class T>
struct Node {
    T data;
    Node* next;

    Node(const T& data) : data(data) {
        next = nullptr;
    }
};