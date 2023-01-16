// baekjoon 2573
#include <bits/stdc++.h>

using namespace std;

int N, M;
int ice[300][300];
bool visited[300][300];
vector<int> V;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

void BFS(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push({i, j});
    visited[i][j] = true;
    while (!Q.empty()) {
        int cur_i = Q.front().first;
        int cur_j = Q.front().second;
        Q.pop();

        for (int k = 0; k < 4; k++) {
            int new_i = cur_i + di[k];
            int new_j = cur_j + dj[k];
            if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > M - 1) continue;
            if (ice[new_i][new_j] == 0 || visited[new_i][new_j]) continue;
            visited[new_i][new_j] = true;
            Q.push({new_i, new_j});
        }
    }
}

void melt() {
    int tmp[300][300] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int zero = 0;
            for (int k = 0; k < 4; k++) {
                int new_i = i + di[k];
                int new_j = j + dj[k];
                if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > M - 1) continue;
                if (ice[new_i][new_j] == 0) zero++;
            }
            if (ice[i][j] < zero) tmp[i][j] = 0;
            else tmp[i][j] = ice[i][j] - zero;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ice[i][j] = tmp[i][j];
        }
    }

}

int countIce() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ice[i][j] != 0 && !visited[i][j]) {
                BFS(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int solve() {
    int time = 0;

    while (1) {
        int cnt = countIce();
        if (cnt > 1) return time;
        if (cnt == 0) return 0;
        melt();
        time++;
        memset(visited, false, sizeof(visited));
    }

}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ice[i][j];
        }
    }

    int res = solve();
    cout << res;

    return 0;
}