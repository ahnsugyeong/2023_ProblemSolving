// programmers week5-3
// 숫자 블록

#include <bits/stdc++.h>

using namespace std;

long long isPrime(long long n) {
    if (n < 2) return 0;

    for (long long i = n - 1; i >= sqrt(n); i--) {
        if (n % i == 0) return i;
    }
    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (long long i = begin; i <= end; i++) {
        answer.push_back(isPrime(i));
    }
    return answer;
}

int main() {
    solution(1, 10);

}

