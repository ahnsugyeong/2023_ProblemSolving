#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getPrefixSum(const vector<vector<int>> &numbers);

int getIntervalSum(const vector<vector<int>> &prefixSum, pair<int, int> begin, pair<int, int> end);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> numbers(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> numbers[i][j];
        }
    }

    vector<vector<int>> prefixSum = getPrefixSum(numbers);
    for (int i = 0; i < M; i++) {
        pair<int, int> begin, end;
        cin >> begin.first >> begin.second >> end.first >> end.second;
        cout << getIntervalSum(prefixSum, begin, end) << '\n';
    }

    return 0;
}

vector<vector<int>> getPrefixSum(const vector<vector<int>> &numbers) {
    int n = numbers.size();
    vector<vector<int>> prefixSum(n, vector<int>(n, 0));

    prefixSum[0][0] = numbers[0][0];
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                prefixSum[i][j] = prefixSum[i][j - 1] + numbers[i][j];
                continue;
            }
            if (j == 0) {
                prefixSum[i][j] = prefixSum[i - 1][j] + numbers[i][j];
                continue;
            }
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] + numbers[i][j] - prefixSum[i - 1][j - 1];
        }
    }
    return prefixSum;
}

int getIntervalSum(const vector<vector<int>> &prefixSum, pair<int, int> begin, pair<int, int> end) {
    if (begin.first == 1 && begin.second == 1) return prefixSum[end.first - 1][end.second - 1];
    if (begin.first == 1) {
        return prefixSum[end.first - 1][end.second - 1]
               - prefixSum[end.first - 1][begin.second - 2];
    }
    if (begin.second == 1) {
        return prefixSum[end.first - 1][end.second - 1]
               - prefixSum[begin.first - 2][end.second - 1];
    }

    return prefixSum[end.first - 1][end.second - 1]
           - prefixSum[begin.first - 2][end.second - 1]
           - prefixSum[end.first - 1][begin.second - 2]
           + prefixSum[begin.first - 2][begin.second - 2];
}