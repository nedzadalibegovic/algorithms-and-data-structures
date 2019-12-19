#pragma once
#include <utility>

template <class T>
void InsertionSort(T arr[], size_t size) {
    for (size_t i = 1; i < size; i++) {
        for (size_t j = i; j > 0; j--) {
            if (arr[j - 1] > arr[j]) {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}