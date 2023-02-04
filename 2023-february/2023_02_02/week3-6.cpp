// programmers week3-6
// 다음 큰 숫자

#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    string n_binary = bitset<8>(n).to_string();
    int total = 0;
    for (int i = 0; i < n_binary.size(); i++) {
        if (n_binary[i] == '1') total++;
    }

    while (1) {
        n++;
        string binary = bitset<8>(n).to_string();

        int cnt = 0;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '1') cnt++;
        }
        if (cnt == total) return n;
    }
}