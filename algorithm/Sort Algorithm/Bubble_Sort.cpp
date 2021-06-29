#include <iostream>
using namespace std;

void BubbleSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {

			if (arr[i] > arr[j]) {

				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}


int main() {
	int arr[8] = { 3, 6, 7, 1, 2, 4, 8, 5 };

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	// 결과 확인
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}