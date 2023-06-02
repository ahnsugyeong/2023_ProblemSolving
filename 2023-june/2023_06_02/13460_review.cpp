// baekjoon 13460 review

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
    while (board[i + di[idx]][j + dj[idx]] != '#' && board[i][j] != 'O') {
        i += di[idx];
        j += dj[idx];
        dis++;
    }
    return dis;
}


int BFS() {

    while (!Q.empty()) {
        Bead bead = Q.front();
        pair<int, int> cur_R = bead.R;
        pair<int, int> cur_B = bead.B;
        int cur_cnt = bead.cnt;
        Q.pop();

        if (cur_cnt >= 10) return -1;


        for (int idx = 0; idx < 4; idx++) {
            pair<int, int> new_R = cur_R;
            pair<int, int> new_B = cur_B;
            int new_cnt = cur_cnt + 1;

            // R 이동
            int dis_R = moveBead(new_R.first, new_R.second, idx);
            // B 이동
            int dis_B = moveBead(new_B.first, new_B.second, idx);

//            printf("R = {%d, %d} -> %c\n", new_R.first, new_R.second, board[new_R.first][new_R.second]);
//            printf("B = {%d, %d} -> %c\n\n", new_B.first, new_B.second, board[new_R.first][new_R.second]);

            // 구슬이 구멍에 빠진 경우
            if (board[new_B.first][new_B.second] == 'O') continue;
            if (board[new_R.first][new_R.second] == 'O') return new_cnt;


            // 구슬이 겹치는 경우
            if (new_R == new_B) {
                if (dis_R < dis_B) {
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
    pair<int, int> tmp_R, tmp_B;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++) {
            board[i][j] = tmp[j];
            if (board[i][j] == 'R') {
                tmp_R = {i, j};
            } else if (board[i][j] == 'B') {
                tmp_B = {i, j};
            }
        }
    }

    Q.push({tmp_R, tmp_B, 0});

    cout << BFS() << '\n';

}