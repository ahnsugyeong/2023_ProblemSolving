#include <iostream>
#include <vector>

using namespace std;

vector<int> getPrefixSum(const vector<int> &numbers);
int getIntervalSum(const vector<int> &prefixSum, int begin, int end);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    vector<int> prefixSum = getPrefixSum(numbers);

    for (int i = 0; i < M; i++) {
        int begin, end;
        cin >> begin >> end;
        cout << getIntervalSum(prefixSum, begin, end) << '\n';
    }

    return 0;
}

vector<int> getPrefixSum(const vector<int>& numbers) {
    int n = numbers.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = numbers[0];

    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + numbers[i];
    }
    return prefixSum;
}

int getIntervalSum(const vector<int>& prefixSum, int begin, int end) {
    if (begin == 1) {
        return prefixSum[end - 1];
    }
    return prefixSum[end - 1] - prefixSum[begin - 2];
}