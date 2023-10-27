#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    set<int> numbers;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (numbers.find(M - tmp) != numbers.end()) {
            ans++;
        }
        numbers.insert(tmp);
    }

    cout << ans << '\n';

    return 0;
}