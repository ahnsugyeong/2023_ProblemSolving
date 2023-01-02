// baekjoon 2146
// DFS

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

void DFS(int i, int j, int h) {
    if (visited[i][j]) return;
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int new_i = i + di[k];
        int new_j = j + dj[k];
        if (!safe(new_i, new_j) || visited[new_i][new_j] || area[new_i][new_j] <= h) continue;
        DFS(new_i, new_j, h);
        visited[new_i][new_j] = true;
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
                DFS(i, j, h);
                cnt++;
            }
        }

        res = max(res, cnt);
    }
    cout << res;

    return 0;
}