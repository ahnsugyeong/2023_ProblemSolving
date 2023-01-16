// baekjoon 1697

#include <bits/stdc++.h>

using namespace std;

int N, K;
int visited[200001];


void BFS() {
    queue<int> Q;
    Q.push(N);
    visited[N] = 0;
    while (!Q.empty()) {
        int X = Q.front();
        Q.pop();
        if (X < 0 || X > 100000) continue;
        if (X == K) return;

        int X1 = X - 1;
        int X2 = X + 1;
        int X3 = X * 2;

        if (visited[X1] == 0) {
            visited[X1] = visited[X] + 1;
            Q.push(X1);
        }

        if (visited[X2] == 0) {
            visited[X2] = visited[X] + 1;
            Q.push(X2);
        }

        if (visited[X3] == 0) {
            visited[X3] = visited[X] + 1;
            Q.push(X3);
        }

    }
}

int main() {
    cin >> N >> K;
    BFS();

    cout << visited[K];

    return 0;
}

/*
100 0 # 100
6 16 # 3
8 20 # 3
15964 89498 # 4781
3 43 # 6
4 27 # 5
5 35 # 5
6 43 # 5
7 43 # 6
100 1 # 99
10 19 # 2
5 19 # 3
1 20 # 5
100000 100000 # 0
0 100000 # 22
100000 0 # 100000
0 1 # 1
3482 45592 # 637
2 4 # 1
9 5 # 4
5 5 # 0
5 17 # 4
 */