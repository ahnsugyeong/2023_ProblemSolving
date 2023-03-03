// programmers week6-4
// 숫자 카드 나누기

#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int A_GCD = arrayA[0], B_GCD = arrayB[0];
    for (int i = 1; i < arrayA.size(); i++) {
        A_GCD = GCD(A_GCD, arrayA[i]);
        B_GCD = GCD(B_GCD, arrayB[i]);
    }

    int A_flag = 0, B_flag = 0;

    for (int i = 0; i < arrayA.size(); i++) {
        if (arrayA[i] % B_GCD != 0) A_flag = B_GCD;
        else {
            A_flag = 0;
            break;
        }
    }

    for (int i = 0; i < arrayB.size(); i++) {
        if (arrayB[i] % A_GCD != 0) B_flag = A_GCD;
        else {
            B_flag = 0;
            break;
        }
    }

    return max(A_flag, B_flag);
}