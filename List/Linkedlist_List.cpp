#include <iostream>

using namespace std;

// single linked list ����
class node {
	private:
		int data;
		node* next;
	public:
		node(int val = 0) {
			data = val;
			next = nullptr;
		}

		node* getLink() {		// ��ũ ��� ����
			return next;
		}

		int getData() {			// ������ ��� ����
			return data;
		}

		void setLink(node* target) {
			next = target;
		}

		void insertNext(node* newnode) {	// ����� ���� �ڸ��� �� ��带 �ִ� ����
			if (newnode != nullptr) {
				newnode->next = next;
				next = newnode;
			}
		}

		node* removeNext() {		// ����� ���� �ڸ� ��带 ����� ����
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

		void clear();		// ����Ʈ ����� ����
		node* getHead();	// ù ��带 �θ��� ����
		bool isEmpty();		// ���� Ȯ��

		node* getEntry(int pos);	// ��ȸ ����
		void insert(int pos, node* n);	// ���� ����
		void remove(int pose);		// ���� ����
		node* find(int value);		// �˻� ����
		void replace(int pos, node* n);	// ġȯ����
		size_t size();		// ������ ���ϱ�
		void display();		// linked list�� ��ü ���� ���

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
	cout << "��ü �׸��� �� : " << size() << ", ";
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
