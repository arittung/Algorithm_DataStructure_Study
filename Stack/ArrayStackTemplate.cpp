#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;

#define MAX_STACK_SIZE 100

inline void error(const char* str) {
	cerr << str << "\n";
	exit(1);
};	// inline: �ζ��� �Լ��� �Լ��� ȣ������ �ʰ�, �Լ��� ����ϴ� ��ġ�� �����Ϸ��� �ڵ� ��ü�� �������ش�.

template <typename T>
class ArrayStackTemplate {
	T data[MAX_STACK_SIZE];
	int top;
    public:
       ArrayStackTemplate() { 
           top = -1; 
       }
        ~ArrayStackTemplate() {}
        bool isEmpty() { 
            return top == -1; 
        }
        bool isFull() { 
            return top == MAX_STACK_SIZE - 1; 
        }

        void push(T e) {
            if (isFull()) { 
                error("���� ��ȭ ����"); 
            }
            data[++top] = e;
        }

        T pop() {
            if (isEmpty()) { 
                error("���� ���� ����"); 
            }
            return data[top--];
        }

        T peek() {
            if (isEmpty()) {
                error("���� ���� ����"); }
            return data[top];
        }

        void display() {
            cout << "[���� �׸��� �� = " << top + 1 << "] \n";
            for (int i = 0; i <= top; i++) {
                cout << "<" << data[i] << ">";
            }
            cout << "\n";
        }
};


int main() {
    ArrayStackTemplate<double> stack;
    for (int i = 1; i < 10; i++) {
        stack.push(i);
    }
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();

    return 0;
}