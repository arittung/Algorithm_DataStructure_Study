#include <iostream>
#include <vector>
using namespace std;


void Merge(vector<int> &sorted, vector<int> &arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;

	// ���� ���ĵ� arr�� �պ�
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
	

	// ���� �ִ� ���� �ϰ� ����
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

	// ���ĵ� �迭(sorted[])�� �迭 arr�� �纹��
	for (int s = start; s <= end; s++) {
		arr[s] = sorted[s];
	}
}

void MergeSort(vector<int> &sorted, vector<int> &arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;			// ����(Divide) : �߰� ��ġ ����Ͽ� ����Ʈ�� �յ� ����
		MergeSort(sorted, arr, start, mid);		// ����(Conquer) : ���� �κ� ����Ʈ ����
		MergeSort(sorted, arr, mid + 1, end);	// ����(Conquer) : ���� �κ� ����Ʈ ����
		Merge(sorted, arr, start, mid, end);	// ���ĵ� 2���� �κ� �迭 �պ�
	}
}

int main() {
	vector<int> arr = { 3, 6, 7, 1, 2, 4, 8, 5 };
	vector<int> sorted_arr(arr.size());			// ���ĵ� �迭

	MergeSort(sorted_arr, arr, 0, arr.size() - 1);

	// ��� Ȯ��
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}