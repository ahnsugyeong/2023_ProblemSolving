// baekjoon 5014

#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D;

int visited[1000001];

void BFS() {
    queue<int> Q;
    Q.push(S);  // 강호가 있는 곳
    visited[S] = 1;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        if (cur + U <= F && visited[cur + U] == 0) {
            visited[cur + U] = visited[cur] + 1;
            Q.push(cur + U);
        }
        if (cur - D > 0 && visited[cur - D] == 0) {
            visited[cur - D] = visited[cur] + 1;
            Q.push(cur - D);
        }
    }

}

int main() {
    cin >> F >> S >> G >> U >> D;
    BFS();
    if (visited[G] == 0) cout << "use the stairs";
    else cout << visited[G] - 1;
    return 0;
}