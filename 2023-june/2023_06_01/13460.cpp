// baekjoon 13460

#include <bits/stdc++.h>

using namespace std;


typedef struct Bead {
    pair<int, int> R;
    pair<int, int> B;
    int cnt;
} Bead;
int N, M;
char board[10][10];
bool visited[10][10][10][10];
int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};
queue<Bead> Q;

int moveBead(int &i, int &j, int idx) {
    int dis = 0;

    // 벽 또는 구멍을 만나면 종료
    while (board[i + di[idx]][j + dj[idx]] != '#' && board[i][j] != 'O') {
        i += di[idx];
        j += dj[idx];
        dis++;
    }
    return dis; // 구슬이 움직인 거리
}

int BFS() {

    while (!Q.empty()) {
        Bead bead = Q.front();
        pair<int, int> R = bead.R;
        pair<int, int> B = bead.B;
        int cnt = bead.cnt;
        Q.pop();

        // 10번 이하로 움직여서 성공 못 한다면 -1
        if (cnt >= 10) return -1;

        for (int idx = 0; idx < 4; idx++) {
            pair<int, int> new_R = R;
            pair<int, int> new_B = B;
            int new_cnt = cnt + 1;

            int R_dis = moveBead(new_R.first, new_R.second, idx);
            int B_dis = moveBead(new_B.first, new_B.second, idx);

            // 파란 구슬이 구멍에 들어가면 무효
            if (board[new_B.first][new_B.second] == 'O') continue;
            // 빨간 구슬이 구멍에 들어가면 성공
            if (board[new_R.first][new_R.second] == 'O') {
                return new_cnt;
            }

            // 두 구슬은 동시에 같은 칸에 있을 수 없다 -> 더 많은 거리를 움직인 구슬을 한 칸 뒤로
            if (new_R == new_B) {
                if (R_dis < B_dis) {
                    new_B.first -= di[idx];
                    new_B.second -= dj[idx];
                } else {
                    new_R.first -= di[idx];
                    new_R.second -= dj[idx];
                }
            }

            if (visited[new_R.first][new_R.second][new_B.first][new_B.second]) continue;
            visited[new_R.first][new_R.second][new_B.first][new_B.second] = true;
            Q.push({new_R, new_B, new_cnt});
        }
    }
    return -1;
}

int main() {
    pair<int, int> R_tmp, B_tmp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++) {
            board[i][j] = tmp[j];
            if (tmp[j] == 'R') {
                R_tmp = {i, j};
            } else if (tmp[j] == 'B') {
                B_tmp = {i, j};
            }
        }
    }

    // 구슬 초기 위치
    Q.push({R_tmp, B_tmp, 0});
    visited[R_tmp.first][R_tmp.second][B_tmp.first][B_tmp.second] = true;

    cout << BFS();
}

