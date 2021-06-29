#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int>& arr) {
	int i, j, minIdx;
	int tmp;

	for (i = 0; i < arr.size(); i++) {
		minIdx = i;
		for (j = i + 1; j < arr.size(); j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}

		tmp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = tmp;
	}
}


int main() {
	vector<int> arr = { 3, 6, 7, 1, 2, 4, 8, 5 };

	SelectionSort(arr);

	// 결과 확인
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}