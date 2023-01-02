// baekjoon 2146
// BFS

#include <bits/stdc++.h>

using namespace std;

int N;
int area[101][101];
bool visited[101][101];
int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};

bool safe(int i, int j) {
    if (i < 0 || i > N - 1 || j < 0 || j > N - 1) return false;
    else return true;
}

void initVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

void BFS(int i, int j, int h) {
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
            if (!safe(new_i, new_j) || visited[new_i][new_j] || area[new_i][new_j] <= h) continue;
            Q.push({new_i, new_j});
            visited[new_i][new_j] = true;
        }


    }

}

int main() {
    int minHeight = INT_MAX;
    int maxHeight = 1;
    int cnt, res = 1;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> area[i][j];
            maxHeight = max(maxHeight, area[i][j]);
            minHeight = min(minHeight, area[i][j]);
        }
    }

    for (int h = minHeight; h <= maxHeight; h++) {
        cnt = 0;
        initVisited();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] || area[i][j] <= h) continue;
                BFS(i, j, h);
                cnt++;
            }
        }

        res = max(res, cnt);
    }
    cout << res;

    return 0;
}