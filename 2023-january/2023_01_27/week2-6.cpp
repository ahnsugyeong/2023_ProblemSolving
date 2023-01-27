// programmers week2-6
// 멀쩡한 사각형

#include <bits/stdc++.h>

using namespace std;

long long GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long solution(int w, int h) {
    // total - gcd * (w / gcd + h / gcd - 1);
    return (long long) w * h - (w + h - GCD(w, h));
}
/*
 * long long total = w * h;
 * return total - (w + h - GCD(w, h)); -> test 12 ~ 17 실패
 */