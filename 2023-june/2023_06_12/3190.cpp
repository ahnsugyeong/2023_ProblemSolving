// baekjoon 3190

#include <bits/stdc++.h>

using namespace std;

typedef struct Pos {
    int i;
    int j;
    int dir;    // 0: 상, 1: 우, 2: 하, 3: 좌
};

int N, K, L;
int sec = 0;
int board[100][100];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
queue<pair<int, char>> change;
deque<Pos> snake;

void input() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int first, second;
        cin >> first >> second;
        board[first - 1][second - 1] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;  // L: 왼쪽 D: 오른쪽
        change.push({X, C});
    }
    snake.push_back({0, 0, 1});
    board[0][0] = 2;
}

bool isSafe(Pos pos) {
    int i = pos.i;
    int j = pos.j;
    int dir = pos.dir;

    // 벽에 부딪힌 경우
    if (i + di[dir] < 0 || i + di[dir] > N - 1 || j + dj[dir] < 0 || j + dj[dir] > N - 1) return false;
    // 자신의 몸과 부딪힌 경우 (snake[0]만 부딪힐 가능성 있음)
    if (board[i + di[dir]][j + dj[dir]] == 2) return false;
    return true;
}

bool move() {
    if (!change.empty()) {
        if (change.front().first == sec) {
            char C = change.front().second;
            if (C == 'L') { // 왼쪽
                if (snake[0].dir == 0) snake[0].dir = 3;
                else snake[0].dir--;
            } else if (C == 'D') {  // 오른쪽
                if (snake[0].dir == 3) snake[0].dir = 0;
                else snake[0].dir++;
            }
            change.pop();
        }
    }

    bool apple = false;
    // 머리 이동
    if (isSafe(snake[0])) {
        int new_i = snake[0].i + di[snake[0].dir];
        int new_j = snake[0].j + dj[snake[0].dir];
        if (board[new_i][new_j] == 1) {
            apple = true;   // 사과 먹기
        }
        snake.push_front({new_i, new_j, snake[0].dir});
        board[new_i][new_j] = 2;
    } else {
        return false;
    }

    // 사과 안 먹었으면 마지막 꼬리 삭제
    if (!apple) {
        board[snake.back().i][snake.back().j] = 0;
        snake.pop_back();
    }
    return true;
}


int main() {
    input();
    while (move()) {
        sec++;
    }
    sec++;
    cout << sec;
    return 0;
}