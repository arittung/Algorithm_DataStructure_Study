#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void QuickSort(vector<int> &arr, int start, int end) {
	
	if (start >= end) {		// 원소가 1개인 경우
		return;
	}

	int pivot = start;
	int i = pivot + 1;		// 왼쪽 출발 지점
	int j = end;			// 오른쪽 출발 지점

	while (i <= j) {	// 포인터가 엇갈릴때까지 반복
		
		while (i <= end && arr[i] <= arr[pivot]) {
			i++;
		}
		while (j > start && arr[j] >= arr[pivot]) {
			j--;
		}

		if (i > j) {// 엇갈리는 경우
			swap(arr, j, pivot);
		}
		else {			
			swap(arr, i, j);
		}
	}


	// 분할 계산
	QuickSort(arr, start, j - 1);
	QuickSort(arr, j + 1, end);

}

int main() {
	vector<int> arr = { 3, 6, 7, 1, 2, 4, 8, 5 };

	QuickSort(arr, 0, arr.size()-1);

	// 결과 확인
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}