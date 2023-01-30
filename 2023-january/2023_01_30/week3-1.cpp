// programmers week3-1
// 구명보트

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int start = 0;
    int end = people.size() - 1;
    while (start < people.size() && end >= 0) {
        if (start >= end) {
            if (start == end) answer++;
            break;
        }
        if (people[start] + people[end] <= limit) { // 2명 태워 보내기
            answer++;
            start++;
            end--;
        } else {    // 혼자 태워 보내기
            answer++;
            end--;
        }
    }
    return answer;
}