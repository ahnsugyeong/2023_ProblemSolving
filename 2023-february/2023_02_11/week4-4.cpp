// programmers week4-4
// 호텔 대실
// 누적합
// https://ksb-dev.tistory.com/269 참고

#include <bits/stdc++.h>

#define MAX_TIME 1450
using namespace std;

int convertTime(string s) {
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    return hour * 60 + minute;
}

int hotel[MAX_TIME];
int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> V;
    for (auto time: book_time) {
        int start = convertTime(time[0]);
        int end = convertTime(time[1]) + 10;

        hotel[start] += 1;
        hotel[end] -= 1;
    }

    int answer = 0;
    for (int i = 1; i < MAX_TIME; i++) {
        hotel[i] += hotel[i-1];
        answer = max(answer, hotel[i]);
    }
    return answer;
}