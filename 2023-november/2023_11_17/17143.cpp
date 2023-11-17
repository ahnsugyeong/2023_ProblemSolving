#include <iostream>
#include <vector>

using namespace std;

struct Shark {
    int s;
    int d;  // 1: 위, 2: 아래, 3: 오른쪽, 4: 왼쪽
    int z;  // 크기
};

int R, C, M;
vector<Shark> sharks[102][102];
int di[5] = {0, -1, 1, 0, 0};
int dj[5] = {0, 0, 0, 1, -1};

int catchShark(int j) {
    for (int i = 1; i <= R; i++) {
        if (sharks[i][j].empty()) continue;
        Shark shark = sharks[i][j].front();
        if (shark.d == 0 && shark.z == 0) continue;
        int sharkSize = shark.z;
        sharks[i][j].clear();
        return sharkSize;
    }
    return 0;
}

void moveShark(int i, int j) {
    Shark shark = sharks[i][j].front();

    if (shark.d == 1 || shark.d == 2) { // 위, 아래
        int total = 2 * (R - 1);
        int s = shark.s % total;
        int ni = i;
        for (int idx = 0; idx < s; idx++) {
            if (ni == 1) {
                shark.d = 2;
            }
            if (ni == R) {
                shark.d = 1;
            }
            ni = ni + di[shark.d];
        }
        sharks[ni][j].push_back(shark);
        sharks[i][j].erase(sharks[i][j].begin());

    } else if (shark.d == 3 || shark.d == 4) {   // 오른쪽, 왼쪽
        int total = 2 * (C - 1);
        int s = shark.s % total;
        int nj = j;
        for (int idx = 0; idx < s; idx++) {
            if (nj == 1) {
                shark.d = 3;
            }
            if (nj == C) {
                shark.d = 4;
            }
            nj = nj + dj[shark.d];
        }
        sharks[i][nj].push_back(shark);
        sharks[i][j].erase(sharks[i][j].begin());
    }
}

void moveSharks() {
    vector<pair<int, int>> curSharks;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (sharks[i][j].empty()) continue;
            curSharks.push_back({i, j});
        }
    }
    for (int i = 0; i < curSharks.size(); i++) {
        moveShark(curSharks[i].first, curSharks[i].second);
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (sharks[i][j].size() > 1) {
                int maxIndex = 0;
                for (int k = 0; k < sharks[i][j].size(); k++) {
                    if (sharks[i][j][k].z > sharks[i][j][maxIndex].z) {
                        maxIndex = k;
                    }
                }
                Shark shark = sharks[i][j][maxIndex];
                sharks[i][j].clear();
                sharks[i][j].push_back(shark);
            }
        }
    }
}

int main() {
    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sharks[r][c].push_back(Shark({s, d, z}));
    }

    int sum = 0;
    for (int j = 1; j <= C; j++) {
        int ans = catchShark(j);
        sum += ans;
        moveSharks();
    }

    cout << sum;

    return 0;
}