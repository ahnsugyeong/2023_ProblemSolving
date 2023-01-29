// programmers week2-9
// 줄 서는 방법
// permutation 사용 X. 해당 번쨰의 순열을 직접 만들어내는 방식

#include <bits/stdc++.h>

using namespace std;

long long factorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}


vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> num;
    for (int i = 1; i <= n; i++) num.push_back(i);
    while (n) {
        long long size = factorial(n) / n;
        int index = (long long)((k - 1) / size);
        if (k % size == 0) k = size;
        else k %= size;

        answer.push_back(num[index]);
        num.erase(num.begin() + index);
        n--;
    }
    return answer;
}