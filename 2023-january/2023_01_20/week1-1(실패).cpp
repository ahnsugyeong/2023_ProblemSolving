// programmers week1-1
// 택배 배달과 수거하기
// 실패 (19/20) -> 테스트 16 시간초과

#include <bits/stdc++.h>

using namespace std;

int totalD = 0;
int totalP = 0;

int goDelivery(int cap, int n, vector<int> &deliveries, vector<int> &pickups) {
    int len = 0;
    int cnt = cap;
    for (int i = n - 1; i >= 0; i--) {
        if (deliveries[i] == 0) continue;
        if (len == 0) len = i + 1;
        if (deliveries[i] <= cnt) {
            cnt -= deliveries[i];
            totalD--;
            deliveries[i] = 0;
        } else {
            deliveries[i] -= cnt;
            cnt = 0;
        }

        if (cnt == 0 || totalD == 0) {
            return len;
        }
    }
    return len;
}

int goPickUp(int cap, int n, vector<int> &deliveries, vector<int> &pickups) {
    int cnt = 0;
    int len = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (pickups[i] == 0) continue;
        if (len == 0) len = i + 1;
        if (pickups[i] > cap - cnt) {
            pickups[i] -= (cap - cnt);
            cnt = cap;
        } else {
            cnt += pickups[i];
            pickups[i] = 0;
            totalP--;
        }

        if (cnt == cap || totalP == 0) {
            return len;
        }
    }
    return len;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    for (int i = 0; i < n; i++) {
        if (deliveries[i] != 0) totalD++;
        if (pickups[i] != 0) totalP++;
    }

    long long result = 0;
//    printf("\ndeliveries\n");
//    for (int j = 0; j < n; j++) {
//        printf("%d ", deliveries[j]);
//    }
//    printf("\npickups\n");
//    for (int j = 0; j < n; j++) {
//        printf("%d ", pickups[j]);
//    }
//    printf("\n");
    while (1) {
        int d = 0, p = 0;
        if(totalD == 0 && totalP == 0) break;
        if(totalD != 0) {
            d = goDelivery(cap, n, deliveries, pickups);
        }
        if(totalP != 0) {
            p = goPickUp(cap, n, deliveries, pickups);
        }


//        printf("\ndeliveries\n");
//        for (int j = 0; j < n; j++) {
//            printf("%d ", deliveries[j]);
//        }
//        printf("\npickups\n");
//        for (int j = 0; j < n; j++) {
//            printf("%d ", pickups[j]);
//        }
//        printf("\nd = %d, p = %d, total = %d\n", d, p, total);
        int len = 2 * max(d, p);
        result += len;

    }


    return result;
}


void example() {
    int cap = 2;
    int n = 2;

    vector<int> A;
    A.push_back(0);
    A.push_back(0);

    vector<int> B;
    B.push_back(0);
    B.push_back(0);


    printf("%d\n", solution(cap,n, A, B));

}

int main() {
    example();

}