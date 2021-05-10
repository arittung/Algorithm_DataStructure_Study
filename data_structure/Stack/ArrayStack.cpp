#pragma once
#include <iostream>

using namespace std;
#define MAX_STACK_SIZE 100

inline int error(const char* str) {
	cerr << str << "\n";
	exit(1);
};	// inline: �ζ��� �Լ��� �Լ��� ȣ������ �ʰ�, �Լ��� ����ϴ� ��ġ�� �����Ϸ��� �ڵ� ��ü�� �������ش�.

class ArrayStack {
private:
	int data[MAX_STACK_SIZE];	// ����� �迭
	int top;	// ����� ����
public:
	ArrayStack() {
		top = -1;
	}
	~ArrayStack() {}
	bool isEmpty() {		// ������ �����ִ��� Ȯ��
		return top == -1;
	}
	bool isFull() {		// ������ �������ִ��� Ȯ��
		return top == MAX_STACK_SIZE - 1;
	}

	void push(int e) {	// ���ÿ� ��� �߰�
		if(isFull()) {
			error("���� ��ȭ ����");
		}
		data[++top] = e;
	}
	int pop() {		// ���ÿ� ��� ����
		if (isEmpty()) {
			error("���� ���� ����");
		}
		return data[top--];
	}

	int peek() {		// �� ���� ��� ���
		if (isEmpty()) {
			error("���� ���� ����");
			return data[top];
		}
	}

	void display() {
		cout << "[���� �׸��� �� = " << top + 1 << "]";
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