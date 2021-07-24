struct Node
{
	int data;		//������
	Node* left;		//���� �ڽĳ��
	Node* right;		//������ �ڽĳ��
};

class BinaryTreeLinkedList
{
public:
	BinaryTreeLinkedList();				//������
	~BinaryTreeLinkedList();			//�Ҹ���

	Node* CreateNode();				//��� ����
	bool GetData(Node* node, int& data);		//�� ��ȯ
	bool SetData(Node* node, int data);		//�� ����

	bool GetLeftNode(Node* parent, Node** node);	//����� ���� �ڽĳ�� ��ȯ
	bool GetRightNode(Node* parent, Node** node);	//����� ������ �ڽĳ�� ��ȯ

	bool SetLeftNode(Node* parent, Node* child);	//����� ���� �ڽĳ�� ����
	bool SetRightNode(Node* parent, Node* child);	//����� ������ �ڽĳ�� ����

	void PreorderPrint(Node* node);			//���� ��ȸ
	void InorderPrint(Node* node);			//���� ��ȸ
	void PostorderPrint(Node* node);		//���� ��ȸ

	void RemoveNode(Node* node);			//��� ����
};