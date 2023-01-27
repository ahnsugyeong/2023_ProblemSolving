// programmers week2-5
// 숫자 게임

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    int answer = 0;
    int a = 0, b = 0;
    while (a < A.size() && b < B.size()) {
        if (A[a] < B[b]) {
            answer++;
            a++;
            b++;
        } else a++;

    }
    return answer;
}