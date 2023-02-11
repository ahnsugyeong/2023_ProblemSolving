// programmers week4-3
// 프린터

#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq; // priority queue 사용하여 최댓값 갱신

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
    }

    while (1) {
        for (int i = 0; i < priorities.size(); i++) {
            if (pq.top() == priorities[i]) {
                answer++; // print
                pq.pop();
                if (i == location) return answer;
            }
        }
    }
}

/*

A B C D E F
1 1 9 1 7 1
loc: 5
exp: 3

B C D E F A
1 9 1 7 1 1

C D E F A B
9 1 7 1 1 1 -> C

D E F A B
1 7 1 1 1

E F A B D
7 1 1 1 1 -> E

F A B D
1 1 1 1 -> F

res: 3


//////////////////////



A B C D E F
1 1 7 1 9 1

E F A B C D
9 1 1 1 7 1 -> E

C D F A B
7 1 1 1 1 -> C

D F A B
1 1 1 1 -> D

F A B
1 1 1 -> F

 */