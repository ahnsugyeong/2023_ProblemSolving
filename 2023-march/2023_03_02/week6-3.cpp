// programmers week6-3
// 미로 탈출
// BFS

#include <bits/stdc++.h>


using namespace std;

pair<int, int> S, L;
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
bool visited[100][100];

int BFS1(vector<string> maps) { // 출발 -> 레버
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int>> Q;
    Q.push({S, 0});
    visited[S.first][S.second] = true;

    while (!Q.empty()) {
        int cur_i = Q.front().first.first;
        int cur_j = Q.front().first.second;
        int cur_time = Q.front().second;
        Q.pop();

        for (int idx = 0; idx < 4; idx++) {
            int new_i = cur_i + di[idx];
            int new_j = cur_j + dj[idx];

            if (new_i < 0 || new_i > maps.size() - 1 || new_j < 0 || new_j > maps[0].size() - 1) continue;
            if (maps[new_i][new_j] == 'X' || visited[new_i][new_j]) continue;
            if (maps[new_i][new_j] == 'L') {
                return cur_time + 1;
            }
            visited[new_i][new_j] = true;
            Q.push({{new_i, new_j}, cur_time + 1});
        }
    }
    return -1;
}

int BFS2(vector<string> maps) { // 레버 -> 출구
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int>> Q;
    Q.push({L, 0});
    visited[L.first][L.second] = true;

    while (!Q.empty()) {
        int cur_i = Q.front().first.first;
        int cur_j = Q.front().first.second;
        int cur_time = Q.front().second;
        Q.pop();

        for (int idx = 0; idx < 4; idx++) {
            int new_i = cur_i + di[idx];
            int new_j = cur_j + dj[idx];

            if (new_i < 0 || new_i > maps.size() - 1 || new_j < 0 || new_j > maps[0].size() - 1) continue;
            if (maps[new_i][new_j] == 'X' || visited[new_i][new_j]) continue;
            if (maps[new_i][new_j] == 'E') {
                return cur_time + 1;
            }
            visited[new_i][new_j] = true;
            Q.push({{new_i, new_j}, cur_time + 1});
        }
    }
    return -1;
}


int solution(vector<string> maps) {

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'S') {
                S.first = i;
                S.second = j;
            } else if (maps[i][j] == 'L') {
                L.first = i;
                L.second = j;
            }
        }
    }

    int first = BFS1(maps);
    if (first == -1) return -1;
    int second = BFS2(maps);
    if (second == -1) return -1;

    return first + second;
}