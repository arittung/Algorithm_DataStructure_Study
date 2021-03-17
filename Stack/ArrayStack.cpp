#pragma once
#include <iostream>

using namespace std;
#define MAX_STACK_SIZE 100

inline int error(const char* str) {
	cerr << str << "\n";
	exit(1);
};	// inline: 인라인 함수는 함수를 호출하지 않고, 함수를 사용하는 위치에 컴파일러가 코드 자체를 복사해준다.

class ArrayStack {
private:
	int data[MAX_STACK_SIZE];	// 요소의 배열
	int top;	// 요소의 개수
public:
	ArrayStack() {
		top = -1;
	}
	~ArrayStack() {}
	bool isEmpty() {		// 스택이 지어있는지 확인
		return top == -1;
	}
	bool isFull() {		// 스택이 가득차있는지 확인
		return top == MAX_STACK_SIZE - 1;
	}

	void push(int e) {	// 스택에 요소 추가
		if(isFull()) {
			error("스택 포화 에러");
		}
		data[++top] = e;
	}
	int pop() {		// 스택에 요소 제거
		if (isEmpty()) {
			error("스택 공백 에러");
		}
		return data[top--];
	}

	int peek() {		// 맨 위의 요소 출력
		if (isEmpty()) {
			error("스택 공백 에러");
			return data[top];
		}
	}

	void display() {
		cout << "[스택 항목의 수 = " << top + 1 << "]";
		for (int i = 0; i <= top; i++) {
			cout << "<" << data[i] << ">";
		}
		cout << endl;
	}
};


int main() {
	ArrayStack stack;
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