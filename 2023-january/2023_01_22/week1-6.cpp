// programmers week1-6
// 테이블 해시 함수

#include <bits/stdc++.h>

using namespace std;
/*
 * 2 2 6
 * 1 5 10
 * 4 2 9
 * 3 8 3
 *
 * 4 2 9
 * 2 2 6
 * 1 5 10
 * 3 8 3
 */

int compareCol;

bool compare(vector<int> A, vector<int> B) {
    if (A[compareCol - 1] == B[compareCol - 1]) {
        return A[0] > B[0];
    } else return A[compareCol - 1] < B[compareCol - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    compareCol = col;
    sort(data.begin(), data.end(), compare);
    vector<int> V;
    for (int i = row_begin - 1; i <= row_end - 1; i++) {
        int sum = 0;
        for (int j = 0; j < data[i].size(); j++) {
            sum += data[i][j] % (i + 1);
        }
        V.push_back(sum);
    }
    int res = V[0];
    for (int i = 1; i < V.size(); i++) {
        res ^= V[i];
    }

    return res;
}