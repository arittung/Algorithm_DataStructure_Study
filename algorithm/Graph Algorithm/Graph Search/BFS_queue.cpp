#include <iostream>
#include <queue>
#include <vector>

using namespace std;


void bfs(int start, vector<vector<int>> arr, vector<bool> visit, vector<int>& res) {
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		// 큐에 값이 있는 경우 = 아직 방문하지 않은 노드 존재
		int x = q.front();
		q.pop();
		//cout << x << " ";
		res.push_back(x);

		for (int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i];

			if (!visit[y]) {
				
				q.push(y);

				visit[y] = true;
			}
		}
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
	vector<vector<int>> arr(n);
	vector<bool> visit(n, 0);
	vector<int> res;

	// 1과 2를 연결 
	arr[1].push_back(2); 
	arr[2].push_back(1); 
	
	// 1과 3을 연결 
	arr[1].push_back(3); 
	arr[3].push_back(1); 
	
	// 2와 4를 연결 
	arr[2].push_back(4); 
	arr[4].push_back(2); 
	
	// 2와 5를 연결 
	arr[2].push_back(5); 
	arr[5].push_back(2); 
	
	// 4와 8을 연결 
	arr[4].push_back(8); 
	arr[8].push_back(4); 
	
	// 5와 9를 연결 
	arr[5].push_back(9); 
	arr[9].push_back(5); 
	
	// 3과 6을 연결 
	arr[3].push_back(6); 
	arr[6].push_back(3); 
	
	// 3과 7을 연결 
	arr[3].push_back(7); 
	arr[7].push_back(3);

	//print(arr);

	// 1번 node부터 bfs 실행
	bfs(1, arr, visit, res);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}