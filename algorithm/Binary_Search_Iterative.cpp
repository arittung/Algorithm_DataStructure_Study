#include <iostream>
using namespace std;

int bitsearch(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;
		if (target == arr[mid]) {
			return mid;
		}
		else {
			if (target < arr[mid]) {
				last = mid - 1;
			}
			else {
				first = mid + 1;
			}
		}
		
	}
	return -1;
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9 };
	int length = sizeof(arr) / sizeof(int);
	int idx;
	idx = bitsearch(arr, sizeof(arr)/sizeof(int), 7);

	if (idx == -1) {
		cout << "Fail to search!" << endl;
	}
	else {
		cout << "Target saving index : " << idx << endl;
	}
	return 0;
}
