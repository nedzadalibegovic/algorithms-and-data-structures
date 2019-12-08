#include <iostream>
#include <vector>

// Data Structures:
#include "ListPtr.h";
#include "ListSeq.h"
#include "StackSeq.h"
#include "StackPtr.h"
#include "QueueSeq.h"
#include "QueuePtr.h"
#include "PriorityQueueSeq.h"
#include "PriorityQueuePtr.h"
#include "PriorityQueueHeap.h"

// Algorithms:
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

using namespace std;

int main() {
#pragma region ListSeq
    cout << "ListSeq\n";
    ListSeq<int> list_seq;

    for (size_t i = 0; i < 300; i++) {
        list_seq.pushFront(i);
    }

    list_seq.popFront();

    cout << list_seq.popBack() << "\n";

    list_seq.print();

    cout << "/ListSeq\n";
#pragma endregion

#pragma region ListPtr
    cout << "ListPtr\n";
    ListPtr<int> list_ptr;

    for (size_t i = 0; i < 100; i++) {
        list_ptr.pushFront(i);
    }

    cout << list_ptr.popFront() << "<-\n";

    list_ptr.pushBack(100);

    cout << list_ptr.popBack() << "<-\n";

    list_ptr.pushBack(1337);

    list_ptr.print();

    cout << "/ListPtr\n";
#pragma endregion

#pragma region StackSeq
    cout << "StackSeq\n";
    StackSeq<int> stack_seq;

    for (size_t i = 0; i < 100; i++) {
        stack_seq.push(i);
    }

    stack_seq.pop();

    stack_seq.print();

    cout << "/StackSeq\n";
#pragma endregion

#pragma region StackPtr
    cout << "StackPtr\n";
    StackPtr<int> stack_ptr;

    for (size_t i = 0; i < 100; i++) {
        stack_ptr.push(i);
    }

    stack_ptr.pop();

    stack_ptr.print();

    cout << "/StackPtr\n";
#pragma endregion

#pragma region QueueSeq
    cout << "QueueSeq\n";
    QueueSeq<int> queue_seq;

    for (size_t i = 1; i < 10; i++) {
        queue_seq.enqueue(i);
    }

    queue_seq.dequeue();

    queue_seq.print();

    cout << "/QueueSeq\n";
#pragma endregion

#pragma region QueuePtr
    cout << "QueuePtr\n";
    QueuePtr<int> queue_ptr;

    for (size_t i = 1; i < 10; i++) {
        queue_ptr.enqueue(i);
    }

    queue_ptr.print();

    for (size_t i = 0; i < 9; i++) {
        cout << queue_ptr.dequeue() << "<-\n";
    }

    cout << "/QueuePtr\n";
#pragma endregion

#pragma region PriorityQueueSeq
    cout << "PriorityQueueSeq\n";
    PriorityQueueSeq<int> priority_queue_seq;

    for (size_t i = 0; i < 10; i++) {
        priority_queue_seq.enqueue(i);
    }

    priority_queue_seq.print();

    for (size_t i = 0; i < 9; i++) {
        cout << priority_queue_seq.dequeue() << "<-\n";
    }

    cout << "/PriorityQueueSeq\n";
#pragma endregion

#pragma region PriorityQueuePtr
    cout << "PriorityQueuePtr\n";
    PriorityQueuePtr<int> priority_queue_ptr;

    for (size_t i = 10; i > 0; i--) {
        priority_queue_ptr.enqueue(i);
    }

    priority_queue_ptr.print();

    for (size_t i = 0; i < 10; i++) {
        cout << priority_queue_ptr.dequeue() << "<-\n";
    }

    cout << "/PriorityQueuePtr\n";
#pragma endregion

#pragma region PriorityQueueHeap
    cout << "PriorityQueueHeap\n";
    PriorityQueueHeap<int> priority_queue_heap;

    for (size_t i = 1; i <= 10; i++) {
        priority_queue_heap.enqueue(i);
    }

    priority_queue_heap.print();

    for (size_t i = 0; i < 10; i++) {
        cout << priority_queue_heap.dequeue() << "<-\n";
    }

    cout << "/PriorityQueueHeap\n";
#pragma endregion

#pragma region BubbleSort
    vector<int> arr_bubble{ 15, 66, 19, 84, 65, 36, 53, 7, 43, 8, 59, 94, 3, 5, 71, 58, 27, 80, 1, 72, 78, 39, 57, 52, 12, 24, 25, 21, 91, 29, 11, 89, 40, 62, 18, 98, 54, 96, 35, 41, 86, 97, 79, 95, 33, 81, 64, 67, 50, 14, 28, 13, 42, 85, 17, 77, 74, 38, 22, 37, 61, 30, 90, 34, 56, 31, 10, 55, 6, 88, 49, 82, 73, 93, 68, 75, 16, 83, 4, 23, 63, 60, 51, 26, 9, 45, 46, 70, 44, 32, 47, 100, 20, 76, 99, 92, 87, 69, 2, 48 };

    BubbleSort(arr_bubble.data(), arr_bubble.size());

    cout << "\nBubble sort:\n";
    for (size_t i = 0; i < arr_bubble.size(); i++) {
        cout << arr_bubble[i] << " ";
    }

#pragma endregion

#pragma region InsertionSort
    vector<int> arr_insertion{ 76, 22, 71, 52, 93, 38, 79, 14, 6, 21, 42, 23, 18, 70, 81, 51, 20, 63, 89, 68, 9, 95, 31, 11, 12, 13, 37, 94, 27, 50, 64, 62, 34, 54, 25, 92, 2, 77, 7, 90, 69, 46, 58, 59, 60, 16, 74, 73, 53, 97, 26, 48, 45, 5, 33, 15, 17, 29, 61, 57, 82, 44, 30, 4, 98, 83, 86, 80, 49, 65, 35, 43, 78, 85, 19, 87, 96, 39, 40, 36, 91, 1, 28, 100, 75, 84, 55, 32, 24, 41, 99, 8, 3, 88, 10, 47, 56, 66, 72, 67 };

    InsertionSort(arr_insertion.data(), arr_insertion.size());

    cout << "\nInsertion sort:\n";
    for (size_t i = 0; i < arr_insertion.size(); i++) {
        cout << arr_insertion[i] << " ";
    }

#pragma endregion

#pragma region SelectionSort
    vector<int> arr_selection{ 24, 25, 90, 27, 72, 97, 66, 39, 47, 92, 12, 82, 35, 65, 52, 1, 14, 16, 91, 53, 84, 11, 68, 37, 42, 7, 34, 85, 43, 19, 40, 73, 32, 6, 100, 28, 62, 96, 46, 55, 70, 95, 77, 10, 48, 51, 20, 86, 8, 64, 50, 74, 98, 79, 5, 49, 61, 23, 76, 4, 30, 29, 81, 60, 56, 41, 67, 69, 38, 83, 22, 59, 71, 9, 57, 94, 75, 80, 99, 13, 54, 78, 15, 21, 33, 17, 58, 3, 88, 89, 63, 45, 36, 18, 93, 87, 44, 26, 31, 2 };

    SelectionSort(arr_selection.data(), arr_selection.size());

    cout << "\nSelection sort:\n";
    for (size_t i = 0; i < arr_selection.size(); i++) {
        cout << arr_selection[i] << " ";
    }

#pragma endregion

    return 0;
}