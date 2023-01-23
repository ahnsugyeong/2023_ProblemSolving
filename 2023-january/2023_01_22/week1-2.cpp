// programmers week1-2
// 연속 부분 수열 합의 개수

#include <bits/stdc++.h>

using namespace std;

set<int> S;

int solution(vector<int> elements) {
    int n = elements.size();
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < len; j++) {
                int idx = i + j;
                if (idx >= n) idx -= n;
                sum += elements[idx];
            }
            S.insert(sum);
        }
    }
    return S.size();
}

/*
 7 9 1 1 4

 len = 1
 7, 9, 1, 4

 len = 2
 16 = 7 + 9
 10 = 9 + 1
 2 = 1 + 1
 5 = 1 + 4
 11 = 4 + 7

 len = 3
 17 = 7 + 9 + 1
 11 = 9 + 1 + 1
 6 = 1 + 1 + 4
 12 = 1 + 4 + 7
 20 = 4 + 7 + 9

 len = 4
 18 = 7 + 9 + 1 + 1
 15 = 9 + 1 + 1 + 4
 13 = 1 + 1 + 4 + 7
 21 = 1 + 4 + 7 + 9
 21 = 4 + 7 + 9 + 1

 len = 5
 22 = 7 + 9 + 1 + 1 + 4


 */