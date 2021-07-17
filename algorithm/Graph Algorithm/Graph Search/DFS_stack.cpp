#include <iostream>
#include <vector>

using namespace std;

void dfs(int root, bool*visit, vector<vector<int>> node, vector<int> &res) {

	// root 노드 방문
	if (visit[root] == true) {
		return;		// 방문한 경우, 바로 빠져나옴.
	}

	visit[root] = true;	// 방문한 노드 표시
	res.push_back(root);
	//cout << root << " ";

	for (int i = 0; i < node[root].size(); i++) {	// root 노드와 인접한 정점을 모두 방문
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
	int n;	// node 개수
	n = 10;
	bool *visit = new bool[n];
	vector<vector<int>> node(n);
	vector<int> res;
	
	//1과 2연결
	node[1].push_back(2);
	node[2].push_back(1);

	// 1과 3을 연결 
	node[1].push_back(3); 
	node[3].push_back(1); 
	
	// 2과 3을 연결 
	node[2].push_back(3); 
	node[3].push_back(2); 
	
	// 2와 4를 연결 
	node[2].push_back(4); 
	node[4].push_back(2); 
	
	// 2와 5를 연결 
	node[2].push_back(5); 
	node[5].push_back(2); 
	
	// 4와 8을 연결 
	node[4].push_back(8); 
	node[8].push_back(4); 
	
	// 5와 9를 연결 
	node[5].push_back(9); 
	node[9].push_back(5); 
	
	// 3과 6을 연결 
	node[3].push_back(6); 
	node[6].push_back(3); 
	
	// 3과 7을 연결 
	node[3].push_back(7); 
	node[7].push_back(3);


	//print(node);

	// 1번 node부터 dfs 탐색 실행
	dfs(1, visit, node, res);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;

}