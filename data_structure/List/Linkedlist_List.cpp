#include <iostream>

using namespace std;

// single linked list 구현
class node {
	private:
		int data;
		node* next;
	public:
		node(int val = 0) {
			data = val;
			next = nullptr;
		}

		node* getLink() {		// 링크 얻는 연산
			return next;
		}

		int getData() {			// 데이터 얻는 연산
			return data;
		}

		void setLink(node* target) {
			next = target;
		}

		void insertNext(node* newnode) {	// 노드의 다음 자리에 새 노드를 넣는 연산
			if (newnode != nullptr) {
				newnode->next = next;
				next = newnode;
			}
		}

		node* removeNext() {		// 노드의 다음 자리 노드를 지우는 연산
			node* removed = next;
			if (removed != nullptr) {
				next = removed->next;
			}
			return removed;
		}
};


class node_linked_list {
	protected:
		node origin;
	public:
		node_linked_list() : origin(0){}
		~node_linked_list() {
			clear();
		}

		void clear();		// 리스트 지우는 연산
		node* getHead();	// 첫 노드를 부르는 연산
		bool isEmpty();		// 공백 확인

		node* getEntry(int pos);	// 조회 연산
		void insert(int pos, node* n);	// 삽입 연산
		void remove(int pose);		// 삭제 연산
		node* find(int value);		// 검색 연산
		void replace(int pos, node* n);	// 치환연산
		size_t size();		// 사이즈 구하기
		void display();		// linked list의 전체 내용 출력

};


void node_linked_list::clear() {
	while (!isEmpty()) {
		remove(0);
	}
}

node* node_linked_list::getHead() {
	return origin.getLink();
}

bool node_linked_list::isEmpty() {
	return getHead() == nullptr;
}

node* node_linked_list::getEntry(int pos) {
	node* n = &origin;
	for (int i = -1; i < pos; i++, n = n->getLink()) {
		if (n == nullptr) {
			break;
		}
	}
	return n;
}

void node_linked_list::insert(int pos, node* n) {
	node* prev = getEntry(pos - 1);
	if (prev != nullptr) {
		prev->insertNext(n);
	}
}


void node_linked_list::remove(int pos) {
	node* prev = getEntry(pos - 1);
	delete prev->removeNext();
}

node* node_linked_list::find(int value) {
	for (node* p = getHead(); p != nullptr; p = p->getLink()) {
		if (p->getData() == value) {
			return p;
		}
	}
	return nullptr;
}


void node_linked_list::replace(int pos, node* n) {
	node* prev = getEntry(pos - 1);
	if (prev != nullptr) {
		delete prev->removeNext();
		prev->insertNext(n);
	}
}

size_t node_linked_list::size() {
	int count = 0;
	for (node* p = getHead(); p != nullptr; p = p->getLink()) {
		count++;
	}
	return count;
}

void node_linked_list::display() {
	cout << "전체 항목의 수 : " << size() << ", ";
	for (node* p = getHead(); p != nullptr; p = p->getLink()) {
		cout << p->getData() << " ";
	}
	cout << endl;
}

int main() {
	node_linked_list list;

	list.insert(0, new node(10));
	list.insert(0, new node(20));
	list.insert(1, new node(30));
	list.insert(list.size(), new node(40));
	list.insert(2, new node(50));
	list.display();

	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.replace(1, new node(90));
	list.display();

	list.clear();
	list.display();
	return 0;
}
