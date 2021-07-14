#include <iostream>
#include <algorithm>
using namespace std;

int Knapsack_dynamic(int w, int* wt, int* v, int n) {
    // w: �賶�� ���� �ѵ�, wt: �� ������ ����
    // v: �� ������ ��ġ, n: ������ ����

        // DP ���� 2���� �迭 �ʱ�ȭ
    int** kp_dynamic = new int* [w];
    for (int i = 0; i < w; i++) {
        kp_dynamic[i] = new int[n];
    }

    // �� ĭ�� ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || j == 0) {
                // 0��° ��, 0��° ���� 0���� ����.
                kp_dynamic[i][j] = 0;
            }
            else if (wt[i - 1] <= j) {
                // ���� ��ȭ���� �״�� ����.
                kp_dynamic[i][j] = max(v[i - 1] + kp_dynamic[i - 1][j - wt[i - 1]], kp_dynamic[i - 1][j]);
            }
            else {
                kp_dynamic[i][j] = kp_dynamic[i - 1][j];
            }
        }
        return kp_dynamic[n][w];
    }
}