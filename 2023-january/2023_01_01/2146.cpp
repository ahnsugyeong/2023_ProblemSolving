// baekjoon 2146
// BFS

#include <bits/stdc++.h>

using namespace std;

int N;
int area[101][101];
int visited[101][101];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};

bool safe(int i, int j) {
    if (i < 0 || i > N - 1 || j < 0 || j > N - 1) return false;
    else return true;
}

void initVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}

void BFS(int i, int j, int h) {
    queue<pair<int, int>> q;
    visited[i][j] = 1;
    q.push({i, j});

    while (!q.empty()) {
        int cur_i = q.front().first;
        int cur_j = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_i = cur_i + di[i];
            int new_j = cur_j + dj[i];

            if (safe(new_i, new_j) == 1 && visited[new_i][new_j] == 0 && area[new_i][new_j] > h) {
                visited[new_i][new_j] = 1;
                q.push({new_i, new_j});
            }
        }
    }
}

int main() {
    int minHeight = INT_MAX;
    int maxHeight = 0;
    int cnt, res = 0;

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