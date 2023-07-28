#include <bits/stdc++.h>

using namespace std;

int N, D;
vector<int> strawberries;
bool visited[1000000];
int ans;

void getStrawberries(int cur, int harvested, int dis) {
    // 현재 위치에 있는 모든 딸기 수확
    for (int i = 0; i < strawberries.size(); i++) {
        if (strawberries[i] == cur) {
            if (!visited[i]) {
                harvested++;
            }
        }
    }
    ans = max(ans, harvested);
    if (dis <= 0) {
        return;
    }

    // 오른쪽으로 이동하는 경우
    for (int i = strawberries.size() - 1; i >= 0; i--) {
        if (strawberries[i] >= cur) {
            int right = strawberries[i];
            if (right - cur <= dis) {
                if (!visited[i]) {
                    visited[i] = true;
                    getStrawberries(right, harvested + 1, dis - (right - cur));
                    visited[i] = false;
                }
            }
        } else break;
    }

    // 왼쪽으로 이동하는 경우
    for (int i = 0; i < strawberries.size(); i++) {
        if (strawberries[i] <= cur) {
            int left = strawberries[i];
            if (cur - left <= dis) {
                if (!visited[i]) {
                    visited[i] = true;
                    getStrawberries(left, harvested + 1, dis - (cur - left));
                    visited[i] = false;
                }
            }
        } else break;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> D;
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            strawberries.push_back(tmp);
        }
        sort(strawberries.begin(), strawberries.end());
        getStrawberries(0, 0, D);

        cout << "Case #" << i + 1 << "\n";
        cout << ans << "\n";

        strawberries.clear();
        ans = 0;

    }


    return 0;
}