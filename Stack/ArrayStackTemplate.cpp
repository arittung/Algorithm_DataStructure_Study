#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;

#define MAX_STACK_SIZE 100

inline void error(const char* str) {
	cerr << str << "\n";
	exit(1);
};	// inline: 인라인 함수는 함수를 호출하지 않고, 함수를 사용하는 위치에 컴파일러가 코드 자체를 복사해준다.

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
                error("스택 포화 에러"); 
            }
            data[++top] = e;
        }

        T pop() {
            if (isEmpty()) { 
                error("스택 공백 에러"); 
            }
            return data[top--];
        }

        T peek() {
            if (isEmpty()) {
                error("스택 공백 에러"); }
            return data[top];
        }

        void display() {
            cout << "[스택 항목의 수 = " << top + 1 << "] \n";
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