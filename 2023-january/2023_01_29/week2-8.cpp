// programmers week2-8
// 디펜스 게임
// priority queue 사용
// : 현재 차례를 포함하여 지금까지 공격한 round 중 적의 개수가 가장 많았던 round에 무적권 사용

#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    int answer = 0;
    for (int i = 0; i < enemy.size(); i++) {
        n -= enemy[i];
        pq.push(enemy[i]);
        if (n < 0) {
            if (k > 0) {
                n += pq.top();
                pq.pop();
                k--;
            } else {
                answer = i;
                break;
            }
        }

    }
    if (n >= 0) answer = enemy.size();
    return answer;
}