// programmers week2-7
// 괄호 회전하기

#include <bits/stdc++.h>

using namespace std;

bool isOpen(char c) {
    if (c == '(' || c == '{' || c == '[') return true;
    else return false;
}

bool isCorrect(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (isOpen(s[i])) st.push(s[i]);
        else {
            if (s[i] == ')') {
                if (st.empty() || st.top() != '(') return false;
                st.pop();
            }
            if (s[i] == '}') {
                if (st.empty() || st.top() != '{') return false;
                st.pop();
            }
            if (s[i] == ']') {
                if (st.empty() || st.top() != '[') return false;
                st.pop();
            }
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        if (isCorrect(s)) answer++;

        char tmp = s[0];
        s = s.substr(1, s.size() - 1);
        s += tmp;
    }
    return answer;
}

int main() {
    cout << solution("}]()[{") << '\n';

}