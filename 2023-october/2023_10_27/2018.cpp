#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int ans = 1;
    for (int i = 1; i <= N / 2; i++) {
        int sum = 0;
        for (int j = i; j <= N; j++) {
            sum += j;
            if (sum > N) {
                break;
            }
            if (sum == N) {
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}