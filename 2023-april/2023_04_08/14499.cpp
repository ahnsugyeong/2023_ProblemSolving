#include <bits/stdc++.h>

using namespace std;

int N, M, x, y, K;
int dice[6];
int diceMap[20][20];

/*
 * 0: 위
 * 1: 뒤
 * 2: 아래
 * 3: 앞
 * 4: 왼쪽
 * 5: 오른쪽
 */

void rollEast() {
    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[2];
    dice[2] = dice[5];
    dice[5] = tmp;
}

void rollWest() {
    int tmp = dice[0];
    dice[0] = dice[5];
    dice[5] = dice[2];
    dice[2] = dice[4];
    dice[4] = tmp;
}

void rollSouth() {
    int tmp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[3];
    dice[3] = tmp;
}

void rollNorth() {
    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[2];
    dice[2] = dice[1];
    dice[1] = tmp;
}


int main() {

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> diceMap[i][j];
        }
    }

    while (K--) {
        int op;
        cin >> op;
        switch (op) {
            case 1:
                if (y + 1 > M - 1) continue;
                rollEast();
                y++;
                if (diceMap[x][y] == 0) {
                    diceMap[x][y] = dice[2];
                } else {
                    dice[2] = diceMap[x][y];
                    diceMap[x][y] = 0;
                }
                cout << dice[0] << '\n';
                break;

            case 2:
                if (y - 1 < 0) continue;
                rollWest();
                y--;
                if (diceMap[x][y] == 0) {
                    diceMap[x][y] = dice[2];
                } else {
                    dice[2] = diceMap[x][y];
                    diceMap[x][y] = 0;
                }
                cout << dice[0] << '\n';
                break;

            case 3:
                if (x - 1 < 0) continue;
                rollNorth();
                x--;
                if (diceMap[x][y] == 0) {
                    diceMap[x][y] = dice[2];
                } else {
                    dice[2] = diceMap[x][y];
                    diceMap[x][y] = 0;
                }
                cout << dice[0] << '\n';
                break;

            case 4:
                if (x + 1 > N - 1) continue;
                rollSouth();
                x++;
                if (diceMap[x][y] == 0) {
                    diceMap[x][y] = dice[2];
                } else {
                    dice[2] = diceMap[x][y];
                    diceMap[x][y] = 0;
                }
                cout << dice[0] << '\n';
                break;
        }
    }
}