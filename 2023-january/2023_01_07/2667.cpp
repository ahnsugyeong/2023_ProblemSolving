#include <bits/stdc++.h>

using namespace std;

int N;
string house[25];
bool visited[25][25];
int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};

int DFS(int i, int j, int size) {
    for (int k = 0; k < 4; k++) {
        int new_i = i + di[k];
        int new_j = j + dj[k];
        if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1) continue;
        if (visited[new_i][new_j] || house[new_i][new_j] == '0') continue;
        visited[new_i][new_j] = true;
        size = DFS(new_i, new_j, size + 1);
    }
    return size;
}


int main() {

    int cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> house[i];
    }

    vector<int> result;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || house[i][j] == '0') continue;
            int size = DFS(i, j, 1);

            if (size > 1) {
                size--;
            }
            result.push_back(size);
            cnt++;
        }
    }
    sort(result.begin(), result.end());

    cout << cnt << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }


}