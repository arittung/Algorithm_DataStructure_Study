#include <iostream>
using namespace std;

void Mergetwoarray(int *arr, int left, int mid, int right) {
	int fidx, ridx, sidx, i;
	fidx = left;
	ridx = mid + 1;
	sidx = left;
	int *sortArr = new int[sizeof(int) * (right + 1)];
	
	/*분할 정렬된 list의 합병*/
	while (fidx <= mid && ridx <= right) {
		if (arr[fidx] <= arr[ridx]) {
			sortArr[sidx] = arr[fidx++];
		}
		else {
			sortArr[sidx] = arr[ridx++];
		}
		cout << "First: " << sortArr[sidx];
		sidx++;
	}

	/*남아 있는 값들을 일괄 복사*/
	if (fidx > mid) {
		for (i = ridx; i <= right; i++, sidx++) {
			sortArr[sidx] = arr[i];
			cout << "Second: " << sortArr[sidx];
		}
	}
	else {
		for (i = fidx; i <= mid; i++, sidx++) {
			sortArr[sidx] = arr[i];
			cout << "Second: " << sortArr[sidx];
		}
	}

	//배열 sortArr[](임시 배열)의 리스트를 배열 list[]로 재복사
	cout << "Result: ";
	for (i = left; i <= right; i++) {
		arr[i] = sortArr[i];
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] sortArr;
	
}

//합병 정렬
void MergeSort(int *arr, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left < right) / 2;	// 중간 위치 계산하여 리스트를 균등 분할 - 분할(Divide)
		MergeSort(arr, left, mid);	// 앞쪽 부분 리스트 정렬 - 정렬(Conquer)
		MergeSort(arr, mid + 1, right);	// 앞쪽 부분 리스트 정렬 - 정렬(Conquer)
		Mergetwoarray(arr, left, mid, right);	//정렬된 2개의 부분 배열 합병하는 과정
	}
}

int main(){
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;
	cout << "Array: ";
	for (i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) -1 );
	
	cout << "Sorted Array : ";
	for (i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}