// baekjoon 1911

#include  <bits/stdc++.h>

using namespace std;

int N, L;
vector<pair<int, int>> pool;

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        pool.push_back({start, end});
    }

    sort(pool.begin(), pool.end());


    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < pool.size(); i++) {
        int start = pool[i].first;
        int end = pool[i].second;
        if (idx >= pool[i].second) continue;

        if (start < idx) start = idx;

        int ans = (end - start) / L;
        if ((end - start) % L != 0) ans++;
        idx = start + ans * L;
        cnt += ans;

    }
    cout << cnt;
    return 0;
}