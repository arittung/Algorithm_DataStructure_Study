#include <iostream>
#include <vector>
using namespace std;


void Merge(vector<int> &sorted, vector<int> &arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;

	// 분할 정렬된 arr의 합병
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}
	

	// 남아 있는 값을 일괄 복사
	if (i > mid) {
		for (int s = j; s <= end; s++) {
			sorted[k] = arr[s];
			k++;
		}
	}
	else {
		for (int s = i; s <= mid; s++) {
			sorted[k] = arr[s];
			k++;
		}
	}

	// 정렬된 배열(sorted[])을 배열 arr로 재복사
	for (int s = start; s <= end; s++) {
		arr[s] = sorted[s];
	}
}

void MergeSort(vector<int> &sorted, vector<int> &arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;			// 분할(Divide) : 중간 위치 계산하여 리스트를 균등 분할
		MergeSort(sorted, arr, start, mid);		// 정렬(Conquer) : 앞쪽 부분 리스트 정렬
		MergeSort(sorted, arr, mid + 1, end);	// 정렬(Conquer) : 뒤쪽 부분 리스트 정렬
		Merge(sorted, arr, start, mid, end);	// 정렬된 2개의 부분 배열 합병
	}
}

int main() {
	vector<int> arr = { 3, 6, 7, 1, 2, 4, 8, 5 };
	vector<int> sorted_arr(arr.size());			// 정렬된 배열

	MergeSort(sorted_arr, arr, 0, arr.size() - 1);

	// 결과 확인
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}