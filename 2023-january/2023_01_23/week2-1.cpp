// programmers week2-1
// 올바른 괄호

#include <bits/stdc++.h>

using namespace std;

bool solution(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (st.empty()) return false;
            else st.pop();
        }
    }

    return st.empty();
}
