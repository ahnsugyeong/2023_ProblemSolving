// programmers week6-1
// JadenCase 문자열 만들기

#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || s[i - 1] == ' ') {
            if (s[i] >= 'a' && s[i] <= 'z') s[i] -= ('a' - 'A');
        } else {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += ('a' - 'A');
        }
    }
    return s;
}

int main() {
    //cout << solution("3people unFollowed me") << '\n';
    cout << solution("for the last week") << '\n';
}