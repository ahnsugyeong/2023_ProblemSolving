// programmers week5-5
// N-Queen
// Backtracking

#include <bits/stdc++.h>

using namespace std;

int chess[12];
int answer = 0;

bool isValid(int depth) {
    for (int i = 0; i < depth; i++) {
        if (chess[depth] == chess[i] || abs(chess[depth] - chess[i]) == depth - i) return false;
    }
    return true;
}

void DFS(int n, int depth) {
    if (depth == n) {
        answer++;
        return;
    }
    for (int i = 0; i < n; i++) {
        chess[depth] = i;   // queen 배치
        if (isValid(depth)) DFS(n, depth + 1);
    }
}

int solution(int n) {
    DFS(n, 0);
    return answer;
}