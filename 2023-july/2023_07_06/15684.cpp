// baekjoon 15684

#include <bits/stdc++.h>

using namespace std;


int N, M, H;
int ladder[31][11];
vector<int> lines;
int ans = INT_MAX;

bool ladderGame() {
    for (int j = 1; j <= N; j++) {
        int a = 1;
        int b = j;
        while (a <= H) {
            if (ladder[a][b]) b++;
            else if (ladder[a][b - 1]) b--;
            a++;
        }
        if (b != j) return false;
    }
    return true;
}

void DFS(int maxDepth, int cnt) {
    if (cnt == maxDepth) {
        if (ladderGame()) {
            cout << maxDepth;
            exit(0);
        }
        return;
    }

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= H; i++) {
            if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;
            ladder[i][j] = 1;
            DFS(maxDepth, cnt + 1);
            ladder[i][j] = 0;

            while (!ladder[i][j - 1] && !ladder[i][j + 1]) i++;  // 사다리 놓을 수 있을 때까지 i++

        }
    }
}


int main() {
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }
    for (int i = 0; i < 4; i++) {
        DFS(i, 0);
    }
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}