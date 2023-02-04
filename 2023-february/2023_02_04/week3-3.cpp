// programmers week3-3

#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    // n(10진수)을 k진수로 변환
    vector<int> V;
    while (n) {
        V.push_back(n % k);
        n /= k;
    }

    vector<string> nums;
    string str = "";
    for (int i = V.size() - 1; i >= 0; i--) {

        if (i == 0 && V[i] != 0) {
            str += (V[i] + '0');
            nums.push_back(str);
            break;
        }

        if (V[i] == 0) {
            if (str.size() > 0) {
                nums.push_back(str);
                str = "";
            }
        } else {
            str += (V[i] + '0');
        }
    }

    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (isPrime(stoll(nums[i]))) cnt++;
    }

    return cnt;
}