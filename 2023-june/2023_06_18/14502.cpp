// baekjoon 14500

#include <bits/stdc++.h>

using namespace std;

int N, M;
int virusMap[8][8]; // 0: 빈 칸, 1: 벽, 2: 바이러스
vector<pair<int, int>> emptySpace;
queue<pair<int, int>> virus;
vector<pair<int, int>> wall;
bool check[64];
int ans = 0;

int calSafe() {
    int tmp[8][8];
    memcpy(tmp, virusMap, sizeof(virusMap));
    queue<pair<int, int>> virus_tmp = virus;
    while (!virus_tmp.empty()) {
        int virus_i = virus_tmp.front().first;
        int virus_j = virus_tmp.front().second;
        virus_tmp.pop();

        for (int j = virus_j + 1; j < M; j++) {
            if (tmp[virus_i][j] != 0) break;
            tmp[virus_i][j] = 2;
            virus_tmp.push({virus_i, j});
        }

        for (int j = virus_j - 1; j >= 0; j--) {
            if (tmp[virus_i][j] != 0) break;
            tmp[virus_i][j] = 2;
            virus_tmp.push({virus_i, j});
        }

        for (int i = virus_i + 1; i < N; i++) {
            if (tmp[i][virus_j] != 0) break;
            tmp[i][virus_j] = 2;
            virus_tmp.push({i, virus_j});
        }

        for (int i = virus_i - 1; i >= 0; i--) {
            if (tmp[i][virus_j] != 0) break;
            tmp[i][virus_j] = 2;
            virus_tmp.push({i, virus_j});
        }
    }

    int safe = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == 0) safe++;
        }
    }
    return safe;
}

// 새로운 벽 3개 세우기
void DFS(int idx, int cnt) {
    if (cnt == 3) {
        wall.clear();
        for (int i = 0; i < emptySpace.size(); i++) {
            if (check[i]) wall.push_back(emptySpace[i]);
        }

        for (int i = 0; i < 3; i++) {
            virusMap[wall[i].first][wall[i].second] = 1;
        }

        int safe = calSafe();
        ans = max(ans, safe);

        for (int i = 0; i < 3; i++) {
            virusMap[wall[i].first][wall[i].second] = 0;
        }

        return;
    }

    for (int i = idx; i < emptySpace.size(); i++) {
        if (check[i]) continue;
        check[i] = true;
        DFS(i, cnt + 1);
        check[i] = false;
    }
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> virusMap[i][j];
            if (virusMap[i][j] == 0) emptySpace.push_back({i, j});
            else if (virusMap[i][j] == 2) virus.push({i, j});
        }
    }

    DFS(0, 0);
}


int main() {
    input();
    cout << ans;
}