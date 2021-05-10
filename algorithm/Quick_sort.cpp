#include <iostream>
using namespace std;

void swap(int arr[], int idx1, int idx2) {
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	
	while (low <= high) {
		while (pivot > arr[low]) {
			low++;
		}
		while (pivot < arr[high]) {
			high--;
		}
		if (low <= high) {
			swap(arr, low, high);
		}
	}
	
	swap(arr, left, high);
	return high;
}

void Quicksort(int arr[], int left, int right) {
	
	if (left <= right) {
		int pivot = partition(arr, left, right);
		Quicksort(arr, left, pivot - 1);
		Quicksort(arr, pivot + 1, right);
	}
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