// baekjoon 14502

#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans = 0;
int virusMap[8][8];
int tmp[8][8];
queue<pair<int, int>> virus;
vector<pair<int, int>> space;
vector<pair<int, int>> wall;
int check[64];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

bool isSafe(int i, int j) {
    if (i < 0 || i > N - 1 || j < 0 || j > M - 1) return false;
    return true;
}

int BFS() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tmp[i][j] = virusMap[i][j];
        }
    }

    queue<pair<int, int>> Q;
    Q = virus;

    while (!Q.empty()) {
        int cur_i = Q.front().first;
        int cur_j = Q.front().second;
        Q.pop();
        tmp[cur_i][cur_j] = 2;

        for (int idx = 0; idx < 4; idx++) {
            int new_i = cur_i + di[idx];
            int new_j = cur_j + dj[idx];
            if (!isSafe(new_i, new_j) || tmp[new_i][new_j] != 0) continue;
            tmp[new_i][new_j] = 2;
            Q.push({new_i, new_j});
        }
    }

    int size = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == 0) size++;
        }
    }

    return size;
}

void solution(int idx, int cnt) {
    if (cnt == 3) {
        for (int i = 0; i < space.size(); i++) {
            if (check[i]) {
                wall.push_back(space[i]);
            }
        }
        for (int i = 0; i < wall.size(); i++) {
            virusMap[wall[i].first][wall[i].second] = 1;
        }
        // 안전 영역 크기 계산
        int size = BFS();
        ans = max(ans, size);

        for (int i = 0; i < wall.size(); i++) {
            virusMap[wall[i].first][wall[i].second] = 0;
        }
        wall.clear();
        return;
    }

    for (int i = idx; i < space.size(); i++) {
        if (check[i]) continue;
        check[i] = 1;
        solution(i, cnt + 1);
        check[i] = 0;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> virusMap[i][j];
            if (virusMap[i][j] == 2) virus.push({i, j});
            if (virusMap[i][j] == 0) space.push_back({i, j});
        }
    }
    solution(0, 0);
    cout << ans;
}
