// programmers week2-9
// 줄 서는 방법
// 효율성 테스트 실패

#include <bits/stdc++.h>

using namespace std;

vector<int> res;
vector<int> answer;
int visited[21];
int num = 0;

void DFS(int n, int cnt, int k) {
    if (n == cnt) {
        num++;
        if (num == k) answer = res;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        res.push_back(i);
        DFS(n, cnt + 1, k);
        res.pop_back();
        visited[i] = false;
    }

}

vector<int> solution(int n, long long k) {
    DFS(n, 0, k);
    return answer;
}

int main() {
    vector<int> ans = solution(3, 5);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}