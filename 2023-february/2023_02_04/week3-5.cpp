// programmers week3-5

#include <bits/stdc++.h>

using namespace std;

bool visited[100000001];
vector<string> path;

int flag = 0;
void DFS(vector<vector<string>> tickets, string cur, int cnt) {
    if (cnt == tickets.size()) {
        flag = 1;
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] != cur || visited[i]) continue;
        path.push_back(tickets[i][1]);
        visited[i] = true;
        DFS(tickets, tickets[i][1], cnt + 1);
        if(flag == 0) {
            path.pop_back();
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    path.push_back("ICN");
    DFS(tickets, "ICN", 0); // ICN 공항에서 출발
    return path;
}

int main() {
    solution({{"ICN", "JFK"},
              {"HND", "IAD"},
              {"JFK", "HND"}});
}