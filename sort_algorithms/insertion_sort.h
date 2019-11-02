#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void insertion_sort(vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        for (size_t j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}