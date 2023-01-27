// programmers week2-2
// 소수 찾기

#include <bits/stdc++.h>

using namespace std;

bool visited[8];
bool primeNum[10000000];
set<int> S;

void computePrime() {   // true: 소수 X, false: 소수
    primeNum[0] = true;
    primeNum[1] = true;
    primeNum[2] = false;
    for (int i = 2; i < 10000000; i++) {
        if (primeNum[i]) continue;
        for (int j = i * 2; j < 10000000; j += i) {
            primeNum[j] = true;
        }
    }
}

void DFS(string numbers, int len, int cnt, string num) {
    if (cnt == len) {
        S.insert(stoi(num));
        return;
    }
    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        DFS(numbers, len, cnt + 1, num + numbers[i]);
        visited[i] = false;
    }
}

int solution(string numbers) {
    computePrime();

    for (int i = 1; i <= numbers.size(); i++) {
        DFS(numbers, i, 0, "");
    }

    int res = 0;
    for (int ele: S) {
        if (!primeNum[ele]) res++;

    }

    return res;
}