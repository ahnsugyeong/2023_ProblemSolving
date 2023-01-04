// baekjoon 2146

#include <bits/stdc++.h>

using namespace std;

int M, N, H;
int tomato[100][100][100];
bool visited[100][100][100];

/*
 * 0, 0, 1
 * 0, 1, 0
 * 0, 1, 1
 * 1, 0, 0
 * 1, 0, 1
 * 1, 1, 0
 * 1, 1, 1
 */

int di[7] = {0, 0, 0, 1, 1, 1, 1};
int dj[7] = {0, 1, 1, 0, 0, 1, 1};
int dk[7] = {1, 0, 1, 0, 1, 0, 1};

class Tomato {
    int i;
    int j;
    int k;

    Tomato(int _i, int _j, int _k) {
        this.i = _i;
        this.j = _j;
        this.k = _k;
    };
};

bool safe(int i, int j, int k) {
    if (i < 0 || i > H - 1 || j < 0 || j > N - 1 || k < 0 || k > M - 1) return false;
    else return true;
}

void BFS(int i, int j, int k) {
    queue<Tomato> Q;
    Q.push(Tomato(i, j, k));
    while (!Q.empty()) {
        int cur_i = Q.front().i;
        int cur_j = Q.front().j;
        int cur_k = Q.front().k;
        Q.pop();
        visited[cur_i][cur_j][cur_k] = true;

        for (int index = 0; index < 7; index++) {
            int new_i = cur_i + di[index];
            int new_j = cur_j + dj[index];
            int new_k = cur_k + dk[index];
            if (!safe(new_i, new_j, new_k) || visited[new_i][new_j][new_k]) continue;
            visited[new_i][new_j][new_k] = true;
            Q.push(Tomato(new_i, new_j, new_k));
        }
    }
}

int main() {
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k +) {
                cin >> tomato[i][j][k];
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k +) {
                if(tomato[i])
                cin >> tomato[i][j][k];
            }
        }
    }


    return 0;
}