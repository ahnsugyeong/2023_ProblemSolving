#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> s;
    vector<char> result;
    int num = 1;
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            result.push_back('+');
            s.push(num);
            num++;
        }

        while (s.top() != arr[i]) {
            if (num > n) break;
            result.push_back('+');
            s.push(num);
            num++;
        }

        if (s.top() == arr[i]) {
            result.push_back('-');
            s.pop();
        }
    }

    if (!s.empty()) cout << "NO\n";
    else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << '\n';
        }
    }

    return 0;
}