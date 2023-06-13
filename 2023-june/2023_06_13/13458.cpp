// baekjoon 13458

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    int N, B, C;
    vector<ll> A;

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    cin >> B >> C;

    ll result = N; // 각 시험장마다 배치된 총감독관
    for (int i = 0; i < N; i++) {
        // 총감독관이 감시하는 응시자 빼기
        A[i] -= B;
        if (A[i] <= 0) continue;    // 총감독관만으로도 충분하면 해당 시험장 PASS
        // 남은 학생들을 위해 필요한 부감독관
        if (A[i] % C != 0) result += A[i] / C + 1;
        else result += A[i] / C;
    }

    cout << result;

    return 0;
}