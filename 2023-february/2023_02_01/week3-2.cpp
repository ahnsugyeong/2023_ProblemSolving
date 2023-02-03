// programmers week3-2
// 무인도 여행
// BFS

#include <bits/stdc++.h>

using namespace std;

int island[100][100];
bool visited[100][100];
vector<pair<int, int>> V;
vector<int> days;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};


vector<int> solution(vector<string> maps) {
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'X') continue;
            island[i][j] = maps[i][j] - '0';
            V.push_back({i, j});
        }
    }

    for (auto ele: V) {
        if (!island[ele.first][ele.second] || visited[ele.first][ele.second]) continue;

        int day = 0;
        queue<pair<int, int>> Q;
        Q.push(ele);
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            day += island[cur.first][cur.second];
            visited[cur.first][cur.second] = true;

            for (int idx = 0; idx < 4; idx++) {
                int new_i = cur.first + di[idx];
                int new_j = cur.second + dj[idx];
                if (new_i < 0 || new_i > maps.size() - 1 || new_j < 0 || new_j > maps[0].size() - 1) continue;
                if (!island[new_i][new_j] || visited[new_i][new_j]) continue;
                visited[new_i][new_j] = true;
                Q.push({new_i, new_j});
            }
        }
        days.push_back(day);
    }
    sort(days.begin(), days.end());

    if (days.size() == 0) days.push_back(-1);
    return days;
}

int main() {
    solution({"X591X", "X1X5X", "X231X", "1XXX1"});

}