// programmers week3-7
// 숫자 변환하기

#include <bits/stdc++.h>

using namespace std;

bool visited[1000001];

int solution(int x, int y, int n) {
    queue<pair<int, int>> Q;
    Q.push({x, 0});
    while (!Q.empty()) {
        int num = Q.front().first;
        int cnt = Q.front().second;

        Q.pop();
        if (num == y) return cnt;
        visited[num] = true;

        if (num + n <= y && !visited[num + n]) {
            Q.push({num + n, cnt + 1});
            visited[num + n] = true;
        }
        if (num * 2 <= y && !visited[num * 2]) {
            Q.push({num * 2, cnt + 1});
            visited[num * 2] = true;
        }
        if (num * 3 <= y && !visited[num * 3]) {
            Q.push({num * 3, cnt + 1});
            visited[num * 3] = true;
        }

    }
    return -1;
}