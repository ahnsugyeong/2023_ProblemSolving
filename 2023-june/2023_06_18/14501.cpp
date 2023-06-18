// baekjoon 14500

#include <bits/stdc++.h>

using namespace std;

int N;
int T[16];
int P[16];
int dp[16];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i > 0; i--) {
        int deadLine = i + T[i];
        if (deadLine > N + 1) {
            dp[i] = dp[i + 1];
        } else {
            dp[i] = max(dp[deadLine] + P[i], dp[i + 1]);
        }
    }

    cout << dp[1] << '\n';

}