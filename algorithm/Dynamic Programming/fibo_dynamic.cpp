#include <iostream>
#include <vector>
using namespace std;

long long int fibo_daynamic(long long int n, vector<long long int> &fibo_memo) {

	if (n == 1 || n == 0) {
		return n;
	}
	else if (fibo_memo[n] != 0) {
		return fibo_memo[n];
	}
	else {
		fibo_memo[n] = fibo_daynamic(n - 1, fibo_memo) + fibo_daynamic(n - 2, fibo_memo);

		//cout << fibo_memo[n] << endl;
		return fibo_memo[n];
	}
}

int main() {

	int n = 5;
	vector<long long int> fibo_memo(n+1, 0);

	cout << fibo_daynamic(n, fibo_memo) << endl;

	fibo_memo[1] = 1;
	cout << "result :";
	for (int i = 0; i <fibo_memo.size(); i++) {
		cout << fibo_memo[i] << " ";
	}
	cout << endl;

	return 0;
}
