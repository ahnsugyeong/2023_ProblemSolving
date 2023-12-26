#include <iostream>
#include <climits>

using namespace std;

int N;
int area[21][21];
int ans = INT_MAX;

void selectInfo(int cnt);

void getMinGap(int x, int y, int d1, int d2);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> area[i][j];
        }
    }

    selectInfo(0);

    cout << ans;
}


bool boundary[21][21];

void setBoundary(int x, int y, int d1, int d2) {
    fill(&boundary[1][1], &boundary[21][0], false);

    // boundary #1
    for (int i = 0; i <= d1; i++) {
        boundary[x + i][y - i] = true;
    }

    // boundary #2
    for (int i = 0; i <= d2; i++) {
        boundary[x + i][y + i] = true;
    }

    // boundary #3
    for (int i = 0; i <= d2; i++) {
        boundary[x + d1 + i][y - d1 + i] = true;
    }

    // boundary #4
    for (int i = 0; i <= d1; i++) {
        boundary[x + d2 + i][y + d2 - i] = true;
    }

}

int population[5];
void getMinGap(int x, int y, int d1, int d2) {
    setBoundary(x, y, d1, d2);

    fill(population, population + 5, 0);

    // area #1
    for (int i = 1; i < x + d1; i++) {
        for (int j = 1; j <= y; j++) {
            if (boundary[i][j]) break;
            population[0] += area[i][j];
        }
    }

    // area #2
    for (int i = 1; i <= x + d2; i++) {
        for (int j = N; j > y; j--) {
            if (boundary[i][j]) break;
            population[1] += area[i][j];
        }
    }


    // area #3
    for (int i = N; i >= x + d1; i--) {
        for (int j = 1; j < y - d1 + d2; j++) {
            if (boundary[i][j]) break;
            population[2] += area[i][j];
        }
    }

    // area #4
    for (int i = N; i > x + d2; i--) {
        for (int j = N; j >= y - d1 + d2; j--) {
            if (boundary[i][j]) break;
            population[3] += area[i][j];
        }
    }

    int entireArea = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            entireArea += area[i][j];
        }
    }

    population[4] = entireArea - (population[0] + population[1] + population[2] + population[3]);

    int maxPopulation = population[0];
    int minPopulation = population[0];
    for (int i = 0; i < 5; i++) {
        maxPopulation = max(maxPopulation, population[i]);
        minPopulation = min(minPopulation, population[i]);
    }
    int gap = maxPopulation - minPopulation;
    ans = min(ans, gap);
}

/*
 * d1, d2 ≥ 1 ✅
 * 1 ≤ x < x+d1+d2 ≤ N ✅
 * 1 ≤ y-d1 < y < y+d2 ≤ N ✅
 * */
int selected[4];

void selectInfo(int cnt) {
    if (cnt == 4) {
        int x = selected[0];
        int y = selected[1];
        int d1 = selected[2];
        int d2 = selected[3];
        if (x + d1 + d2 > N) return;
        if (y - d1 < 1 || y + d2 > N) return;
        getMinGap(x, y, d1, d2);
        return;
    }

    for (int i = 1; i <= N; i++) {
        selected[cnt] = i;
        selectInfo(cnt + 1);
    }
}