#include "data_structures/linked_list.h"
#include "data_structures/doubly_linked_list.h"
#include "data_structures/stack.h"
#include "data_structures/queue.h"
#include "data_structures/priority_queue.h"
#include "sort_algorithms/insertion_sort.h"
#include "sort_algorithms/selection_sort.h"

using namespace std;

int main() {
    // singly linked list
    LinkedList<int> s_list;

    for (size_t i = 0; i < 10; i++) {
        s_list.pushFront(i);
        s_list.pushBack(i);
    }

    s_list.popFront();
    s_list.popBack();

    cout << s_list[2] << endl;

    s_list.insert(1337, 2);
    s_list.erase(2);

    cout << s_list << endl;

    cout << s_list.getSize() << endl;

    // doubly linked list
    DoublyLinkedList<int> d_list;

    for (size_t i = 0; i < 10; i++) {
        d_list.pushFront(i);
    }

    d_list.pushBack(1337);

    d_list.popBack();
    d_list.popFront();

    d_list.insert(1337, 2);
    d_list.erase(2);

    cout << d_list << endl;

    // stack
    Stack<int> foo;

    for (size_t i = 0; i < 10; i++) {
        foo.push(i);
    }

    foo.pop();

    cout << foo << endl;

    // queue
    Queue<int> q;

    for (size_t i = 0; i < 10; i++) {
        q.enqueue(i);
    }

    q.dequeue();

    cout << q << endl;

    // priority queue
    PriorityQueue_Heap<int> pq;

    pq.enqueue(60, 2);
    pq.enqueue(70, 4);
    pq.enqueue(80, 6);
    pq.enqueue(90, 1);

    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();

    cout << pq << endl;

    // insertion sort
    vector<int> insertion_arr = { 84, 72, 28, 5, 64, 61, 13, 79, 81, 68, 14, 31, 85, 6, 71, 47, 35, 78, 44, 50, 69, 29, 9, 18, 22, 3, 7, 19, 92, 63, 99, 17, 37, 86, 57, 30, 87, 34, 33, 39, 55, 96, 16, 11, 25, 93, 41, 74, 8, 60, 98, 76, 94, 38, 100, 66, 89, 97, 46, 70, 52, 36, 2, 26, 20, 77, 51, 90, 32, 1, 10, 59, 54, 24, 73, 91, 65, 95, 58, 15, 88, 4, 49, 21, 40, 23, 56, 27, 42, 48, 80, 82, 62, 67, 75, 53, 43, 83, 12, 45 };

    cout << "\nBefore insertion sort:\n";
    for (size_t i = 0; i < insertion_arr.size(); i++) {
        cout << insertion_arr[i] << " ";
    }

    insertion_sort(insertion_arr);

    cout << "\nAfter insertion sort:\n";
    for (size_t i = 0; i < insertion_arr.size(); i++) {
        cout << insertion_arr[i] << " ";
    }

    // selection sort
    vector<int> selection_arr = { 84, 72, 28, 5, 64, 61, 13, 79, 81, 68, 14, 31, 85, 6, 71, 47, 35, 78, 44, 50, 69, 29, 9, 18, 22, 3, 7, 19, 92, 63, 99, 17, 37, 86, 57, 30, 87, 34, 33, 39, 55, 96, 16, 11, 25, 93, 41, 74, 8, 60, 98, 76, 94, 38, 100, 66, 89, 97, 46, 70, 52, 36, 2, 26, 20, 77, 51, 90, 32, 1, 10, 59, 54, 24, 73, 91, 65, 95, 58, 15, 88, 4, 49, 21, 40, 23, 56, 27, 42, 48, 80, 82, 62, 67, 75, 53, 43, 83, 12, 45 };

    cout << "\nBefore selection sort:\n";
    for (size_t i = 0; i < selection_arr.size(); i++) {
        cout << selection_arr[i] << " ";
    }

    selection_sort(selection_arr);

    cout << "\nAfter selection sort:\n";
    for (size_t i = 0; i < selection_arr.size(); i++) {
        cout << selection_arr[i] << " ";
    }
}