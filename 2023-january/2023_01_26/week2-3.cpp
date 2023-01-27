// programmers week2-3
// 땅따먹기
// Dynamic Programming

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> land) {

    for (int i = 1; i < land.size(); i++) {
        land[i][0] += max(land[i - 1][1], max(land[i - 1][2], land[i - 1][3]));
        land[i][1] += max(land[i - 1][0], max(land[i - 1][2], land[i - 1][3]));
        land[i][2] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][3]));
        land[i][3] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][2]));
    }

    int res = 0;
    for (int i = 0; i < 4; i++) {
        res = max(res, land[land.size() - 1][i]);
    }

    return res;
}