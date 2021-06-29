#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void QuickSort(vector<int> &arr, int start, int end) {
	
	if (start >= end) {		// ���Ұ� 1���� ���
		return;
	}

	int pivot = start;
	int i = pivot + 1;		// ���� ��� ����
	int j = end;			// ������ ��� ����

	while (i <= j) {	// �����Ͱ� ������������ �ݺ�
		
		while (i <= end && arr[i] <= arr[pivot]) {
			i++;
		}
		while (j > start && arr[j] >= arr[pivot]) {
			j--;
		}

		if (i > j) {// �������� ���
			swap(arr, j, pivot);
		}
		else {			
			swap(arr, i, j);
		}
	}


	// ���� ���
	QuickSort(arr, start, j - 1);
	QuickSort(arr, j + 1, end);

}

int main() {
	vector<int> arr = { 3, 6, 7, 1, 2, 4, 8, 5 };

	QuickSort(arr, 0, arr.size()-1);

	// ��� Ȯ��
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}