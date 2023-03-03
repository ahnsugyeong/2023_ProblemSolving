// programmers week6-4
// 숫자 카드 나누기

#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    for (int i = 0; i < arrayA.size() - 1; i++) {
        arrayA[i + 1] = GCD(arrayA[i], arrayA[i + 1]);
    }
    int maxGCD = arrayA[arrayA.size() - 1];
    for (int i = 0; i < arrayB.size(); i++) {
        if (arrayB[i] % maxGCD == 0) return 0;
    }
    return maxGCD;
}

int main() {
    cout << solution({10, 17}, {5, 20});
}