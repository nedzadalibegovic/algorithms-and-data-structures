#pragma once
#include <utility>

template <class T>
void SelectionSort(T arr[], size_t size) {
    size_t min_index = 0;

    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        std::swap(arr[min_index], arr[i]);
        min_index = i + 1;
    }
}