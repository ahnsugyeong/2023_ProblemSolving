// baekjoon 17135

#include <bits/stdc++.h>

using namespace std;

int N, M, D, res = 0;
int area[15][15];
vector<int> archer;
vector<pair<int, int>> enemies;
bool visited[300];

int distance(pair<int, int> A, pair<int, int> B) {
    return abs(A.first - B.first) + abs(A.second - B.second);
}

int solve() {
    int cnt = 0;

    for (int cur = 0; cur < N; cur++) {
        vector<pair<int, int>> attacked;
        vector<int> indices;

        for (int i = 0; i < 3; i++) {   // archer
            int targetDis = INT_MAX;
            int idx = INT_MAX;
            pair<int, int> target = {-1, -1};
            for (int j = 0; j < enemies.size(); j++) {
                if (enemies[j].first >= N - cur || visited[j]) continue;
                int dis = distance({N - cur, archer[i]}, enemies[j]);
                if (dis > D) continue;
                if (targetDis > dis) {
                    targetDis = dis;
                    target = enemies[j];
                    idx = j;
                } else if (targetDis == dis) {
                    if (enemies[idx].second > enemies[j].second) {
                        targetDis = dis;
                        target = enemies[j];
                        idx = j;
                    }
                }
            }
            if (target.first == -1) continue;
            indices.push_back(idx);
            attacked.push_back(target);
        }
        for (int i = 0; i < indices.size(); i++) {
            visited[indices[i]] = true;
        }

        attacked.erase(unique(attacked.begin(), attacked.end()), attacked.end());
        cnt += attacked.size();
        attacked.clear();
    }

    return cnt;

}


// coombination -> 완전탐색
void combination(int index, int cnt) {
    if (cnt == 3) {
        // solve
        res = max(res, solve());
        memset(visited, false, sizeof(visited));
    }
    for (int i = index; i < M; i++) {
        archer.push_back(i);
        combination(i + 1, cnt + 1);
        archer.pop_back();
    }
}


int main() {
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> area[i][j];
            if (area[i][j]) {
                enemies.push_back({i, j});
            }
        }
    }

    combination(0, 0);
    cout << res;
    return 0;
}