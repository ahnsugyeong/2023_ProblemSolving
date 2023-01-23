// programmers week1-5
// 멀리 뛰기

#include <bits/stdc++.h>

using namespace std;

int dp[2001];

long long solution(int n) {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    return dp[n];
}
