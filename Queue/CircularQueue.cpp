#include <iostream>

using namespace std;
#define MAX_QUEUE_SIZE 100

inline void error(const char* str) {
    cerr << str << "\n";   // ������ ���: std::cerr�� ���
    exit(1);
};

class CircularQueue {
    protected:
        int front;  // ���� �� : �����͸� ������ ��ġ
        int rear;   // ���� �� : �����͸� �ִ� ��ġ
        int data[MAX_QUEUE_SIZE];
    public:
        CircularQueue() {
            front = 0;
            rear = 0;
        }
        ~CircularQueue() {}

        bool isEmpty() {
            return front == rear;
        }

        bool isFull() {
            return (rear + 1) % MAX_QUEUE_SIZE == front;
        }

        void enqueue(int val) {
            if (isFull()) {
                error("Error: ť�� ��ȭ�����Դϴ�.\n");
            }
            else {
                rear = (rear + 1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }

        int dequeue() {
            if (isEmpty()) {
                error("Error: ť�� ��������Դϴ�.\n");
            }
            else {
                front = (front + 1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }

        int peek() {
            if (isEmpty()) {
                error("Error: ť�� ��������Դϴ�.\n");
            }
            else {
                return data[(front + 1) % MAX_QUEUE_SIZE];
            }
        }

        void display() {
            cout << "Queue : ";
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            // ������ ? ���϶� ���̴� �� : ������ �� ���̴� ��

            for (int i = front + 1; i <= maxi; i++) {
                cout << data[i % MAX_QUEUE_SIZE] << " ";
            }
            cout << endl;
        }
};


int main() {
    CircularQueue que;
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