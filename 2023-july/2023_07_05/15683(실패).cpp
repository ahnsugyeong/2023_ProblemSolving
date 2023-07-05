// baekjoon 15683

#include <bits/stdc++.h>

using namespace std;

int N, M;
int room[8][8];
int visited[8][8];
vector<pair<pair<int, int>, int>> cctvs;

void up(pair<int, int> cctv) {
    for (int i = cctv.first - 1; i >= 0; i--) {
        if (room[i][cctv.second] == 6) break;
        visited[i][cctv.second] = true;
    }
}

void down(pair<int, int> cctv) {
    for (int i = cctv.first + 1; i < N; i++) {
        if (room[i][cctv.second] == 6) break;
        visited[i][cctv.second] = true;
    }
}

void left(pair<int, int> cctv) {
    for (int j = cctv.first - 1; j >= 0; j--) {
        if (room[cctv.first][j] == 6) break;
        visited[cctv.first][j] = true;
    }
}

void right(pair<int, int> cctv) {
    for (int j = cctv.first + 1; j < M; j++) {
        if (room[cctv.first][j] == 6) break;
        visited[cctv.first][j] = true;
    }
}

void monitor(pair<int, int> cctv, int dir) {
    int num = room[cctv.first][cctv.second];
    if (num == 1) {
        if (dir == 0) {  // ↑
            up(cctv);
        } else if (dir == 1) {  // ↓
            down(cctv);
        } else if (dir == 2) {  // ←
            left(cctv);
        } else if (dir == 3) {  // →
            right(cctv);
        }
    } else if (num == 2) {
        if (dir == 0 || dir == 2) { // ←→
            left(cctv);
            right(cctv);
        } else if (dir == 1 || dir == 3) { // ↑↓
            up(cctv);
            down(cctv);
        }
    } else if (num == 3) {
        if (dir == 0) { // →↑
            up(cctv);
            right(cctv);
        } else if (dir == 1) {  // →↓
            down(cctv);
            right(cctv);
        } else if (dir == 2) {  // ←↓
            down(cctv);
            left(cctv);
        } else if (dir == 3) {  // ←↑
            up(cctv);
            left(cctv);
        }
    } else if (num == 4) {
        if (dir == 0) { // →←↓
            down(cctv);
            left(cctv);
            right(cctv);
        } else if (dir == 1) {  // →←↑
            up(cctv);
            left(cctv);
            right(cctv);
        } else if (dir == 2) {  // →↑↓
            up(cctv);
            down(cctv);
            right(cctv);
        } else if (dir == 3) {  // ←↑↓
            up(cctv);
            down(cctv);
            left(cctv);
        }
    } else if (num == 5) {
        // →←↑↓
        up(cctv);
        down(cctv);
        left(cctv);
        right(cctv);
    }
}


/*
 * 1: 4
 * 2: 2
 * 3: 4
 * 4: 4
 * 5: 1
 */

int safeArea() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) cnt++;
        }
    }
    return cnt;
}

int ans = INT_MAX;

int solution(int cnt) {

    if (cnt == cctvs.size()) {
        int cnt = safeArea();
        ans = min(cnt, ans);
        memset(visited, 0, sizeof(visited));
    }

    cctvs[cnt].second = 0;
    solution(cnt + 1);

    cctvs[cnt].second = 1;
    solution(cnt + 1);

    cctvs[cnt].second = 2;
    solution(cnt + 1);

    cctvs[cnt].second = 3;
    solution(cnt + 1);


}


int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
            if (room[i][j] > 0 && room[i][j] < 6) cctvs.push_back({{i, j}, 0});
        }
    }

    solution(0);
    cout << ans;


    return 0;
}