#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    stack<int> s;
    vector<int> NGE(N);
    for (int i = N - 1; i >= 0; i--) {
        while(!s.empty() && s.top() <= A[i]) {
            s.pop();
        }
        if (s.empty()) NGE[i] = -1;
        else NGE[i] = s.top();
        s.push(A[i]);
    }

    for(int i=0;i<N;i++) {
        cout << NGE[i] << " ";
    }

    return 0;
}