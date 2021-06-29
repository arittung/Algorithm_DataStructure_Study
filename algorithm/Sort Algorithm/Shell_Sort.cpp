#include <iostream>
using namespace std;

// first ���� �����ϴ� �κ� ����Ʈ�� ������ ���� ���� ����.
void gap_insertion(int* arr, int first, int last, int gap) {

	// ���� ���Ŀ��� ù ��° ���Ҵ� ������ �ʿ� �����Ƿ� i = first + gap
	// �� �ݺ����� i ���� gap �����ָ� �κ� ����Ʈ ���� ���� ����
	for (int i = first + gap; i <= last; i += gap) {		
		
		int key = arr[i];
		int j;

		// key �� ������ �迭�� ������ �����ϸ鼭 key���� �� ��ġ ã��.
		for (j = i - gap; j >= first && arr[j] > key; j -= gap) {
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}

void ShellSort(int* arr, int n) {
	
	// �ʱ� gap �� :  �迭�� ũ�� n / 2

	for (int gap = n / 2; gap > 0; gap /= 2) {
		// ¦���� ���, 1 �����ִ� ���� ���ɿ� ������ ��.
		if (gap % 2 == 0) {
			gap++;
		}

		for (int i = 0; i < gap; i++) {
			gap_insertion(arr, i, n - 1, gap);
		}
	}
}



int main() {
	int arr[8] = { 3, 6, 7, 1, 2, 4, 8, 5 };

	ShellSort(arr, sizeof(arr) / sizeof(int));

	// ��� Ȯ��
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}