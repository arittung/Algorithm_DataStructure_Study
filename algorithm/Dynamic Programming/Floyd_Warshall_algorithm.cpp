#include <iostream>
using namespace std;

int number = 4;			// 노드 수
int INF = 10000000;		// 무한대 값.

int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydwarshall() {
	// 결과 그래프 초기화
	int** d = new int* [number];
	for (int i = 0; i < number; i++) {
		d[i] = new int[number];
		
	}

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k : 거쳐가는 노드
	for (int k = 0; k < number; k++) {
		// i : 출발 노드
		for (int i = 0; i < number; i++) {
			// j : 도착 노드
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// 결과 출력
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	floydwarshall();

	return 0;
}