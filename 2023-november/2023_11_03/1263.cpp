#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isGoodNumber(vector<long long> &A, int cur);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        if (isGoodNumber(A, i)) ans++;
    }

    cout << ans << '\n';

    return 0;
}


bool isGoodNumber(vector<long long> &A, int cur) {
    int left = 0, right = A.size() - 1;
    while (left < right) {
        if (cur == left) {
            left++;
            continue;
        }
        if (cur == right) {
            right--;
            continue;
        }

        int sum = A[left] + A[right];
        if (sum == A[cur]) return true;
        if (sum > A[cur]) right--;
        if (sum < A[cur]) left++;
    }
    return false;
}