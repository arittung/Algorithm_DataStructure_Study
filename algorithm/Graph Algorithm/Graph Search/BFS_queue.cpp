#include <iostream>
#include <queue>
#include <vector>

using namespace std;


void bfs(int start, vector<vector<int>> arr, vector<bool> visit, vector<int>& res) {
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		// ť�� ���� �ִ� ��� = ���� �湮���� ���� ��� ����
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
	int n;	// node ����
	n = 10;
	vector<vector<int>> arr(n);
	vector<bool> visit(n, 0);
	vector<int> res;

	// 1�� 2�� ���� 
	arr[1].push_back(2); 
	arr[2].push_back(1); 
	
	// 1�� 3�� ���� 
	arr[1].push_back(3); 
	arr[3].push_back(1); 
	
	// 2�� 4�� ���� 
	arr[2].push_back(4); 
	arr[4].push_back(2); 
	
	// 2�� 5�� ���� 
	arr[2].push_back(5); 
	arr[5].push_back(2); 
	
	// 4�� 8�� ���� 
	arr[4].push_back(8); 
	arr[8].push_back(4); 
	
	// 5�� 9�� ���� 
	arr[5].push_back(9); 
	arr[9].push_back(5); 
	
	// 3�� 6�� ���� 
	arr[3].push_back(6); 
	arr[6].push_back(3); 
	
	// 3�� 7�� ���� 
	arr[3].push_back(7); 
	arr[7].push_back(3);

	//print(arr);

	// 1�� node���� bfs ����
	bfs(1, arr, visit, res);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}