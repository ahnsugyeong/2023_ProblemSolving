// programmers week5-5
// N-Queen
// dynamic programming -> 접근 잘못 됨. 백트래킹으로 다시!

#include <bits/stdc++.h>

using namespace std;

using namespace std;

int dp[13];

int solution(int n) {
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 0;
    dp[4] = 2;

    for (int i = 5; i <= 12; i++) {
        if (i % 2 == 0) dp[i] = dp[i - 1] * 4;
        else dp[i] = dp[i - 1] * 4 + 2;
    }
    return dp[n];
}

int main() {
    cout << solution(5) << '\n';

}