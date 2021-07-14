#include <iostream>
using namespace std;

void SelectSort(int arr[], int n) {
	int i, j;
	int maxIdx;
	int temp;

	for (i = 0; i < n; i++) {
		maxIdx = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[maxIdx]) {
				maxIdx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

int main() {
	int arr[4] = { 3, 4, 2, 1 };
	int i;
	SelectSort(arr, sizeof(arr) / sizeof(int));
	for (i = 0; i < 4; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}