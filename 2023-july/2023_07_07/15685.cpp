// baekjoon 15685

#include <bits/stdc++.h>

using namespace std;
int N;
int x, y, d, g;
vector<int> dir;
int Map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void dragonCurve() {

    // 움직일 방향 구하기
    for (int i = 0; i < g; i++) {
        for (int j = dir.size() - 1; j >= 0; j--) {
            int new_dir = (dir[j] + 1) % 4;
            dir.push_back(new_dir);
        }
    }

    // 구한 방향대로 Map에 check
    for (int i = 0; i < dir.size(); i++) {
        x += dx[dir[i]];
        y += dy[dir[i]];
        Map[x][y] = 1;
    }

}

int countSqure() {
    int cnt = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (Map[i][j] && Map[i + 1][j] && Map[i][j + 1] && Map[i + 1][j + 1]) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        dir.clear();
        cin >> x >> y >> d >> g;
        dir.push_back(d);
        Map[x][y] = 1;
        Map[x + dx[d]][y + dy[d]] = 1;  // 0세대 check
        dragonCurve();
    }
    cout << countSqure();


    return 0;
}