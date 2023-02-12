// programmers week4-6
// 게임 맵 최단거리

#include <bits/stdc++.h>

using namespace std;


int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps) {
    int N = maps.size();
    int M = maps[0].size();

    queue<pair<pair<int, int>, int>> Q;
    Q.push({{0, 0}, 1});
    while (!Q.empty()) {
        int cur_i = Q.front().first.first;
        int cur_j = Q.front().first.second;
        int cur_cnt = Q.front().second;
        if (cur_i == N - 1 && cur_j == M - 1) return cur_cnt;
        Q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int new_i = cur_i + di[idx];
            int new_j = cur_j + dj[idx];

            if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > M - 1) continue;
            if (maps[new_i][new_j] == 0) continue;
            maps[new_i][new_j] = 0;
            Q.push({{new_i, new_j}, cur_cnt + 1});
        }
    }

    return -1;
}