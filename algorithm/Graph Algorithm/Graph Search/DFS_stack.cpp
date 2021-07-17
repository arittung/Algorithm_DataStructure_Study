#include <iostream>
#include <vector>

using namespace std;

void dfs(int root, bool*visit, vector<vector<int>> node, vector<int> &res) {

	// root ��� �湮
	if (visit[root] == true) {
		return;		// �湮�� ���, �ٷ� ��������.
	}

	visit[root] = true;	// �湮�� ��� ǥ��
	res.push_back(root);
	//cout << root << " ";

	for (int i = 0; i < node[root].size(); i++) {	// root ���� ������ ������ ��� �湮
		int x = node[root][i];
		dfs(x, visit, node, res);
	}
}

void print(vector<vector<int>> node) {
	for (int i = 0; i < node.size(); i++) {
		for (int j = 0; j < node[i].size(); j++) {
			cout << node[i][j] << " ";
		}
		cout << endl;
	}

}

int main() {
	int n;	// node ����
	n = 10;
	bool *visit = new bool[n];
	vector<vector<int>> node(n);
	vector<int> res;
	
	//1�� 2����
	node[1].push_back(2);
	node[2].push_back(1);

	// 1�� 3�� ���� 
	node[1].push_back(3); 
	node[3].push_back(1); 
	
	// 2�� 3�� ���� 
	node[2].push_back(3); 
	node[3].push_back(2); 
	
	// 2�� 4�� ���� 
	node[2].push_back(4); 
	node[4].push_back(2); 
	
	// 2�� 5�� ���� 
	node[2].push_back(5); 
	node[5].push_back(2); 
	
	// 4�� 8�� ���� 
	node[4].push_back(8); 
	node[8].push_back(4); 
	
	// 5�� 9�� ���� 
	node[5].push_back(9); 
	node[9].push_back(5); 
	
	// 3�� 6�� ���� 
	node[3].push_back(6); 
	node[6].push_back(3); 
	
	// 3�� 7�� ���� 
	node[3].push_back(7); 
	node[7].push_back(3);


	//print(node);

	// 1�� node���� dfs Ž�� ����
	dfs(1, visit, node, res);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;

}