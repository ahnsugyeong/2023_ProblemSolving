// baekjoon 14500

#include <bits/stdc++.h>

using namespace std;


int N, M;
int paper[500][500];
bool visited[500][500];
int ans = 0;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

void DFS(int i, int j, int cnt, int sum) {
    if (cnt == 4) {
        ans = max(ans, sum);
        return;
    }

    for (int idx = 0; idx < 4; idx++) {
        int new_i = i + di[idx];
        int new_j = j + dj[idx];

        if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > M - 1) continue;
        if (visited[new_i][new_j]) continue;

        visited[new_i][new_j] = true;
        DFS(new_i, new_j, cnt + 1, sum + paper[new_i][new_j]);
        visited[new_i][new_j] = false;
    }
}

// ㅏ, ㅓ, ㅗ, ㅜ 모양 탐색
void findTShape(int i, int j) {
    int east = j + 1;
    int west = j - 1;
    int south = i + 1;
    int north = i - 1;

    // ㅏ
    if (east < M && south < N && north >= 0) {
        int sum = paper[i][j] + paper[i][east] + paper[north][j] + paper[south][j];
        ans = max(sum, ans);
    }

    // ㅓ
    if (west >= 0 && south < N && north >= 0) {
        int sum = paper[i][j] + paper[i][west] + paper[north][j] + paper[south][j];
        ans = max(sum, ans);
    }

    // ㅗ
    if (east < M && west >= 0 && north >= 0) {
        int sum = paper[i][j] + paper[i][east] + paper[i][west] + paper[north][j];
        ans = max(sum, ans);
    }

    // ㅜ
    if (east < M && west >= 0 && south < N) {
        int sum = paper[i][j] + paper[i][east] + paper[i][west] + paper[south][j];
        ans = max(sum, ans);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            DFS(i, j, 1, paper[i][j]);
            visited[i][j] = false;
            findTShape(i, j);
        }
    }
    cout << ans;
}