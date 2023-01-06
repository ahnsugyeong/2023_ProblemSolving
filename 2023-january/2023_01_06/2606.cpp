#include <bits/stdc++.h>

using namespace std;

int N, M;
bool computers[101][101];
bool visited[101];

void BFS() {
    queue<int> Q;
    Q.push(1);
    visited[1] = true;

    while (!Q.empty()) {
        int index = Q.front();
        Q.pop();
        for (int i = 1; i <= N; i++) {
            if (visited[i] || computers[index][i] == false) continue;
            Q.push(i);
            visited[i] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;

    while (M--) {
        int a, b;
        cin >> a >> b;
        computers[a][b] = true;
        computers[b][a] = true;
    }

    BFS();

    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (visited[i]) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}