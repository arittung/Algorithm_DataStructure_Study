#include <iostream>
using namespace std;

int number = 4;			// ��� ��
int INF = 10000000;		// ���Ѵ� ��.

int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydwarshall() {
	// ��� �׷��� �ʱ�ȭ
	int** d = new int* [number];
	for (int i = 0; i < number; i++) {
		d[i] = new int[number];
		
	}

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k : ���İ��� ���
	for (int k = 0; k < number; k++) {
		// i : ��� ���
		for (int i = 0; i < number; i++) {
			// j : ���� ���
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// ��� ���
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