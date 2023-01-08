// baekjoon 9205

#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> home, festival;
vector<pair<int, int>> store;
bool visited[100];

int distance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

bool BFS() {
    queue<pair<int, int>> Q;
    Q.push(home);

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        if (distance(cur, festival) <= 1000) return true;

        for (int i = 0; i < n; i++) {
            if (visited[i] || distance(cur, store[i]) > 1000) continue;
            visited[i] = true;
            Q.push(store[i]);
        }

    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        store.clear();

        cin >> n;
        cin >> home.first >> home.second;

        for (int i = 0; i < n; i++) {
            memset(visited, false, sizeof(visited));
            int x, y;
            cin >> x >> y;
            store.push_back({x, y});
        }

        cin >> festival.first >> festival.second;
        if (BFS()) cout << "happy\n";
        else cout << "sad\n";

    }

    return 0;
}
/*
3
9
3000 3000
3000 2000
3000 1000
2000 1000
1000 1000
4000 1000
5000 1000
5000 0
3000 0
1000 0
5000 -1000
9
3000 3000
3000 2000
3000 1000
2000 1000
1000 1000
4000 1000
5000 1000
5000 0
3000 0
1000 0
3000 -1000
9
3000 3000
3000 2000
3000 1000
2000 1000
1000 1000
4000 1000
5000 1000
5000 0
3000 0
1000 0
1000 -1000
 */