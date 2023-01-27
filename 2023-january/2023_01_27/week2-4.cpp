// programmers week2-4
// 체육복

#include <bits/stdc++.h>

using namespace std;

int students[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    for (int i = 0; i < lost.size(); i++) {
        students[lost[i]] = -1;
    }
    for (int i = 0; i < reserve.size(); i++) {
        students[reserve[i]]++;
    }

    // 도난당한 학생 중 주변에 체육복을 가진 학생이 1명밖에 없을 경우 먼저 처리
    for (int i = 1; i <= n; i++) {
        if (students[i] > -1) continue;
        int cnt = 0;
        int prev = 0;
        if (students[i - 1] > 0) {
            cnt++;
            prev = i - 1;
        }

        int next = 0;
        if (students[i + 1] > 0) {
            cnt++;
            next = i + 1;
        }

        if (cnt == 1) {
            students[i] = 0;
            if(prev > 0) students[prev]--;
            if(next > 0) students[next]--;
        }
    }

    // 도난당한 학생 중 주변에 체육복을 가진 학생이 2명이었을 경우 처리

    for (int i = 1; i <= n; i++) {
        if (students[i] > -1) continue;
        int cnt = 0;
        int prev = 0;
        if (students[i - 1] > 0) {
            cnt++;
            prev = i - 1;
        }

        int next = 0;
        if (students[i + 1] > 0) {
            cnt++;
            next = i + 1;
        }

        if (cnt > 0) {
            students[i] = 0;
            if(prev > 0) students[prev]--;
            if(next > 0) students[next]--;
        }
    }


    int res = n;
    for (int i = 1; i <= n; i++) {
        if(students[i] == -1) res--;
    }

    return res;

}
