#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N;
int area[21][21];
int check[21][21];
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};
int sharkSize = 2;

struct cmp {
    bool operator()(pair<int, int> &A, pair<int, int> &B) {
        if (check[A.first][A.second] > check[B.first][B.second]) return true;
        else if (check[A.first][A.second] == check[B.first][B.second]) {
            if (A.first > B.first) return true;
            else if (A.first == B.first) return A.second > B.second;
        }
        return false;
    }
};

queue<pair<int, int>> Q;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void BFS() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int new_i = cur.first + di[idx];
            int new_j = cur.second + dj[idx];
            if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1) continue;
            if (check[new_i][new_j] != -1) continue;
            if (area[new_i][new_j] != 0 && area[new_i][new_j] > sharkSize) continue;

            if (area[new_i][new_j] == sharkSize || area[new_i][new_j] == 0) {
                Q.push({new_i, new_j});
                check[new_i][new_j] = check[cur.first][cur.second] + 1;
            } else {
                Q.push({new_i, new_j});
                check[new_i][new_j] = check[cur.first][cur.second] + 1;
                pq.push({new_i, new_j});
            }
        }
    }
}

int solve(int fishCnt) {
    int ateCnt = 0;
    int time = 0;

    while (fishCnt--) {
        pq = {};    // init
        fill(&check[0][0], &check[20][20], -1);

        pair<int, int> cur = Q.front();
        check[cur.first][cur.second] = 0;
        BFS();
        if (pq.size() == 0) break;

        auto target = pq.top();
//        printf("target = {%d, %d}\n", target.first, target.second);
        area[cur.first][cur.second] = 0;
        area[target.first][target.second] = 9;
        time += check[target.first][target.second];
        Q.push({target.first, target.second});
        ateCnt++;
        if (ateCnt == sharkSize) {
            ateCnt = 0;
            sharkSize++;
        }
    }
    return time;
}

int main() {
    cin >> N;
    int fishCnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> area[i][j];
            if (area[i][j] >= 1 && area[i][j] <= 6) fishCnt++;
            if (area[i][j] == 9) Q.push({i, j});
        }
    }

    cout << solve(fishCnt);

    return 0;
}