// baekjoon 7576
// BFS

#include <bits/stdc++.h>

using namespace std;

int M, N;
int tomato[1000][1000];
int day[1000][1000];
queue<pair<int, int>> tomatoes;

int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};

bool safe(int i, int j) {
    if (i < 0 || i > N - 1 || j < 0 || j > M - 1) return false;
    else return true;
}

void BFS() {
    while (!tomatoes.empty()) {
        int cur_i = tomatoes.front().first;
        int cur_j = tomatoes.front().second;

        tomatoes.pop();

        for (int index = 0; index < 4; index++) {
            int new_i = cur_i + di[index];
            int new_j = cur_j + dj[index];
            if (!safe(new_i, new_j) || tomato[new_i][new_j] != 0) continue;
            tomato[new_i][new_j] = 1;
            day[new_i][new_j] = day[cur_i][cur_j] + 1;
            tomatoes.push({new_i, new_j});
        }
    }
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) tomatoes.push({i, j});
        }
    }

    BFS();

    int cnt = 0;
    int minDay = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 0) cnt++;
            minDay = max(minDay, day[i][j]);
        }
    }

    if (cnt != 0) cout << -1;
    else cout << minDay;

    return 0;
}