#include <bits/stdc++.h>

using namespace std;

int T, N;
int cube[6][9];

void rotateFace(int index, char dir) {
    int arr[9];
    for (int i = 0; i < 9; i++) {
        arr[i] = cube[index][i];
    }
    if (dir == '+') {
        cube[index][0] = arr[6];
        cube[index][1] = arr[3];
        cube[index][2] = arr[0];
        cube[index][3] = arr[7];
        cube[index][4] = arr[4];
        cube[index][5] = arr[1];
        cube[index][6] = arr[8];
        cube[index][7] = arr[5];
        cube[index][8] = arr[2];
    } else if (dir == '-') {
        cube[index][0] = arr[2];
        cube[index][1] = arr[5];
        cube[index][2] = arr[8];
        cube[index][3] = arr[1];
        cube[index][4] = arr[4];
        cube[index][5] = arr[7];
        cube[index][6] = arr[0];
        cube[index][7] = arr[3];
        cube[index][8] = arr[6];
    }

}

// U D F B L R
// w y r o g b
// 0 1 2 3 4 5
void rotateCube(char face, char dir) {
    switch (face) {
        case 'U':
            if (dir == '+') {
                int tmp1 = cube[2][0];
                int tmp2 = cube[2][1];
                int tmp3 = cube[2][2];

                cube[2][0] = cube[5][0];
                cube[2][1] = cube[5][1];
                cube[2][2] = cube[5][2];

                cube[5][0] = cube[3][0];
                cube[5][1] = cube[3][1];
                cube[5][2] = cube[3][2];

                cube[3][0] = cube[4][0];
                cube[3][1] = cube[4][1];
                cube[3][2] = cube[4][2];

                cube[4][0] = tmp1;
                cube[4][1] = tmp2;
                cube[4][2] = tmp3;

            } else if (dir == '-') {
                int tmp1 = cube[2][0];
                int tmp2 = cube[2][1];
                int tmp3 = cube[2][2];

                cube[2][0] = cube[4][0];
                cube[2][1] = cube[4][1];
                cube[2][2] = cube[4][2];

                cube[4][0] = cube[3][0];
                cube[4][1] = cube[3][1];
                cube[4][2] = cube[3][2];

                cube[3][0] = cube[5][0];
                cube[3][1] = cube[5][1];
                cube[3][2] = cube[5][2];

                cube[5][0] = tmp1;
                cube[5][1] = tmp2;
                cube[5][2] = tmp3;
            }

            rotateFace(0, dir);
            break;

        case 'D':
            if (dir == '+') {
                int tmp1 = cube[2][6];
                int tmp2 = cube[2][7];
                int tmp3 = cube[2][8];

                cube[2][6] = cube[4][6];
                cube[2][7] = cube[4][7];
                cube[2][8] = cube[4][8];

                cube[4][6] = cube[3][6];
                cube[4][7] = cube[3][7];
                cube[4][8] = cube[3][8];

                cube[3][6] = cube[5][6];
                cube[3][7] = cube[5][7];
                cube[3][8] = cube[5][8];

                cube[5][6] = tmp1;
                cube[5][7] = tmp2;
                cube[5][8] = tmp3;
            } else if (dir == '-') {
                int tmp1 = cube[2][6];
                int tmp2 = cube[2][7];
                int tmp3 = cube[2][8];

                cube[2][6] = cube[5][6];
                cube[2][7] = cube[5][7];
                cube[2][8] = cube[5][8];

                cube[5][6] = cube[3][6];
                cube[5][7] = cube[3][7];
                cube[5][8] = cube[3][8];

                cube[3][6] = cube[4][6];
                cube[3][7] = cube[4][7];
                cube[3][8] = cube[4][8];

                cube[4][6] = tmp1;
                cube[4][7] = tmp2;
                cube[4][8] = tmp3;
            }

            rotateFace(1, dir);
            break;

        case 'F':
            if (dir == '+') {
                int tmp1 = cube[0][6];
                int tmp2 = cube[0][7];
                int tmp3 = cube[0][8];

                cube[0][6] = cube[4][8];
                cube[0][7] = cube[4][5];
                cube[0][8] = cube[4][2];

                cube[4][8] = cube[1][6];
                cube[4][5] = cube[1][7];
                cube[4][2] = cube[1][8];

                cube[1][6] = cube[5][0];
                cube[1][7] = cube[5][3];
                cube[1][8] = cube[5][6];

                cube[5][0] = tmp1;
                cube[5][3] = tmp2;
                cube[5][6] = tmp3;

            } else if (dir == '-') {
                int tmp1 = cube[0][6];
                int tmp2 = cube[0][7];
                int tmp3 = cube[0][8];

                cube[0][6] = cube[5][0];
                cube[0][7] = cube[5][3];
                cube[0][8] = cube[5][6];

                cube[5][0] = cube[1][6];
                cube[5][3] = cube[1][7];
                cube[5][6] = cube[1][8];

                cube[1][6] = cube[4][8];
                cube[1][7] = cube[4][5];
                cube[1][8] = cube[4][2];

                cube[4][8] = tmp1;
                cube[4][5] = tmp2;
                cube[4][2] = tmp3;
            }

            rotateFace(2, dir);
            break;

        case 'B':
            if (dir == '+') {
                int tmp1 = cube[0][0];
                int tmp2 = cube[0][1];
                int tmp3 = cube[0][2];

                cube[0][0] = cube[5][2];
                cube[0][1] = cube[5][5];
                cube[0][2] = cube[5][8];

                cube[5][2] = cube[1][0];
                cube[5][5] = cube[1][1];
                cube[5][8] = cube[1][2];

                cube[1][0] = cube[4][6];
                cube[1][1] = cube[4][3];
                cube[1][2] = cube[4][0];

                cube[4][6] = tmp1;
                cube[4][3] = tmp2;
                cube[4][0] = tmp3;

            } else if (dir == '-') {
                int tmp1 = cube[0][0];
                int tmp2 = cube[0][1];
                int tmp3 = cube[0][2];

                cube[0][0] = cube[4][6];
                cube[0][1] = cube[4][3];
                cube[0][2] = cube[4][0];

                cube[4][6] = cube[1][0];
                cube[4][3] = cube[1][1];
                cube[4][0] = cube[1][2];

                cube[1][0] = cube[5][2];
                cube[1][1] = cube[5][5];
                cube[1][2] = cube[5][8];

                cube[5][2] = tmp1;
                cube[5][5] = tmp2;
                cube[5][8] = tmp3;

            }

            rotateFace(3, dir);
            break;

        case 'L':
            if (dir == '+') {
                int tmp1 = cube[0][0];
                int tmp2 = cube[0][3];
                int tmp3 = cube[0][6];

                cube[0][0] = cube[3][8];
                cube[0][3] = cube[3][5];
                cube[0][6] = cube[3][2];

                cube[3][8] = cube[1][8];
                cube[3][5] = cube[1][5];
                cube[3][2] = cube[1][2];

                cube[1][8] = cube[2][0];
                cube[1][5] = cube[2][3];
                cube[1][2] = cube[2][6];

                cube[2][0] = tmp1;
                cube[2][3] = tmp2;
                cube[2][6] = tmp3;

            } else if (dir == '-') {
                int tmp1 = cube[0][0];
                int tmp2 = cube[0][3];
                int tmp3 = cube[0][6];

                cube[0][0] = cube[2][0];
                cube[0][3] = cube[2][3];
                cube[0][6] = cube[2][6];

                cube[2][0] = cube[1][8];
                cube[2][3] = cube[1][5];
                cube[2][6] = cube[1][2];

                cube[1][8] = cube[3][8];
                cube[1][5] = cube[3][5];
                cube[1][2] = cube[3][2];

                cube[3][8] = tmp1;
                cube[3][5] = tmp2;
                cube[3][2] = tmp3;

            }
            rotateFace(4, dir);
            break;

        case 'R':
            if (dir == '+') {
                int tmp1 = cube[0][2];
                int tmp2 = cube[0][5];
                int tmp3 = cube[0][8];

                cube[0][2] = cube[2][2];
                cube[0][5] = cube[2][5];
                cube[0][8] = cube[2][8];

                cube[2][2] = cube[1][6];
                cube[2][5] = cube[1][3];
                cube[2][8] = cube[1][0];

                cube[1][6] = cube[3][6];
                cube[1][3] = cube[3][3];
                cube[1][0] = cube[3][0];

                cube[3][6] = tmp1;
                cube[3][3] = tmp2;
                cube[3][0] = tmp3;


            } else if (dir == '-') {
                int tmp1 = cube[0][2];
                int tmp2 = cube[0][5];
                int tmp3 = cube[0][8];

                cube[0][2] = cube[3][6];
                cube[0][5] = cube[3][3];
                cube[0][8] = cube[3][0];

                cube[3][6] = cube[1][6];
                cube[3][3] = cube[1][3];
                cube[3][0] = cube[1][0];

                cube[1][6] = cube[2][2];
                cube[1][3] = cube[2][5];
                cube[1][0] = cube[2][8];

                cube[2][2] = tmp1;
                cube[2][5] = tmp2;
                cube[2][8] = tmp3;

            }
            rotateFace(5, dir);
            break;
    }
}


void printUp() {
    // w y r o g b
    // 0 1 2 3 4 5

    for (int j = 0; j < 9; j++) {
        switch (cube[0][j]) {
            case 0:
                cout << "w";
                break;
            case 1:
                cout << "y";
                break;
            case 2:
                cout << "r";
                break;
            case 3:
                cout << "o";
                break;
            case 4:
                cout << "g";
                break;
            case 5:
                cout << "b";
                break;
        }
        if (j % 3 == 2) cout << "\n";
    }

}

void init() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube[i][j] = i;
        }
    }
}

int main() {

    cin >> T;
    while (T--) {
        init();
        cin >> N;
        while (N--) {
            string op;
            cin >> op;
            rotateCube(op[0], op[1]);
        }
        printUp();
    }
    return 0;
}