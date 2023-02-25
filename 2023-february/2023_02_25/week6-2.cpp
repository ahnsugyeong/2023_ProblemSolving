// programmers week6-2
// N개의 최소공배수

#include <bits/stdc++.h>

using namespace std;

long long GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long LCM(int a, int b) {
    return a * b / GCD(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < arr.size() - 1; i++) {
        answer = LCM(arr[i], arr[i + 1]);
        arr[i + 1] = answer;
    }
    return answer;
}

int main() {
    cout << solution({2, 6, 8, 14}) << '\n';    // 168
    cout << solution({1, 2, 3}) << '\n';  // 6
}