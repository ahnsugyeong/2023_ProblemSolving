#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void selectActiveVirus(int index, int cnt);

void spreadVirus(vector<pair<int, int>> &activeVirus);

int N, M;
int lab[51][51];    // 0: 빈 칸, 1: 벽, 2: 비활성 바이러스
vector<pair<int, int>> virus;
bool selected[10];

int visited[51][51];
int ans = INT_MAX;
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) virus.push_back({i, j});
        }
    }

    selectActiveVirus(0, 0);

    if (ans == INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';
}

void selectActiveVirus(int index, int cnt) {
    if (cnt == M) {
        vector<pair<int, int>> activeVirus;
        for (int i = 0; i < virus.size(); i++) {
            if (selected[i]) activeVirus.push_back(virus[i]);
        }
        spreadVirus(activeVirus);
    }

    for (int i = index; i < virus.size(); i++) {
        if (selected[i]) continue;
        selected[i] = true;
        selectActiveVirus(i, cnt + 1);
        selected[i] = false;
    }
}

struct Virus {
    pair<int, int> index;
    int time;
};


void spreadVirus(vector<pair<int, int>> &activeVirus) {
    fill(&visited[0][0], &visited[N][0], -1);

    queue<pair<int, int>> Q;
    for (int i = 0; i < activeVirus.size(); i++) {
        Q.push(activeVirus[i]);
        visited[activeVirus[i].first][activeVirus[i].second] = 0;
    }

    int totalTime = 0;
    while (!Q.empty()) {
        int cur_i = Q.front().first;
        int cur_j = Q.front().second;
        Q.pop();

        for (int idx = 0; idx < 4; idx++) {
            int new_i = cur_i + di[idx];
            int new_j = cur_j + dj[idx];
            if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1) continue;
            if (lab[new_i][new_j] == 1 || visited[new_i][new_j] != -1) continue;

            visited[new_i][new_j] = visited[cur_i][cur_j] + 1;
            Q.push({new_i, new_j});
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lab[i][j] == 0) {
                if (visited[i][j] == -1) return;
                totalTime = max(totalTime, visited[i][j]);
            }
        }
    }

    ans = min(ans, totalTime);
}