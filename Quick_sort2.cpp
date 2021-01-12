#include <iostream>
using namespace std;

void swap(int arr[], int idx1, int idx2) {
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

void Quicksort(int arr[], int left, int right) {
	if (left >= right) {	// ���Ұ� 1���� ���
		return;
	}
	int pivot = left;
	int start = left + 1;	// ���� �������
	int end = right;		// ������ �������

	while (start <= end) {	// �����Ͱ� ������������ �ݺ�

		while (arr[pivot] >= arr[start] && start <= right) {
			start++;
		}
		while (arr[pivot] <= arr[end] && end > left) {
			end--;
		}
		if (start > end) {	// �������� ���
			swap(arr, pivot, end);
		}
		else {
			swap(arr, start, end);
		}
	}
	Quicksort(arr, left, end - 1);
	Quicksort(arr, end + 1, right);
}


int main() {
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int len = sizeof(arr) / sizeof(int);
	int i;
	Quicksort(arr, 0, len - 1);

	for (i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}