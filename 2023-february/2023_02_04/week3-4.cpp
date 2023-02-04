// programmers week3-4
// 블로그 참고

#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    int quotient = n;
    int remainder = 0;

    while(quotient) {
        remainder = quotient % 3;
        quotient = quotient / 3;

        switch (remainder) {
            case 0:
                answer = "4" + answer;
                quotient--;
                break;
            case 1:
                answer = "1" + answer;
                break;

            case 2:
                answer = "2" + answer;
        }
    }

    return answer;
}