// programmers week4-2
// 할인 행사

#include <bits/stdc++.h>

using namespace std;

map<string, int> w;
map<string, int> d;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    for (int i = 0;i < want.size();i++) {
        w[want[i]] = number[i];
    }
    for (int i = 0;i < 10;i++) {
        if (d.find(discount[i]) == d.end()) d[discount[i]] = 1;
        else d[discount[i]] ++;
    }

    int count = 0;
    int start = 0;
    while (start < discount.size() - 10) {
        int flag = 0;
        for (auto ele : w) {
            if (ele.second > d[ele.first]) {
                flag = 1;   // 할인 실패
                break;
            }
        }

        if (d[discount[start]] == 1) d.erase(discount[start]);
        else d[discount[start]] --;
        if (d.find(discount[start + 10]) == d.end()) d[discount[start + 10]] = 1;
        else d[discount[start + 10]] ++;
        start++;
        if (flag) continue;

        // 할인 조건 만족하면 count++;
        count++;
    }

    for (int i = 0;i < 10;i++) {
        int idx = discount.size() - 10 + i;

        int flag = 0;
        for (auto ele : w) {
            if (ele.second > d[ele.first]) {
                flag = 1;   // 할인 실패
                break;
            }
        }

        if (d[discount[idx]] == 1) d.erase(discount[idx]);
        else d[discount[idx]] --;

        if (flag) continue;

        // 할인 조건 만족하면 count++;
        count++;
    }

    return count;
}
