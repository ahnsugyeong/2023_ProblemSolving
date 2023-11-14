#include <iostream>
#include <queue>

using namespace std;

int R, C, T;
int area[51][51];
vector<pair<int, int>> dust;
vector<pair<int, int>> cleaner;
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

void spreadDust() {
    int tmpArea[51][51];
    fill(&tmpArea[0][0], &tmpArea[50][50], 0);

    for (int i = 0; i < dust.size(); i++) {
        int cur_i = dust[i].first;
        int cur_j = dust[i].second;
        int cur_dust = area[cur_i][cur_j];

        for (int idx = 0; idx < 4; idx++) {
            int new_i = cur_i + di[idx];
            int new_j = cur_j + dj[idx];
            if (new_i < 0 || new_i > R - 1 || new_j < 0 || new_j > C - 1) continue;
            if (area[new_i][new_j] == -1) continue; // 공기청정기
            tmpArea[new_i][new_j] += cur_dust / 5;
            tmpArea[cur_i][cur_j] -= cur_dust / 5;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            area[i][j] += tmpArea[i][j];
        }
    }
}

// 반시계방향
void rotateDustUp(int pivot) {
    int cleanedDust = area[pivot][1];

    // 공기청정기 위
    for (int i = pivot - 1; i >= 0; i--) {
        area[i][0] = area[i - 1][0];
    }

    // 위
    for (int j = 0; j < C; j++) {
        area[0][j] = area[0][j + 1];
    }

    // 오른쪽
    for (int i = 0; i < pivot; i++) {
        area[i][C - 1] = area[i + 1][C - 1];
    }

    // 아래
    for (int j = C - 1; j > 1; j--) {
        area[pivot][j] = area[pivot][j - 1];
    }
    area[pivot][1] = 0;
}

// 시계방향
void rotateDustDown(int pivot) {
    // 공기청정기 아래
    for (int i = pivot + 1; i < R; i++) {
        area[i][0] = area[i + 1][0];
    }

    // 아래
    for (int j = 0; j < C; j++) {
        area[R - 1][j] = area[R - 1][j + 1];
    }

    // 오른쪽
    for (int i = R - 1; i > pivot; i--) {
        area[i][C - 1] = area[i - 1][C - 1];
    }

    // 위
    for (int j = C - 1; j > 0; j--) {
        area[pivot][j] = area[pivot][j - 1];
    }
    area[pivot][1] = 0;
}

void cleanDust() {
    auto upCleaner = cleaner[0];
    auto downCleaner = cleaner[1];
    rotateDustUp(upCleaner.first);
    rotateDustDown(downCleaner.first);
}

int calDust() {
    int cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (area[i][j] <= 0) continue;
            cnt += area[i][j];
        }
    }
    return cnt;
}


int main() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> area[i][j];
            if (area[i][j] == -1) cleaner.push_back({i, j});
        }
    }

    while (T--) {
        dust.clear();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (area[i][j] > 0) dust.push_back({i, j});
            }
        }
        spreadDust();
        cleanDust();
    }
    cout << calDust();
    return 0;
}