#include <iostream>
using namespace std;

int LinearSearch(int* arr, int size, int n) {
	
	for (int i = 0; i < size; i++) {
		if (arr[i] == n) {
			return i;
		}
	}
	return -1;
}

int main() {
	int arr[5] = { 5, 3, 2, 4, 1 };

	// 찾는 값의 index 리턴
	int idx = LinearSearch(arr, sizeof(arr) / sizeof(int), 4);

	if (idx == -1) {
		cout << "Fail to search!" << endl;
	}
	else {
		cout << "Success to search! : " << idx << endl;
	}
	return 0;
}