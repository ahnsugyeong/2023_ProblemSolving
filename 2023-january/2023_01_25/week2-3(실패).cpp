// programmers week2-3
// 땅따먹기

#include <bits/stdc++.h>

using namespace std;

int res = 0;

void DFS(vector<vector<int>> land, int cnt, int sum, int prevRow) {
    if (land.size() == cnt) {
        res = max(res, sum);
        return;
    }

    for (int i = 0; i < land[cnt].size(); i++) {
        if (i == prevRow) continue;
        DFS(land, cnt + 1, sum + land[cnt][i], i);
    }
}

int solution(vector<vector<int>> land) {
    DFS(land, 0, 0, -1);
    return res;
}

int main() {
    cout << solution({{1,2,3,5},{5,6,7,8},{4,3,2,1}});
}