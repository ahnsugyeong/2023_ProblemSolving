// programmers week5-1
// 점프와 순간 이동

#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int ans = 0;

    while (n) {
        if (n % 2 == 0) n /= 2;
        else {
            n -= 1;
            ans++;
        }
    }
    return ans;
}