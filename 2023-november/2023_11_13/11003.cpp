#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Info {
    int data;
    int index;
};

struct cmp {
    bool operator()(const Info &a, const Info &b) {
        return a.data > b.data;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    priority_queue<Info, vector<Info>, cmp> pq;
    for (int i = 0; i < N; i++) {
        pq.push({A[i], i});
        int pos = pq.top().index;
        while (pos < i - L + 1) {
            pq.pop();
            pos = pq.top().index;
        }
        cout << pq.top().data << ' ';
    }

    return 0;
}