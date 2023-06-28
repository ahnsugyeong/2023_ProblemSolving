// baekjoon 14889

#include <bits/stdc++.h>

using namespace std;

int N;
int S[20][20];
bool check[20];
int ans = INT_MAX;

void DFS(int cnt, int idx) {
    if (cnt == N / 2) {
        int A_sum = 0;
        int B_sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (check[i] && check[j]) {
                    A_sum += S[i][j];
                }
                if (!check[i] && !check[j]) {
                    B_sum += S[i][j];
                }
            }
        }

        ans = min(ans, abs(A_sum - B_sum));
        return;
    }

    for (int i = idx; i < N; i++) {
        if (check[i]) continue;

        check[i] = true;
        DFS(cnt + 1, i);
        check[i] = false;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    DFS(0, 0);

    cout << ans;

    return 0;
}