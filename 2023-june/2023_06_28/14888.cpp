// baekjoon 14888

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[11];
int op[4];  // 0: +, 1: -, 2: *, 3: /
int max_ans = INT_MIN;
int min_ans = INT_MAX;

void DFS(int cnt, int ans) {
    if (cnt == N) {
        max_ans = max(max_ans, ans);
        min_ans = min(min_ans, ans);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] == 0) continue;

        op[i]--;

        if (i == 0) {
            DFS(cnt + 1, ans + arr[cnt]);
        } else if (i == 1) {
            DFS(cnt + 1, ans - arr[cnt]);
        } else if (i == 2) {
            DFS(cnt + 1, ans * arr[cnt]);
        } else if (i == 3) {
            DFS(cnt + 1, ans / arr[cnt]);
        }

        op[i]++;
    }
}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    DFS(1, arr[0]);

    cout << max_ans << "\n" << min_ans << "\n";
}