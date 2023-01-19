// programmers week1-1
// 택배 배달과 수거하기
// 실패 (2/10)

#include <bits/stdc++.h>

using namespace std;

int total = 0;

int goDelivery(int cap, int n, vector<int>& deliveries, vector<int>& pickups) {
    int len = 0;
    int cnt = cap;
    for (int i = n - 1; i >= 0; i--) {
        if (deliveries[i] == 0) continue;
        if (len == 0) len = i + 1;
        if (deliveries[i] <= cnt) {
            cnt -= deliveries[i];
            total--;
            deliveries[i] = 0;
        } else {
            deliveries[i] -= cnt;
            cnt = 0;
        }

        if (cnt == 0) {
            return len;
        }
    }
    return len;
}

int goPickUp(int cap, int n, vector<int>& deliveries, vector<int>& pickups) {
    int cnt = 0;
    int len = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (pickups[i] == 0) continue;
        if (len == 0) len = i + 1;
        if (pickups[i] >= cnt) {
            cnt += pickups[i];
            total--;
            pickups[i] = 0;
        } else {
            pickups[i] -= (cap - cnt);
            cnt = cap;
        }

        if (cnt == cap) {
            return len;
        }
    }
    return len;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    for(int i=0;i<n;i++) {
        if(deliveries[i] != 0) total++;
        if(pickups[i] != 0) total++;
    }

//    cin >> cap >> n;
//
//    for (int i = 0; i < n; i++) {
//        int delivery;
//        cin >> delivery;
//        if(delivery != 0) total++;
//        deliveries.push_back(delivery);
//    }
//
//    for (int i = 0; i < n; i++) {
//        int pickup;
//        cin >> pickup;
//        if(pickup != 0) total++;
//        pickups.push_back(pickup);
//    }

    int result = 0;
    while(1) {
        int d = goDelivery(cap, n, deliveries, pickups);
        int p = goPickUp(cap, n, deliveries, pickups);
//        printf("\ndeliveries\n");
//        for(int j=0;j<n;j++) {
//            printf("%d ", deliveries[j]);
//        }
//        printf("\npickups\n");
//        for(int j=0;j<n;j++) {
//            printf("%d ", pickups[j]);
//        }
//        printf("d = %d, p = %d, total = %d\n", d, p, total);
        int len = 2 * max(d, p);
        result += len;
        if(total == 0) break;
    }

    return result;
}

int main() {
    int cap = 4;
    int n = 5;
    vector<int> A;
    A.push_back(1);
    A.push_back(0);
    A.push_back(3);
    A.push_back(1);
    A.push_back(2);

    vector<int> B;
    B.push_back(0);
    B.push_back(3);
    B.push_back(0);
    B.push_back(4);
    B.push_back(0);

    cout << solution(cap, n, A, B) << '\n';

}

/*
4 5
1 0 3 1 2
0 3 0 4 0

 2 7
 1 0 2 0 1 0 2
 0 2 0 1 0 2 0

 */