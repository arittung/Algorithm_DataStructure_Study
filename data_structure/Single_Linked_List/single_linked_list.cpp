#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

struct node {
	int data;
	node* next;
};

class s_linked_list {
protected:
	node *head, *tail;	// head: first node, tail: last node
	int size = 0;
public:
	s_linked_list() {	// ������
		head = nullptr;
		tail = nullptr;
	}

	~s_linked_list() {	// �Ҹ���
		delete_list();
	}

	// ���� �����
	void push_front(int n);	// ��带 �� �տ� �� �� �߰�
	void push_back(int n);	// ��带 ���� �� �� �߰�
	void insert_node_at(int idx, int n);	// ������ ��ġ(idx)�� �߰�

	// ���� �����
	int pop_front();	// �� �� ��� ����� ���� ��� ���
	int pop_back();		// �� �� ��� ����� ���� ��� ���
	int pop_node_at(int idx);	// idx ��ġ�� ��� ����
	void remove_node(int n);	// ���� ���� ��� �Ѱ� ����
	void delete_list();		// linked_list ��ü ����

	// ����
	void replace_value_at(int idx, int n);

	// �˻� �� ǥ��
	int list_size();		// linked_list ũ�� ���
	void display_contents();	// linked_list�� ���� ���
	int search_value(int n);	// �� �˻�
	
};

// ���� �����
void s_linked_list::push_front(int n) {
	node* ptr = new node;	// �� ����� �޸� �Ҵ�
	ptr->next = head;
	ptr->data = n;
	head = ptr;
	if (ptr->next == nullptr) {
		tail = ptr;
	}
	size++;
}

void s_linked_list::push_back(int n) {
	node* tmp = new node;	// �� ����� �޸� �Ҵ�
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
		cout << "�ش��ε����� �������� �ʽ��ϴ�." << endl;
	}
	else if (idx == 0) {	// idx == 0�� push_front(n)�� ����.
		push_front(n);
	}
	else if (idx == size) {	// idx == size�� push_back(n)�� ����.
		push_back(n);
	}
	else {
		node* ptr = head;
		node* tmp = ptr;
		node* new_node = new node;
		new_node->data = n;
		new_node->next = nullptr;	// �� ��� �ʱ�ȭ
		for (int i = 0; i < idx; i++) {
			tmp = ptr;		// �� ����� ���� ��� ��ġ
			ptr = ptr->next;	// �� ����� ��ġ
		}
		tmp->next = new_node;
		new_node->next = ptr;
		size++;
	}
}

// ���� ����
int s_linked_list::pop_front() {
	if (head == nullptr) {
		cout << "linked_list��  ������ϴ�." << endl;
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
		cout << "linked_list�� ������ϴ�." << endl;
		exit(1);
	}
	node* ptr = head;
	node* tmp = new node;
	while (ptr->next != nullptr) {
		tmp = ptr;
		ptr = ptr->next;
	}
	int value = ptr->data;
	if (ptr == head) {	// pop_back()���� ���� ����Ʈ�� ����
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
		cout << "�ش� �ε����� �������� �ʽ��ϴٴ�." << endl;
	}
	else if (size == 0) {
		cout << "linked list�� ����ֽ��ϴ�." << endl;
	}
	else if (idx == 0) {	// idx == 0�� pop_front()�� ����.
		value = pop_front();
	}
	else if (idx == size - 1) {
		value = pop_back();
	}
	else {
		node* ptr = head;
		node* tmp = ptr;
		for (int i = 0; i < idx; i++) {
			tmp = ptr;		// ������ ����� ���� ��� ��ġ
			ptr = ptr->next;	// ������ ��� ��ġ
		}
		value = ptr->data;	// ���� ��
		tmp->next = ptr->next;	// ������ ��带 ���� ����
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
			tmp = ptr;		// ���� ���
			ptr = ptr->next;	// �������
		}
	}

	if (ptr == nullptr) {
		cout << n << "���� ���� �������� �ʽ��ϴ�." << endl;
	}
	else if (size == 1) {
		head == nullptr;
		tail == nullptr;
	}
	else {
		size--;
		cout << ptr->data << "���� ��带 �ϳ� ����ϴ�." << endl;
		tmp->next = ptr->next;	// ������ ��带 ���� ����
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
	cout << "����Ʈ�� �����Ǿ����ϴ�." << endl;
}

// ����
void s_linked_list::replace_value_at(int idx, int n) {
	node* ptr = head;
	if (size == 0) {
		cout << "linked list�� ����ֽ��ϴ�." << endl;
		exit(1);
	}
	else if (size <= idx || 0 > idx) {
		cout << "�ش� �ε����� �������� �ʽ��ϴ�." << endl;
	}
	else {
		for (int i = 0; i < idx; i++) {
			ptr = ptr->next;	//�� �����ġ
		}
		ptr->data = n;
	}
}

// �˻� �� ǥ��
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
			cout << n << "�� " << idx << "�� �ֽ��ϴ�." << endl;
			isFind = true;
			break;
		}
		ptr = ptr->next;
		idx++;
	}

	if (isFind == false) {
		cout << n << "�� ����Ʈ �ȿ� �����ϴ�." << endl;
		return -1;
	}
	else {
		return idx;
	}
}
int main() {
	s_linked_list sl_list;
	sl_list.push_front(1);
	std::cout << sl_list.pop_back();


	sl_list.push_back(10);
	sl_list.push_back(11);
	sl_list.push_back(14);
	sl_list.push_back(18);
	sl_list.push_back(20);
	sl_list.push_back(27);
	sl_list.display_contents(); // �ǵڿ� �ֱ� �׽�Ʈ

	sl_list.insert_node_at(2, 7);
	sl_list.display_contents();    // ������ ��ҿ� �ֱ� �׽�Ʈ

	sl_list.push_front(15);
	sl_list.display_contents();    // �Ǿտ� �ֱ� �׽�Ʈ

	sl_list.search_value(10);
	sl_list.search_value(20);

	std::cout << sl_list.pop_back() << " deleted at back\n";
	sl_list.display_contents();

	std::cout << sl_list.pop_front() << " deleted at front\n";
	sl_list.display_contents();

	std::cout << sl_list.pop_node_at(3) << " deleted at 3\n";
	sl_list.display_contents();

	sl_list.remove_node(7);
	sl_list.display_contents();
	std::cout << "����Ʈ�� ũ���" << sl_list.list_size() << "\n";



	return 0;
}