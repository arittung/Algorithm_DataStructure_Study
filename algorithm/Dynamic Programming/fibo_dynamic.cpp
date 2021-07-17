#include <iostream>
using namespace std;

long long int fibo_memo[100];

long long int fibo_daynamic(long long int n) {

	if (n<= 1) {
		return n;
	}
	else if (fibo_memo[n] != 0) {
		return fibo_memo[n];
	}
	else {
		fibo_memo[n] = fibo_daynamic(n - 1) + fibo_daynamic(n - 2);


		return fibo_memo[n];
	}
}

int main() {
	
	int n = 3;
	
	cout << fibo_daynamic(n) << endl;

	return 0;
}
