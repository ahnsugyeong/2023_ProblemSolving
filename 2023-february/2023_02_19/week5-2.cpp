// programmers week5-2
// 뒤에 있는 큰 수 찾기

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++) {
        answer.push_back(-1);
    }

    stack<pair<int, int>> S;    // first: index, second: element
    for (int i = 0; i < numbers.size(); i++) {
        int cur = numbers[i];
        while (!S.empty() && S.top().second < cur) {
            answer[S.top().first] = cur;
            S.pop();
        }
        S.push({i, numbers[i]});
    }
    return answer;
}