// programmers week1-7
// 귤 고르기 - 블로그 참고

#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> A, pair<int, int> B) {
    if (A.second == B.second) return A.first > B.first;
    return A.second > B.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> save;

    for (int i : tangerine) {
        if (save.find(i) != save.end()) {
            save[i] += 1;
        } else {
            save.insert(pair<int, int>(i, 1));
        }
    }

    vector<pair<int, int>> all_list(save.begin(), save.end());
    sort(all_list.begin(), all_list.end(), compare);

    int idx = 0;

    while (k > 0) {
        if (k <= all_list[idx].second) {
            answer += 1;
            break;
        } else {
            answer += 1;
            k -= all_list[idx].second;
        }
        idx++;
    }


    return answer;


}

// 1 3 2 5 4 5 2 3