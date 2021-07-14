#include <iostream>
using namespace std;

void Mergetwoarray(int *arr, int left, int mid, int right) {
	int fidx, ridx, sidx, i;
	fidx = left;
	ridx = mid + 1;
	sidx = left;
	int *sortArr = new int[sizeof(int) * (right + 1)];
	
	/*���� ���ĵ� list�� �պ�*/
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

	/*���� �ִ� ������ �ϰ� ����*/
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

	//�迭 sortArr[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
	cout << "Result: ";
	for (i = left; i <= right; i++) {
		arr[i] = sortArr[i];
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] sortArr;
	
}

//�պ� ����
void MergeSort(int *arr, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left < right) / 2;	// �߰� ��ġ ����Ͽ� ����Ʈ�� �յ� ���� - ����(Divide)
		MergeSort(arr, left, mid);	// ���� �κ� ����Ʈ ���� - ����(Conquer)
		MergeSort(arr, mid + 1, right);	// ���� �κ� ����Ʈ ���� - ����(Conquer)
		Mergetwoarray(arr, left, mid, right);	//���ĵ� 2���� �κ� �迭 �պ��ϴ� ����
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