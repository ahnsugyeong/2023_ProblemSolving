// baekjoon 1182

#include <bits/stdc++.h>

using namespace std;

vector<int> V;
bool visited[21];
int N, S;
int res = 0;

// 1 0 0 0
void DFS(int len, int cnt, int idx) {
    if (len == cnt) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                sum += V[i];
            }
        }
        if (sum == S) res++;
        return;
    }
    for (int i = idx; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        DFS(len, cnt + 1, i);
        visited[i] = false;
    }

}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        int len = i + 1;
        DFS(len, 0, 0);
    }
    cout << res;

    return 0;
}