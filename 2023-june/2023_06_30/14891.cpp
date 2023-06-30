// baekjoon 14891

#include <bits/stdc++.h>

using namespace std;

// 0: N극, 1: S극
int gear[4][8];

// 시계 방향으로 회전
void moveGearRight(int idx) {
    int tmp = gear[idx][7];
    for (int i = 7; i > 0; i--) {
        gear[idx][i] = gear[idx][i - 1];
    }
    gear[idx][0] = tmp;

}

// 반시계 방향으로 회전
void moveGearLeft(int idx) {
    int tmp = gear[idx][0];
    for (int i = 0; i < 7; i++) {
        gear[idx][i] = gear[idx][i + 1];
    }
    gear[idx][7] = tmp;
}


int main() {
    for (int i = 0; i < 4; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 8; j++) {
            gear[i][j] = tmp[j] - '0';
        }
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int num, op;
        cin >> num >> op;
        int move[4] = {0};
        num--;
        move[num] = op;

        // 왼쪽으로 회전 검사
        for (int idx = num - 1; idx >= 0; idx--) {
            if (gear[idx + 1][6] != gear[idx][2]) {
                move[idx] = move[idx + 1] * -1;
            }
        }

        // 오른쪽으로 회전 검사
        for (int idx = num + 1; idx < 4; idx++) {
            if (gear[idx - 1][2] != gear[idx][6]) {
                move[idx] = move[idx - 1] * -1;
            }
        }

        for (int idx = 0; idx < 4; idx++) {
            if (move[idx] == 1) moveGearRight(idx);
            else if (move[idx] == -1) moveGearLeft(idx);
        }
    }

    int ans = 0;
    if (gear[0][0] == 1) ans += 1;
    if (gear[1][0] == 1) ans += 2;
    if (gear[2][0] == 1) ans += 4;
    if (gear[3][0] == 1) ans += 8;

    cout << ans;
}