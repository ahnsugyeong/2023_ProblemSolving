// programmers week4-7
// N으로 표현

#include <bits/stdc++.h>

using namespace std;

int answer = 9;

void DFS(int N, int num, int cnt, int cur) {
    if (cnt >= 9) return;
    if (cur == num) {
        answer = min(answer, cnt);
        return;
    }
    int tmp = 0;
    for (int i = 0; i < 9 - cnt; i++) {
        tmp = tmp * 10 + N;
        DFS(N, num, cnt + 1 + i, cur + tmp);
        DFS(N, num, cnt + 1 + i, cur - tmp);
        DFS(N, num, cnt + 1 + i, cur * tmp);
        DFS(N, num, cnt + 1 + i, cur / tmp);
    }
}

int solution(int N, int number) {
    DFS(N, number, 0, 0);
    if (answer == 9) return -1;
    else return answer;
}