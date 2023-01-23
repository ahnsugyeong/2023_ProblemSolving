// programmers week1-3
// 마법의 엘리베이터

#include <bits/stdc++.h>

using namespace std;


// storey = 민수와 마법의 엘리베이터가 있는 층
// 0층으로 가야 함.

int solution(int storey) {
    int cnt = 0;
    while (storey) {
        int n = storey % 10;

        if (n > 5 || (n == 5 && storey / 10 % 10 >= 5)) {
            cnt += 10 - n;
            storey += 10 - n;
        } else {
            cnt += n;
        }
        storey /= 10;
    }
    return cnt;
}