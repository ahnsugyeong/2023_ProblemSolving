// baekjoon 7569

#include <bits/stdc++.h>

using namespace std;

class Tomato {
public:
    int i;
    int j;
    int k;

    Tomato(int _i, int _j, int _k) {
        i = _i;
        j = _j;
        k = _k;
    };
};

int M, N, H;
queue<Tomato> tomatoes;
int tomato[100][100][100];
int day[100][100][100];

/*
 * 0, 0, 1
 * 0, 1, 0
 * 0, 1, 1
 * 1, 0, 0
 * 1, 0, 1
 * 1, 1, 0
 * 1, 1, 1
 */

int di[6] = {0, 0, 0, 0, 1, -1};
int dj[6] = {0, 0, -1, 1, 0, 0};
int dk[6] = {1, -1, 0, 0, 0, 0};

bool safe(int i, int j, int k) {
    if (i < 0 || i > H - 1 || j < 0 || j > N - 1 || k < 0 || k > M - 1) return false;
    else return true;
}

void BFS() {

    while (!tomatoes.empty()) {
        int cur_i = tomatoes.front().i;
        int cur_j = tomatoes.front().j;
        int cur_k = tomatoes.front().k;

        tomatoes.pop();

        for (int index = 0; index < 6; index++) {
            int new_i = cur_i + di[index];
            int new_j = cur_j + dj[index];
            int new_k = cur_k + dk[index];
            if (!safe(new_i, new_j, new_k) || tomato[new_i][new_j][new_k] != 0) continue;
            tomato[new_i][new_j][new_k] = 1;
            day[new_i][new_j][new_k] = day[cur_i][cur_j][cur_k] + 1;
            tomatoes.push(Tomato(new_i, new_j, new_k));
        }
    }
}

int main() {
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) tomatoes.push(Tomato(i, j, k));
            }
        }
    }

    BFS();

    int cnt = 0;
    int minDay = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomato[i][j][k] == 0) cnt++;
                minDay = max(minDay, day[i][j][k]);
            }
        }
    }
    if (cnt != 0) cout << -1;
    else cout << minDay;


    return 0;
}