// programmers week5-4
// 혼자 놀기의 달인

#include <bits/stdc++.h>

using namespace std;

// 8 6 3 7 2 5 1 4
// 1번 상자: 8 4 7 1
// 2번 상자: 6 5 2
// result = 4 * 3 = 12

int DFS(vector<int> &cards, int idx, int sum) {
    if (cards[idx] == 0) return sum;
    int cur = cards[idx];
    cards[idx] = 0;
    return DFS(cards, cur - 1, sum + 1);
}

int solution(vector<int> cards) {
    vector<int> answer;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] == 0) continue;
        int cnt = DFS(cards, i, 0);
        answer.push_back(cnt);
    }
    sort(answer.rbegin(), answer.rend());
    if (answer.size() == 1) return 0;
    else return answer[0] * answer[1];

}

int main() {
    cout << solution({8, 6, 3, 7, 2, 5, 1, 4}); // 12
    //cout << solution({2, 3, 4, 5, 6, 7, 8, 1});
}