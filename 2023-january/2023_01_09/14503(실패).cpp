// baekjon 14503

#include <bits/stdc++.h>

using namespace std;


int N, M;
int r, c, d;
// 0: 북쪽, 1: 동쪽, 2: 남쪽, 3: 서쪽
int area[50][50];

void input() {
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> area[i][j];
        }
    }
}

// 북->서, 서->남, 남->동, 동->북
// 0->3, 3->2, 2->1, 1->0
void nextDir() {
    if (d == 0) d = 3;
    else d--;
}

bool isNextValid() {
    int tmp_r = r, tmp_c = c;
    switch (d) {
        case 0:
            tmp_r--;
            break;
        case 1:
            tmp_c++;
            break;
        case 2:
            tmp_r++;
            break;
        case 3:
            tmp_c--;
            break;
    }
    if (area[tmp_r][tmp_c]) return false;
    else return true;
}

void nextPos() {
    switch (d) {
        case 0:
            r--;
            break;
        case 1:
            c++;
            break;
        case 2:
            r++;
            break;
        case 3:
            c--;
            break;
    }
}

bool isBackValid() {
    int tmp_r = r, tmp_c = c;
    switch (d) {
        case 0:
            tmp_r++;
            break;
        case 1:
            tmp_c--;
            break;
        case 2:
            tmp_r--;
            break;
        case 3:
            tmp_c++;
            break;
    }
    if (area[tmp_r][tmp_c]) return false;
    else return true;
}

void backPos() {
    switch (d) {
        case 0:
            r++;
            break;
        case 1:
            c--;
            break;
        case 2:
            r--;
            break;
        case 3:
            c++;
            break;
    }
}


int solve() {
    int cnt = 0;
    int flag = 0;

    while (1) {
        if (flag == 0) {
            area[r][c] = 1;
            cnt++;
        }
        for (int i = 0; i < 4; i++) {
            nextDir();
            if (isNextValid()) {
                nextPos();
                break;
            } else nextDir();
            flag = 1;
        }
        if (isBackValid()) {
            backPos();
            flag = 0;
        } else break;
    }
}

int main() {
    input();
    int res = solve();
    cout << res;

    return 0;
}