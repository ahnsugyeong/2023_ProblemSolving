// programmers week1-4
// 최댓값과 최솟값

#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    long long maxNum = LONG_LONG_MIN;
    long long minNum = LONG_LONG_MAX;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        if (s[i] == '-') {
            string num = "";
            int j = i + 1;
            while (j < s.size()) {
                if (s[j] == ' ') break;
                num += s[j];
                j++;
            }
            if (maxNum < -stoi(num)) maxNum = -stoi(num);
            if (minNum > -stoi(num)) minNum = -stoi(num);

            i += (j - i);

        } else {
            string num = "";
            int j = i;
            while (j < s.size()) {
                if (s[j] == ' ') break;
                num += s[j];
                j++;
            }
            if (maxNum < stoi(num)) maxNum = stoi(num);
            if (minNum > stoi(num)) minNum = stoi(num);

            i += (j - i);

        }
    }

    string result = "";
    result += to_string(minNum) + " " + to_string(maxNum);

    return result;
}