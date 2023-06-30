// baekjoon 14890

#include <bits/stdc++.h>

using namespace std;

int N, L;
int arr[100][100];
bool check[100];


bool checkRoad(int idx, int dir) {
    memset(check, 0, sizeof(check));

    // dir -> 0: 행, 1: 열
    int mapArr[100];
    if (dir == 0) {
        for (int i = 0; i < N; i++) {
            mapArr[i] = arr[idx][i];
        }
    } else {
        for (int i = 0; i < N; i++) {
            mapArr[i] = arr[i][idx];
        }
    }

    for (int i = 0; i < N - 1; i++) {
        if (mapArr[i] == mapArr[i + 1]) continue;
        if (abs(mapArr[i] - mapArr[i + 1]) >= 2) return false;  // 칸 차이가 2 이상이면 경사로 설치 불가능

        // / 모양 경사로 설치
        if (mapArr[i] < mapArr[i + 1]) {
            for (int j = 0; j < L; j++) {
                if (i - j < 0) {
                    return false;    // 경사로가 지도 범위를 벗어나 설치 불가능
                }
                if (check[i - j]) {
                    return false;    // 경사로가 이미 설치되어 있어서 중복 설치 불가능
                }
                if (mapArr[i - j] != mapArr[i]) {
                    return false;   // 경사로를 놓을 낮은 칸의 높이가 다르면 설치 불가능
                }
                check[i - j] = true;
            }
        }

        // \ 모양 경사로 설치
        else if (mapArr[i] > mapArr[i + 1]) {
            for (int j = 0; j < L; j++) {
                if (i + 1 + j > N - 1) {
                    return false;    // 경사로가 지도 범위를 벗어나 설치 불가능
                }
                if (check[i + 1 + j]) {
                    return false;    // 경사로가 이미 설치되어 있어서 중복 설치 불가능
                }
                if (mapArr[i + 1 + j] != mapArr[i + 1]) {
                    return false;   // 경사로를 놓을 낮은 칸의 높이가 다르면 설치 불가능
                }
                check[i + 1 + j] = true;
            }
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for(int i=0;i<N;i++) {
        if (checkRoad(i, 0)) {
            ans ++;
        }

        if (checkRoad(i, 1)) {
            ans ++;
        }
    }

    cout << ans;
    return 0;
}