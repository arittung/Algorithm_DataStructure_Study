#include <iostream>
using namespace std;

int bresearch(int* arr, int first, int last, int target) {
	int mid= 0;
	if (first > last) {
		mid = (first + last) / 2;
	}

	if (target == arr[mid]) {
		return mid;
	}
	else {
		if (target < arr[mid]) {
			return bresearch(arr, first, mid - 1, target);
		}
		else {
			return bresearch(arr, mid + 1, last, target);
		}
	}
	return -1;
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9 ,11, 13};
	int length = sizeof(arr) / sizeof(int);
	int idx;
	idx = bresearch(arr, 0, length - 1, 5);

	if (idx == -1) {
		cout << "Fail to search!" << endl;
	}
	else {
		cout << "Target saving index : " << idx << endl;
	}
	return 0;
}
