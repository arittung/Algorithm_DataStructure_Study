#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 100

inline void error(const char* str) {
    std::cerr << str << "\n";
    exit(1);
};


class CircularDeque{
    protected:
        int front;  // ���� �� : �����͸� ������ ��ġ
        int rear;   // ���� �� : �����͸� �ִ� ��ġ
        int data[MAX_QUEUE_SIZE];
    public:
        CircularDeque() {}
        ~CircularDeque(){}
        bool isEmpty() {
            return front == rear;
        }

        bool isFull() {
            return (rear + 1) % MAX_QUEUE_SIZE == front;
        }

        void addFront(int val) {
            if (isFull()) {
                error("Error: ť�� ��ȭ�����Դϴ�.\n");
            }
            else {
                data[front] = val;
                front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            }
        }

        void addRear(int val) {
            if (isFull()) {
                error("Error: ť�� ��ȭ�����Դϴ�.\n");
            }
            else {
                rear = (rear + 1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        
        int deleteFront() {
            if (isEmpty()) {
                error("Error: ť�� ��������Դϴ�.\n");
            }
            else {
                front = (front + 1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }

        int deleteRear() {
            if (isEmpty()) {
                error("Error: ť�� ��������Դϴ�.\n");
            }
            else {
                int res = data[rear];
                rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                return res;
            }
        }

        int getFront() {
            if (isEmpty()) {
                error(" Error: ť�� ��������Դϴ�\n");
            }
            else {
                return data[(front + 1) % MAX_QUEUE_SIZE];
            }
        }

        int getRear() {
            if (isEmpty()) {
                error(" Error: ���� ��������Դϴ�\n");
            }
            else {
                return data[rear];
            }
        }

        void display() {
            cout << "Deque : ";
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

            for (int i = front + 1; i <= maxi; i++) {
                cout << data[i % MAX_QUEUE_SIZE] << " ";
            }
            cout << endl;
        }
        
};


