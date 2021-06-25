#include <iostream>
using namespace std;

int findMax(int* a, int n) {
	if (n == 1) {
		return a[0];
	}

	int max = findMax(a, n - 1);

	if (max > a[n - 1]) {
		return max;
	}
	else {
		return a[n - 1];
	}
}

int main() {
	int a[5] = { 6, 3, 9, 1, 7 };
	cout << findMax(a, 5);

	return 0;
}