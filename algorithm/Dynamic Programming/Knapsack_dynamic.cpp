#include <iostream>
#include <algorithm>
using namespace std;

int Knapsack_dynamic(int w, int* wt, int* v, int n) {
    // w: 배낭의 무게 한도, wt: 각 물건의 무게
    // v: 각 물건의 가치, n: 물건의 갯수

        // DP 위한 2차원 배열 초기화
    int** kp_dynamic = new int* [w];
    for (int i = 0; i < w; i++) {
        kp_dynamic[i] = new int[n];
    }

    // 각 칸을 돌며
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || j == 0) {
                // 0번째 행, 0번째 열은 0으로 세팅.
                kp_dynamic[i][j] = 0;
            }
            else if (wt[i - 1] <= j) {
                // 위의 점화식을 그대로 적용.
                kp_dynamic[i][j] = max(v[i - 1] + kp_dynamic[i - 1][j - wt[i - 1]], kp_dynamic[i - 1][j]);
            }
            else {
                kp_dynamic[i][j] = kp_dynamic[i - 1][j];
            }
        }
        return kp_dynamic[n][w];
    }
}