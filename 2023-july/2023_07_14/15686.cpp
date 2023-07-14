// baekjoon 15686

#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans = INT_MAX;
vector<pair<int, int>> homes, chickens, checkedChickens;
bool check[13];


int chickenDistance(pair<int, int> home, pair<int, int> chicken) {
    return abs(home.first - chicken.first) + abs(home.second - chicken.second);
}

int totalChickenDistance() {
    int sum = 0;
    for (int i = 0; i < homes.size(); i++) {
        int minVal = INT_MAX;
        for (int j = 0; j < checkedChickens.size(); j++) {
            minVal = min(minVal, chickenDistance(homes[i], checkedChickens[j]));
        }
        sum += minVal;
    }
    return sum;
}


void DFS(int idx, int cnt) {
    if (cnt == M) {
        checkedChickens.clear();

        for (int i = 0; i < 13; i++) {
            if (check[i]) checkedChickens.push_back(chickens[i]);
        }
        ans = min(ans, totalChickenDistance());
        return;
    }

    for (int i = idx; i < chickens.size(); i++) {
        if (check[i]) continue;
        check[i] = true;
        DFS(i, cnt + 1);
        check[i] = false;
    }

}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int info;
            cin >> info;
            if (info == 1) homes.push_back({i, j});
            if (info == 2) chickens.push_back({i, j});
        }
    }

    DFS(0, 0);

    cout << ans;
    return 0;
}