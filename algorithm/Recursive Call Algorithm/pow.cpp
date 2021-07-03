#include <iostream>
using namespace std;

long long int power(long long int x, long long int n) {
	// xÀÇ n½Â
	// ½Ã°£ ÁÙÀÌ´Â ¹ý

	if (n == 0) {
		return 1;
	}
	else if (n % 2 == 0) {
		return power(x * x, n / 2);
	}
	else {
		return x * power(x * x, (n - 1) / 2);
	}
}

long long int power2(long long int x, long long int n) {
	// xÀÇ n½Â
	if (n == 0) {
		return 1;
	}
	else {
		return x * power(x, n - 1);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int x;
	cin >> x;

	long long int res = power(x, 10);
	long long int res2 = power2(x, 10);
	cout << res << endl;
	cout << res2 << endl;
	return 0;
}