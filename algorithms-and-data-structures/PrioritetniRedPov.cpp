struct Node {
    Node* next;
    int data;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class PrioritetniRedPov {
    Node* head = nullptr;

public:

    void dodaj(int data) {
        if (head == nullptr) {
            head = new Node(data);
        } else {
            Node* itr = head;
            Node* bfr = nullptr;

            while (itr != nullptr && itr->data > data) {
                bfr = itr;
                itr = itr->next;
            }

            if (bfr == nullptr) {
                head->next = new Node(data);
            }
        }


    }
};