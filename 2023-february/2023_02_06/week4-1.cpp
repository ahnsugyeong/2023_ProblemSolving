// programmers week4-1
// 점 찍기
// type casting

#include <bits/stdc++.h>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for (long long x = 0; x <= d; x += k) {
        long long dd = (long long) d * d;
        long long xx = (long long) x * x;
        long long y = sqrt(dd - xx);
        long long cnt = (long long) (y / k + 1);
        answer += cnt;
    }
    return answer;
}

int main() {
    cout << solution(1, 5);


}