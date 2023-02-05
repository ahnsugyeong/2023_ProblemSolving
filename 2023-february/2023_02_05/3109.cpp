// baekjoon 3109

#include <bits/stdc++.h>

using namespace std;

int R, C, answer = 0;
vector<string> area;
int di[3] = {-1, 0, 1};
int dj[3] = {1, 1, 1};

bool isValid(int i, int j) {
    if (i < 0 || i > R - 1 || j < 0 || j > C - 1) return false;
    else if (area[i][j] == 'x') return false;
    else return true;
}

int flag;
void DFS(int i, int j, int cnt) {
    if (cnt == C - 1) {
        answer++;
        flag = 1;
        return;
    }
    for (int idx = 0; idx < 3; idx++) {
        int new_i = i + di[idx];
        int new_j = j + dj[idx];
        if (!isValid(new_i, new_j)) continue;
        area[new_i][new_j] = 'x';
        DFS(new_i, new_j, cnt + 1);
        if (flag == 1) return;
    }
}


int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string tmp;
        cin >> tmp;
        area.push_back(tmp);
    }

    for (int i = 0; i < R; i++) {
        flag = 0;
        DFS(i, 0, 0);
    }
    cout << answer;

    return 0;
}