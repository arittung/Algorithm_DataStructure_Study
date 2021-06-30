#include <iostream>
using namespace std;

void swap(int* arr, int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void InsertionSort(int* arr, int n) {
	for (int i = 0; i < n-1; i++) {
		int j = i;
		while (arr[j] > arr[j + 1]) {
			swap(arr, j, j + 1);
			j--;
		}
	}
}

int main() {
	int arr[8] = { 3, 6, 7, 1, 2, 4, 8, 5 };

	InsertionSort(arr, sizeof(arr) / sizeof(int));

	// 결과 확인
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
