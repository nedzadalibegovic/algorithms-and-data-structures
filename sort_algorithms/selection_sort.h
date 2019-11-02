#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void selection_sort(vector<T>& arr) {
    size_t min_index = 0;

    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }

        swap(arr[min_index], arr[i]);
        min_index = i + 1;
    }
}