#include <iostream>
#include <vector>

/*
 * (실패)
 * 1초 내에서 이동할 때 상어 간 충돌은 없어야 한다.
 * 1초를 마친 후 중복된 상어 중 하나를 제외한 나머지를 제거하는 방식으로 해결해야 한다.
 * */

using namespace std;

struct Shark {
    int s;
    int d;  // 1: 위, 2: 아래, 3: 오른쪽, 4: 왼쪽
    int z;  // 크기
};
int R, C, M;
Shark board[101][101];

int catchShark(int j) {
    for (int i = 1; i <= R; i++) {
        Shark shark = board[i][j];
        if (shark.d == 0 && shark.z == 0) continue;
        int sharkSize = shark.z;
        board[i][j].d = 0;
        board[i][j].s = 0;
        board[i][j].z = 0;
        return sharkSize;
    }
}

int di[5] = {0, -1, 1, 0, 0};
int dj[5] = {0, 0, 0, 1, -1};

void moveShark(int i, int j) {
    Shark shark = board[i][j];

    if (shark.d == 1 || shark.d == 2) { // 위, 아래
        int total = 2 * (R - 1);
        int s = shark.s % total;
        int ni = i;
        for (int idx = 0; idx < s; idx++) {
            ni = ni + di[shark.d];
            if (ni == 1) {
                shark.d = 2;
            }
            if (ni == R) {
                shark.d = 1;
            }
        }
        if (board[ni][j].d != 0 || board[ni][j].z != 0) {
            if (board[ni][j].z < shark.z) {
                board[ni][j] = shark;
                board[i][j] = Shark({0, 0, 0});
            }
        } else {
            board[ni][j] = shark;
            board[i][j] = Shark({0, 0, 0});
        }

    } else if (shark.d == 3 || shark.d == 4) {   // 오른쪽, 왼쪽
        int total = 2 * (C - 1);
        int s = shark.s % total;
        int nj = j;
        for (int idx = 0; idx < s; idx++) {
            nj = nj + dj[shark.d];
            if (nj == 1) {
                shark.d = 3;
            }
            if (nj == C) {
                shark.d = 4;
            }
        }
        if (board[i][nj].d != 0 || board[i][nj].z != 0) {
            if (board[i][nj].z < shark.z) {
                board[i][nj] = shark;
                board[i][j] = Shark({0, 0, 0});
            }
        } else {
            board[i][nj] = shark;
            board[i][j] = Shark({0, 0, 0});
        }
    }
}

void moveSharks() {
    vector<pair<int, int>> sharks;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            Shark shark = board[i][j];
            if (shark.d == 0 && shark.z == 0) continue;
            sharks.push_back({i, j});
        }
    }

    for (int i = 0; i < sharks.size(); i++) {
        moveShark(sharks[i].first, sharks[i].second);
    }
}

void print(int idx) {
    printf("idx = %d\n", idx);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            printf("%d ", board[i][j].z);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c] = Shark({s, d, z});
    }

    int result = 0;
    print(0);
    for (int j = 1; j <= C; j++) {
        result += catchShark(j);
        moveSharks();
        print(j);
    }

    cout << result;

    return 0;
}

/*
0 0 9 0 3 0
0 5 0 1 0 0
0 0 7 0 0 2
8 0 0 0 4 0

0 0 0 0 3 2
0 0 9 5 0 1
0 0 0 0 0 0
0 0 7 0 4 0
 */