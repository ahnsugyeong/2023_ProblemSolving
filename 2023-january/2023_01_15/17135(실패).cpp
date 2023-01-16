// baekjoon 17135
// 15% 실패

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

//    printf("===========\n");
//    printf("archer\n");
//    for (int a = 0; a < archer.size(); a++) {
//        printf("%d ", archer[a]);
//    }
//    printf("\n");
    for (int cur = 0; cur < N; cur++) {
//        printf("cur = %d\n", cur);
        vector<pair<int, int>> attacked;

        for (int i = 0; i < 3; i++) {   // archer
            int targetDis = INT_MAX;
            int idx = INT_MAX;
            pair<int, int> target = {-1, -1};
            for (int j = 0; j < enemies.size(); j++) {
                if (enemies[j].first > N - cur || visited[j]) continue;
                int dis = distance({N - cur, archer[i]}, enemies[j]);
                //printf("archer = %d, enemies = %d %d, dis = %d\n", archer[i], enemies[j].first, enemies[j].second, dis);
                if (dis > D) continue;

                if (targetDis > dis) {
                    targetDis = dis;
                    target = enemies[j];
                    idx = j;
                } else if (targetDis == dis) {
                    if (idx > j) {
                        targetDis = dis;
                        target = enemies[j];
                        idx = j;
                    }
                }
            }
            if (target.first == -1) continue;
            visited[idx] = true;
            //printf("target added %d %d\n", target.first, target.second);
            attacked.push_back(target);
        }

        attacked.erase(unique(attacked.begin(), attacked.end()), attacked.end());
        cnt += attacked.size();
        //printf("attacked size = %d\n\n", attacked.size());
        attacked.clear();
    }

    //printf("cnt = %d\n", cnt);
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