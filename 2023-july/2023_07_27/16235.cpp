#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int A[11][11];
int tmp[11][11];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

typedef struct Tree {
    int x;
    int y;
    int z;
} Tree;
vector<Tree> trees;
vector<Tree> deadTrees;

void spring() {
    vector<Tree> newTrees;
    for (int i = 0; i < trees.size(); i++) {
        Tree cur = trees[i];
        if (A[cur.x][cur.y] >= cur.z) {
            A[cur.x][cur.y] -= cur.z;
            cur.z++;
            newTrees.push_back(cur);
        } else {
            deadTrees.push_back(cur);
        }
    }
    trees = newTrees;
}

void summer() {
    for (int i = 0; i < deadTrees.size(); i++) {
        Tree cur = deadTrees[i];
        A[cur.x][cur.y] += cur.z / 2;
    }
    deadTrees.clear();
}

void autumn() {
    vector<Tree> newTrees;
    for (int i = 0; i < trees.size(); i++) {
        Tree cur = trees[i];
        if (cur.z % 5 != 0) continue;
        for (int idx = 0; idx < 8; idx++) {
            int new_x = cur.x + dx[idx];
            int new_y = cur.y + dy[idx];
            if (new_x < 1 || new_x > N || new_y < 1 || new_y > N) continue;
            newTrees.push_back({new_x, new_y, 1});
        }
    }
    trees.insert(trees.begin(), newTrees.begin(), newTrees.end());
}

void winter() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            A[i][j] += tmp[i][j];
        }
    }
}

bool compare(Tree &a, Tree &b) {
    return a.z < b.z;
}
void init() {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            A[i][j] = 5;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> tmp[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        trees.push_back({x, y, z});
    }

    sort(trees.begin(), trees.end(), compare);
}

int main() {

    init();

    while(K--) {
        spring();
        summer();
        autumn();
        winter();
    }
    cout << trees.size();

    return 0;
}