#include <bits/stdc++.h>

using namespace std;

/*
1. 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
2. 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
3. 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
4. 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
5. 연합을 해체하고, 모든 국경선을 닫는다.

 -> BFS?

 */

int N, L, R;
int A[50][50];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
bool visited[50][50];

bool BFS() {
    memset(visited, false, sizeof(visited));

    vector<vector<pair<int, int>>> units;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;

            vector<pair<int, int>> unit;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            unit.push_back({i, j});
            visited[i][j] = true;

            while (!Q.empty()) {
                int cur_i = Q.front().first;
                int cur_j = Q.front().second;
                Q.pop();

                for (int idx = 0; idx < 4; idx++) {
                    int new_i = cur_i + di[idx];
                    int new_j = cur_j + dj[idx];
                    if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1) continue;
                    if (visited[new_i][new_j]) continue;
                    int gap = abs(A[cur_i][cur_j] - A[new_i][new_j]);
                    if (gap < L || gap > R) continue;
                    visited[new_i][new_j] = true;
                    Q.push({new_i, new_j});
                    unit.push_back({new_i, new_j});
                }
            }
            units.push_back(unit);
        }
    }

    for (int i = 0; i < units.size(); i++) {
        vector<pair<int, int>> unit = units[i];
        int sum = 0;
        for (int idx = 0; idx < unit.size(); idx++) {
            sum += A[unit[idx].first][unit[idx].second];
        }
        int num = sum / unit.size();
        for (int idx = 0; idx < unit.size(); idx++) {
            A[unit[idx].first][unit[idx].second] = num;
        }
    }

    if (units.size() == N * N) return false;
    else return true;
}

int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int cnt = 0;
    while (true) {
        if (BFS()) cnt++;
        else break;
    }
    cout << cnt;

    return 0;
}