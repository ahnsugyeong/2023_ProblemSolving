// programmers week3-4
// 효율성 테스트 실패

#include <bits/stdc++.h>

using namespace std;

vector<string> V;
vector<string> nums;
int num[3] = {1, 2, 4};
string answer = "";

void DFS(int index, int len, int cnt, int n) {
    if (answer.size() > 0) return;
    if (len == cnt) {
        string result = "";
        for (int i = 0; i < V.size(); i++) {
            result += V[i];
        }
        nums.push_back(result);

        if (nums.size() == n) {
            answer = result;
        }
        return;
    }
    for (int i = index; i < 3; i++) {
        V.push_back(to_string(num[i]));
        DFS(index, len, cnt + 1, n);
        V.pop_back();
    }
}

string solution(int n) {
    for (int i = 1;; i++) {
        DFS(0, i, 0, n);
        if (answer.size() > 0) break;
    }
    return answer;
}

int main() {
    cout << solution(50000000);
}