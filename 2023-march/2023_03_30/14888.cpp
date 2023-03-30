// baekjoon 14888

#include <bits/stdc++.h>

using namespace std;

int N;
int nums[11];
int op[4];
int maxAns = INT_MIN;
int minAns = INT_MAX;

void solution(int result, int idx) {
    if (idx == N) {
        maxAns = max(maxAns, result);
        minAns = min(minAns, result);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            if (i == 0) {
                solution(result + nums[idx], idx + 1);
            } else if (i == 1) {
                solution(result - nums[idx], idx + 1);
            } else if (i == 2) {
                solution(result * nums[idx], idx + 1);
            } else if (i == 3) {
                solution(result / nums[idx], idx + 1);
            }
            op[i]++;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    solution(nums[0], 1);
    cout << maxAns << '\n' << minAns;
}