#include <bits/stdc++.h>

using namespace std;

int N, ans;
int board[20][20];

stack<int> move(queue<int> Q) {
    stack<int> result;
    int prev = 0;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if (prev == 0) {
            prev = cur;
            continue;
        }
        if (prev == cur) {
            result.push(cur * 2);
            prev = 0;
        } else {
            result.push(prev);
            prev = cur;
        }
    }
    if (prev != 0) result.push(prev);
    return result;
}

void moveElem(int board[][20], int idx) {
    if (idx == 0) { // 상
        for (int j = 0; j < N; j++) {
            queue<int> Q;
            for (int i = N - 1; i >= 0; i--) {
                if (board[i][j] != 0) Q.push(board[i][j]);
            }

            stack<int> result = move(Q);
            for (int i = 0; i < N; i++) {
                if (!result.empty()) {
                    board[i][j] = result.top();
                    result.pop();
                } else board[i][j] = 0;
            }
        }
    } else if (idx == 1) {   // 하
        for (int j = 0; j < N; j++) {
            queue<int> Q;
            for (int i = 0; i < N; i++) {
                if (board[i][j] != 0) Q.push(board[i][j]);
            }

            stack<int> result = move(Q);
            for (int i = N - 1; i >= 0; i--) {
                if (!result.empty()) {
                    board[i][j] = result.top();
                    result.pop();
                } else board[i][j] = 0;
            }
        }
    } else if (idx == 2) {   // 좌
        for (int i = 0; i < N; i++) {
            queue<int> Q;
            for (int j = N - 1; j >= 0; j--) {
                if (board[i][j] != 0) Q.push(board[i][j]);
            }

            stack<int> result = move(Q);
            for (int j = 0; j < N; j++) {
                if (!result.empty()) {
                    board[i][j] = result.top();
                    result.pop();
                } else board[i][j] = 0;
            }
        }
    } else if (idx == 3) {   // 우
        for (int i = 0; i < N; i++) {
            queue<int> Q;
            for (int j = 0; j < N; j++) {
                if (board[i][j] != 0) Q.push(board[i][j]);
            }

            stack<int> result = move(Q);
            for (int j = N - 1; j >= 0; j--) {
                if (!result.empty()) {
                    board[i][j] = result.top();
                    result.pop();
                } else board[i][j] = 0;
            }
        }
    }

}

void DFS(int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans = max(ans, board[i][j]);
            }
        }
        return;
    }

    int copyBoard[20][20];
    for (int idx = 0; idx < 4; idx++) {
//        memcpy(copyBoard, board, sizeof(board));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                copyBoard[i][j] = board[i][j];
            }
        }

        moveElem(board, idx);
        DFS(cnt + 1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = copyBoard[i][j];
            }
        }
//        memcpy(board, copyBoard, sizeof(board));
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    DFS(0);
    cout << ans;
}
