#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

inline void error(const char* str) {
	cerr << str << "\n";
	exit(1);
};	// inline: 인라인 함수는 함수를 호출하지 않고, 함수를 사용하는 위치에 컴파일러가 코드 자체를 복사해준다.


struct node {
	int data;
	node* next;
};

class s_linked_list {
protected:
	node* head, * tail;	// head: first node, tail: last node
	int size = 0;
public:
	s_linked_list() {	// 생성자
		head = nullptr;
		tail = nullptr;
	}

	~s_linked_list() {	// 소멸자
		delete_list();
	}

	// 삽입 연산들
	void push_front(int n);	// 노드를 맨 앞에 한 개 추가
	void push_back(int n);	// 노드를 끝에 한 개 추가
	void insert_node_at(int idx, int n);	// 정해진 위치(idx)에 추가

	// 삭제 연산들
	int pop_front();	// 맨 앞 노드 지우고 지운 노드 출력
	int pop_back();		// 맨 끝 노드 지우고 지운 노드 출력
	int pop_node_at(int idx);	// idx 위치의 노드 지움
	void remove_node(int n);	// 값과 같은 노드 한개 지움
	void delete_list();		// linked_list 전체 지움

	// 대입
	void replace_value_at(int idx, int n);

	// 검색 및 표시
	int list_size();		// linked_list 크기 출력
	void display_contents();	// linked_list의 내용 출력
	int search_value(int n);	// 값 검색

};

// 삽입 연산들
void s_linked_list::push_front(int n) {
	node* ptr = new node;	// 새 노드의 메모리 할당
	ptr->next = head;
	ptr->data = n;
	head = ptr;
	if (ptr->next == nullptr) {
		tail = ptr;
	}
	size++;
}

void s_linked_list::push_back(int n) {
	node* tmp = new node;	// 새 노드의 메모리 할당
	tmp->data = n;
	tmp->next = nullptr;
	if (head == nullptr) {
		head = tmp;
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tail->next;
	}
	size++;
}

void s_linked_list::insert_node_at(int idx, int n) {
	if (size < idx || 0 > idx) {
		cout << "해당인덱스는 존재하지 않습니다." << endl;
	}
	else if (idx == 0) {	// idx == 0은 push_front(n)과 같다.
		push_front(n);
	}
	else if (idx == size) {	// idx == size는 push_back(n)과 같다.
		push_back(n);
	}
	else {
		node* ptr = head;
		node* tmp = ptr;
		node* new_node = new node;
		new_node->data = n;
		new_node->next = nullptr;	// 새 노드 초기화
		for (int i = 0; i < idx; i++) {
			tmp = ptr;		// 들어갈 노드의 직전 노드 위치
			ptr = ptr->next;	// 들어갈 노드의 위치
		}
		tmp->next = new_node;
		new_node->next = ptr;
		size++;
	}
}

// 삭제 연산
int s_linked_list::pop_front() {
	if (head == nullptr) {
		cout << "linked_list가  비었습니다." << endl;
		exit(1);
	}
	node* ptr = head;
	int value = head->data;
	head = ptr->next;
	if (head == nullptr) {
		tail == nullptr;
	}
	delete ptr;
	size--;
	return value;
}

int s_linked_list::pop_back() {
	if (size == 0) {
		cout << "linked_list기 비었습니다." << endl;
		exit(1);
	}
	node* ptr = head;
	node* tmp = new node;
	while (ptr->next != nullptr) {
		tmp = ptr;
		ptr = ptr->next;
	}
	int value = ptr->data;
	if (ptr == head) {	// pop_back()으로 인해 리스트가 빌때
		head = nullptr;
		tail = nullptr;
	}
	else {
		tail = tmp;
		tail->next = nullptr;
	}
	delete ptr;
	size--;
	return value;
}

int s_linked_list::pop_node_at(int idx) {
	int value = -1;
	if (size <= idx || 0 > idx) {
		cout << "해당 인덱스는 존재하지 않습니다다." << endl;
	}
	else if (size == 0) {
		cout << "linked list가 비어있습니다." << endl;
	}
	else if (idx == 0) {	// idx == 0은 pop_front()와 같다.
		value = pop_front();
	}
	else if (idx == size - 1) {
		value = pop_back();
	}
	else {
		node* ptr = head;
		node* tmp = ptr;
		for (int i = 0; i < idx; i++) {
			tmp = ptr;		// 삭제할 노드의 직전 노드 위치
			ptr = ptr->next;	// 삭제할 노드 위치
		}
		value = ptr->data;	// 지울 값
		tmp->next = ptr->next;	// 삭제할 노드를 빼고 연결
		if (ptr == tail) {
			tail = tmp;
		}
		size--;
		delete ptr;
		ptr = nullptr;
	}
	return value;
}

void s_linked_list::remove_node(int n) {
	node* ptr = head;
	node* tmp = ptr;
	while (ptr != nullptr) {
		if (ptr->data == n) {
			break;
		}
		else {
			tmp = ptr;		// 현재 노드
			ptr = ptr->next;	// 다음노드
		}
	}

	if (ptr == nullptr) {
		cout << n << "값의 노드는 존재하지 않습니다." << endl;
	}
	else if (size == 1) {
		head == nullptr;
		tail == nullptr;
	}
	else {
		size--;
		cout << ptr->data << "값의 노드를 하나 지웁니다." << endl;
		tmp->next = ptr->next;	// 삭제할 노드를 빼고 연결
		if (ptr == tail) {
			tail = tmp;
		}
		delete ptr;
	}
}

void s_linked_list::delete_list() {
	node* ptr = head;
	while (ptr != nullptr) {
		head = ptr->next;
		delete ptr;
		ptr = head;
	}
	size = 0;
	cout << "리스트가 삭제되었습니다." << endl;
}

// 대입
void s_linked_list::replace_value_at(int idx, int n) {
	node* ptr = head;
	if (size == 0) {
		cout << "linked list가 비어있습니다." << endl;
		exit(1);
	}
	else if (size <= idx || 0 > idx) {
		cout << "해당 인덱스는 존재하지 않습니다." << endl;
	}
	else {
		for (int i = 0; i < idx; i++) {
			ptr = ptr->next;	//들어갈 노드위치
		}
		ptr->data = n;
	}
}

// 검색 및 표시
int s_linked_list::list_size() {
	return size;
}

void s_linked_list::display_contents() {
	node* ptr = head;
	while (ptr != nullptr) {
		cout << ptr->data << "->";
		ptr = ptr->next;
	}
	cout << "nullptr" << endl;
}

int s_linked_list::search_value(int n) {
	node* ptr = head;
	int idx = 0;
	bool isFind = false;

	while (ptr != nullptr) {
		if (ptr->data == n) {
			cout << n << "은 " << idx << "에 있습니다." << endl;
			isFind = true;
			break;
		}
		ptr = ptr->next;
		idx++;
	}

	if (isFind == false) {
		cout << n << "은 리스트 안에 없습니다." << endl;
		return -1;
	}
	else {
		return idx;
	}
}

class LinkedListStack : public s_linked_list {
	public:
		LinkedListStack(): s_linked_list(){}
		bool isEmpty() {
			return list_size() == 0;
		}
		void push(int e) {
			push_front(e);
		}
		int pop() {
			if (isEmpty()) {
				error("스택 공백 에러");
			}
			return pop_front();
		}

		int peek() {
			if (isEmpty()) {
				error("스택 공백 에러");
			}
			return head->data;
		}
		
		void display() {
			node* ptr = head;
			cout << "[전체 스택의 수 = " << list_size() << "] ";
			for (int i = 0; i < list_size(); i++) {
				std::cout << "<" << ptr->data << ">";
				ptr = ptr->next;
			}
			std::cout << "\n";
		}
		
};




int main() {
	LinkedListStack stack;
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