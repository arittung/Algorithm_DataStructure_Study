#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 100

inline void error(const char* str) {
    std::cerr << str << "\n";
    exit(1);
};


class CircularDeque{
    protected:
        int front;  // 가장 앞 : 데이터를 꺼내는 위치
        int rear;   // 가장 뒤 : 데이터를 넣는 위치
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
                error("Error: 큐가 포화상태입니다.\n");
            }
            else {
                data[front] = val;
                front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            }
        }

        void addRear(int val) {
            if (isFull()) {
                error("Error: 큐가 포화상태입니다.\n");
            }
            else {
                rear = (rear + 1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        
        int deleteFront() {
            if (isEmpty()) {
                error("Error: 큐가 공백상태입니다.\n");
            }
            else {
                front = (front + 1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }

        int deleteRear() {
            if (isEmpty()) {
                error("Error: 큐가 공백상태입니다.\n");
            }
            else {
                int res = data[rear];
                rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                return res;
            }
        }

        int getFront() {
            if (isEmpty()) {
                error(" Error: 큐가 공백상태입니다\n");
            }
            else {
                return data[(front + 1) % MAX_QUEUE_SIZE];
            }
        }

        int getRear() {
            if (isEmpty()) {
                error(" Error: 덱이 공백상태입니다\n");
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


