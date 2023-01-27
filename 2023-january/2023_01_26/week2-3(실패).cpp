// programmers week2-3
// 땅따먹기

#include <bits/stdc++.h>

using namespace std;

int maxVal(vector<vector<int>> land, int col, int row) {
    int val = 0;
    for (int i = 0; i < 4; i++) {
        if (i == row) continue;
        val = max(val, land[col - 1][i]);
    }
    return val;
}

int solution(vector<vector<int>> land) {

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            land[i][j] += maxVal(land, i, j);
        }
    }

    int res = 0;
    for (int i = 0; i < 4; i++) {
        res = max(res, land[land.size() - 1][i]);
    }

    return res;
}