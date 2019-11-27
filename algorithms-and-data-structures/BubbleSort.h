#pragma once
#include <iostream>

template <class T>
void BubbleSort(T arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 1; j < size - i; j++) {
            if (arr[j - 1] > arr[j]) {
                std::swap(arr[j - 1], arr[j]);
            }
        }
    }
}