// programmers week4-5
// 야근 지수

#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq;
    for (auto work: works) pq.push(work);
    while (n > 0 && !pq.empty()) {
        int cur = pq.top();
        pq.pop();
        n--;
        if (cur == 1) continue;
        pq.push(cur - 1);
    }
    long long answer = 0;
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        answer += cur * cur;
    }
    return answer;
}