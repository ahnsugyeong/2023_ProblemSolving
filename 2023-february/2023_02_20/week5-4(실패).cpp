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
    int A_cnt = 0, B_cnt = 0;

    A_cnt = DFS(cards, 0, 0);

    int idx = -1;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] != 0) idx = i;
    }
    // 1번 상자 그룹 제외하고 남는 상자 없다면
    if (idx == -1) return 0;

    B_cnt = DFS(cards, idx, 0);

    return A_cnt * B_cnt;
}

int main() {
    cout << solution({8, 6, 3, 7, 2, 5, 1, 4}); // 12
    //cout << solution({2, 3, 4, 5, 6, 7, 8, 1});
}