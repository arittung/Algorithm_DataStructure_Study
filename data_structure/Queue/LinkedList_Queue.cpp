#include "SingleLinkedList.h"

inline void error(const char* str) {
    std::cerr << str << "\n";
    exit(1);
};

class LinkedListQueue : public s_linked_list {
public:
    LinkedListQueue() : s_linked_list() {}
    bool isEmpty() { return list_size() == 0; }
    void enqueue(int e) {
        push_back(e);
    }
    int dequeue() {
        if (isEmpty()) { error("Queue 공백 에러"); }
        return pop_front();
    }
    int peek() {
        if (isEmpty()) { error("Queue 공백 에러"); }
        return head->data;
    }
    void display() {
        std::cout << "Queue : ";
        node* ptr = head;
        for (int i = 0; i < list_size(); i++) {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << "\n";
    }
};

int main() {
    LinkedListQueue que;
    for (int i = 1; i < 10; i++) {
        que.enqueue(i);
    }
    que.display();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.display();
    return 0;
}