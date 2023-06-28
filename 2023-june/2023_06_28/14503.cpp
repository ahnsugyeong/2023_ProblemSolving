// baekjoon 14503

#include <bits/stdc++.h>

using namespace std;

/*
1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.

2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
 - 바라보는 방향을 유지한 채로
 - 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
 - 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.

3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
 - 반시계 방향으로 90도 회전한다.
 - 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
 - 1번으로 돌아간다.
 */


int N, M;
int r, c;
int room[50][50];

// 0: 북, 1: 동, 2: 남, 3: 서
int d;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int cnt = 0;

void cleanRoom() {

    int i = r;
    int j = c;

    while (1) {

        // 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        if (room[i][j] == 0) {
            cnt++;
            room[i][j] = 2;
        }

        int flag = 0;
        for (int idx = 0; idx < 4; idx++) {
            // 반시계 방향으로 90도 회전
            if (d == 0) d = 3;
            else d--;

            int new_i = i + di[d];
            int new_j = j + dj[d];
            if (room[new_i][new_j] == 1) continue;

            // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
            if (room[new_i][new_j] == 0) {
                i = new_i;
                j = new_j;
                flag = 1;
                break;
            }
        }

        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        if (flag == 0) {
            int new_i = i - di[d];
            int new_j = j - dj[d];
            if (room[new_i][new_j] == 1) return;

            i = new_i;
            j = new_j;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];  // 0: 청소되지 않은 빈 칸, 1: 벽
        }
    }

    cleanRoom();

    cout << cnt;
    return 0;
}