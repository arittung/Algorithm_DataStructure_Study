#include <iostream>
using namespace std;

// first 부터 시작하는 부분 리스트를 구성해 삽입 정렬 시행.
void gap_insertion(int* arr, int first, int last, int gap) {

	// 삽입 정렬에서 첫 번째 원소는 정렬할 필요 없으므로 i = first + gap
	// 각 반복별로 i 값에 gap 더해주며 부분 리스트 삽입 정렬 구현
	for (int i = first + gap; i <= last; i += gap) {		
		
		int key = arr[i];
		int j;

		// key 값 이전의 배열의 값들을 조사하면서 key값이 들어갈 위치 찾음.
		for (j = i - gap; j >= first && arr[j] > key; j -= gap) {
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}

void ShellSort(int* arr, int n) {
	
	// 초기 gap 값 :  배열의 크기 n / 2

	for (int gap = n / 2; gap > 0; gap /= 2) {
		// 짝수일 경우, 1 더해주는 것이 성능에 도움이 됨.
		if (gap % 2 == 0) {
			gap++;
		}

		for (int i = 0; i < gap; i++) {
			gap_insertion(arr, i, n - 1, gap);
		}
	}
}



int main() {
	int arr[8] = { 3, 6, 7, 1, 2, 4, 8, 5 };

	ShellSort(arr, sizeof(arr) / sizeof(int));

	// 결과 확인
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}