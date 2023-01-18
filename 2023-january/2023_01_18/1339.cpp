// baekjoon 1339

#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> V;
vector<char> alphabet;
vector<char> pos[8];    // 자리 별 알파벳 (크기: 수의 최대 길이)
int visited[26];   // 알파벳 숫자 지정
int weight[26];

bool compare(char c1, char c2) {
    return weight[c1 - 'A'] > weight[c2 - 'A'];
}

int main() {
    cin >> N;
    int maxSize = 0;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        if (maxSize < tmp.size()) maxSize = tmp.size();
        V.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        string str = V[i];
        int size = str.size();
        for (int j = 0; j < str.size(); j++) {
            alphabet.push_back(str[j]);
            pos[maxSize - size + j].push_back(str[j]);
        }
    }

    sort(alphabet.begin(), alphabet.end());
    alphabet.erase(unique(alphabet.begin(), alphabet.end()), alphabet.end());

    for (int i = 0; i < maxSize; i++) {
        int w = 1;
        for (int j = 0; j < maxSize - i - 1; j++) w = w * 10;

        for (int j = 0; j < pos[i].size(); j++) {
            char c = pos[i][j];
            weight[c - 'A'] += w;
        }
    }

    int num = 9;
    sort(alphabet.begin(), alphabet.end(), compare);
    for (int i = 0; i < alphabet.size(); i++) {
        visited[alphabet[i] - 'A'] = num;
        num--;
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        string tmp = "";
        for (int j = 0; j < V[i].size(); j++) {
            tmp += (visited[V[i][j] - 'A'] + '0');
        }
        sum += stoi(tmp);
    }
    cout << sum;

    return 0;
}