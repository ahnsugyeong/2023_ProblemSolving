#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A.push_back({num, i});
    }

    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int gap = A[i].second - i;
        ans = max(ans, gap);
    }

    cout << ans + 1;

    return 0;
}