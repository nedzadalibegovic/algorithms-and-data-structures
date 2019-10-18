#include <iostream>

using namespace std;

template <class T>
struct Node {
    T data;
    Node<T>* previous;
    Node<T>* next;

public:
    Node(const T& data) : data(data) {
        previous = nullptr;
        next = nullptr;
    }
};

template <class T>
class DoublyLinkedList {
    Node<T>* head;
    Node<T>* tail;
    size_t size;

    void init(const T& data) {
        head = new Node<T>(data);
        tail = head;
        size = 1;
    }

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void pushFront(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            Node<T>* ptr = new Node<T>(data);

            ptr->next = head;
            head->previous = ptr;
            head = ptr;
            size += 1;
        }
    }

    void pushBack(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            tail->next = new Node<T>(data);
            tail->next->previous = tail;
            tail = tail->next;
            size += 1;
        }
    }

    void popBack() {
        if (size <= 0) {
            return;
        }

        if (size == 1) {
            delete head;
            size = 0;
            return;
        }

        Node<T>* itr = head;
        Node<T>* ptr = nullptr;

        while (itr != tail) {
            ptr = itr;
            itr = itr->next;
        }

        delete tail;
        tail = ptr;
        ptr->next = nullptr;
        size -= 1;
    }

    void popFront() {
        if (size <= 0) {
            return;
        }

        if (size == 1) {
            delete head;
            size = 0;
            return;
        }

        Node<T>* ptr = head->next;

        delete head;
        head = ptr;
        head->previous = nullptr;
        size -= 1;
    }

    void insert(const T& data, size_t index) {
        if (index >= size || index < 0) {
            throw exception("Invalid index!");
        }

        if (index == 0) {
            pushFront(data);
            return;
        }

        if (index == size - 1) {
            pushBack(data);
            return;
        }

        Node<T>* before = head;
        Node<T>* after = nullptr;

        for (size_t i = 0; i < index - 1; i++) {
            before = before->next;
        }

        after = before->next;

        before->next = new Node<T>(data);
        before->next->next = after;

        after->previous = before->next;
        before->next->previous = before;

        size += 1;
    }

    void erase(size_t index) {
        if (index >= size || index < 0) {
            throw exception("Invalid index!");
        }

        if (index == 0) {
            popFront();
            return;
        }

        if (index == size - 1) {
            popBack();
            return;
        }

        Node<T>* before = head;
        Node<T>* after = nullptr;

        for (size_t i = 0; i < index - 1; i++) {
            before = before->next;
        }

        after = before->next->next;

        delete before->next;
        before->next = after;
        after->previous = before;

        size -= 1;
    }

    friend ostream& operator<<(ostream& out, const DoublyLinkedList& list) {
        Node<T>* ptr = list.head;

        while (ptr != nullptr) {
            out << ptr->data << "\n";
            ptr = ptr->next;
        }

        return out;
    }

    ~DoublyLinkedList() {
        Node<T>* curr = head;
        Node<T>* next = head->next;

        while (next != nullptr) {
            delete curr;
            curr = next;
            next = curr->next;
        }

        delete curr;
    }
};

int main() {
    DoublyLinkedList<int> list;

    for (size_t i = 0; i < 10; i++) {
        list.pushFront(i);
    }

    list.pushBack(1337);

    list.popBack();
    list.popFront();

    list.insert(1337, 2);
    list.erase(2);

    cout << list << endl;

}