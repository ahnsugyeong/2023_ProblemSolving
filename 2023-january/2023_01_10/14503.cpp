// baekjon 14503

#include <bits/stdc++.h>

using namespace std;

/*
1. 현재 위치를 청소한다.
2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
    2-1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
    2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
    2-3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
    2-4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.

0: 북쪽, 1: 동쪽, 2: 남쪽, 3: 서쪽
 */

int N, M;
int r, c, d;
int cnt;
int flag = 0;
int area[50][50];   // 1: 벽
bool visited[50][50];   // 1: 청소가 되어있거나 벽인 경우


void input() {
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> area[i][j];
            if (area[i][j]) visited[i][j] = true;
        }
    }
    cnt = 0;
    flag = 0;
}

pair<int, int> isNextValid(int i, int j, int d) {

    switch (d) {
        case 0:
            i--;
            break;
        case 1:
            j++;
            break;
        case 2:
            i++;
            break;
        case 3:
            j--;
            break;
    }

    if (!visited[i][j]) return {i, j};
    else return {-1, -1};
}

pair<int, int> isBackValid(int i, int j, int d) { // 뒤쪽이 벽이면 후진 불가
    switch (d) {
        case 0:
            i++;
            break;
        case 1:
            j--;
            break;
        case 2:
            i--;
            break;
        case 3:
            j++;
            break;
    }
    if (!area[i][j]) return {i, j};
    else return {-1, -1};
}


void DFS(int i, int j) {
    if (flag) return;

    for (int index = 0; index < 4; index++) {
        // 북->서, 서->남, 남->동, 동->북
        // 0->3, 3->2, 2->1, 1->0
        d = (d + 3) % 4;
        pair<int, int> validRes = isNextValid(i, j, d);
        if (validRes.first != -1) {
            visited[validRes.first][validRes.second] = 1;
            cnt++;
            DFS(validRes.first, validRes.second);
            return;
        }
    }

    pair<int, int> backValidRes = isBackValid(i, j, d);
    if (backValidRes.first != -1) {
        DFS(backValidRes.first, backValidRes.second);
    } else {
        flag = 1;   // 프로그램 종료
    }
}

int main() {
    input();
    visited[r][c] = 1;
    cnt++;
    DFS(r, c);
    cout << cnt << '\n';

    return 0;
}