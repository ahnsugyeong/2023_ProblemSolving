// baekjoon 14499

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int x, y;
int diceMap[20][20];
vector<int> orders;
// 위, 아래, 앞, 뒤, 왼쪽, 오른쪽
int dice[6] = {0, 0, 0, 0, 0, 0};

void input() {
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> diceMap[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        orders.push_back(tmp);
    }
}

void compareDiceAndMap() {
    if (diceMap[x][y] == 0) diceMap[x][y] = dice[1];
    else {
        dice[1] = diceMap[x][y];
        diceMap[x][y] = 0;
    }
}

void rollEast() {
    if (y + 1 > M - 1) return;

    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[1];
    dice[1] = dice[5];
    dice[5] = tmp;

    y++;
    compareDiceAndMap();
    cout << dice[0] << '\n';
}

void rollWest() {
    if (y - 1 < 0) return;

    int tmp = dice[0];
    dice[0] = dice[5];
    dice[5] = dice[1];
    dice[1] = dice[4];
    dice[4] = tmp;

    y--;
    compareDiceAndMap();
    cout << dice[0] << '\n';
}

void rollSouth() {
    if (x + 1 > N - 1) return;

    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[1];
    dice[1] = dice[2];
    dice[2] = tmp;

    x++;
    compareDiceAndMap();
    cout << dice[0] << '\n';
}

void rollNorth() {
    if (x - 1 < 0) return;

    int tmp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[1];
    dice[1] = dice[3];
    dice[3] = tmp;

    x--;
    compareDiceAndMap();
    cout << dice[0] << '\n';
}


void solution() {
    for (int i = 0; i < orders.size(); i++) {
        switch (orders[i]) {
            case 1:
                rollEast();
                break;
            case 2:
                rollWest();
                break;
            case 3:
                rollNorth();
                break;
            case 4:
                rollSouth();
                break;

        }
    }
}


int main() {
    input();
    solution();
}