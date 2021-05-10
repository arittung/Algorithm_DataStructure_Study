#include <iostream>

using namespace std;
#define MAX_QUEUE_SIZE 100

inline void error(const char* str) {
    cerr << str << "\n";   // 에러의 경우: std::cerr로 출력
    exit(1);
};

class CircularQueue {
    protected:
        int front;  // 가장 앞 : 데이터를 꺼내는 위치
        int rear;   // 가장 뒤 : 데이터를 넣는 위치
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
                error("Error: 큐가 포화상태입니다.\n");
            }
            else {
                rear = (rear + 1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }

        int dequeue() {
            if (isEmpty()) {
                error("Error: 큐가 공백상태입니다.\n");
            }
            else {
                front = (front + 1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }

        int peek() {
            if (isEmpty()) {
                error("Error: 큐가 공백상태입니다.\n");
            }
            else {
                return data[(front + 1) % MAX_QUEUE_SIZE];
            }
        }

        void display() {
            cout << "Queue : ";
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            // 논리연산 ? 참일때 쓰이는 값 : 거짓일 때 쓰이는 값

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