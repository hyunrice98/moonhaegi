//
// W9_2: Othello
// Created by 조재현 on 2021/10/29.
// WARN: 안나올 확률 높음...
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct point {
    int x;
    int y;

    point() {}

    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int grid[21][21];
set<point> candidate;
vector<int> check[21][21][2];

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
int n, q, t;

int candidateCheckFunc() {
    int ret = 0;
    for (point p: candidate) {
        check[p.x][p.y][1].clear();
        check[p.x][p.y][2].clear();
        for (int i = 0; i < 8; i++) {
            int flag = grid[p.x + dx[i]][p.y + dy[i]];
            if (flag <= 0) continue;
            for (int j = 1; j < n; j++) {
                if (grid[p.x + dx[i] * j][p.y + dy[i] * j] <= 0) break;
                else if (grid[p.x + dx[i] * j][p.y + dy[i] * j] != flag) {
                    check[p.x][p.y][grid[p.x + dx[i] * j][p.y + dy[i] * j]].push_back(i);
                    ret |= grid[p.x + dx[i] * j][p.y + dy[i] * j];
                    break;
                }
            }
        }
    }
    return ret;
}

void aroundCandidateFunc(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (grid[X][Y] == 0) candidate.insert(point(x, y));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> q;

        // initial rock setting
        grid[n / 2][n / 2] = grid[n / 2 + 1][n / 2 + 1] = 1;
        grid[n / 2 + 1][n / 2] = grid[n / 2][n / 2 + 1] = 2;

        // setting candidate close to initial rock
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                aroundCandidateFunc(n / 2 + i, n / 2 + j);
            }
        }

        // turn1: black, turn2: white
        int turn = 1;
        while (q--) {
            int x, y;
            cin >> x >> y;

            int flag = candidateCheckFunc();
            if ((flag & turn) == 0)
                turn = flag;

            if (grid[x][y] != 0) continue;

            if (check[x][y][turn].empty() == true) continue;

            for (int k = 1; k <= check[x][y][turn].size(); k++) {
                int i = check[x][y][turn][k];
                for (int j = 1; j <= n; j++) {
                    if (grid[x + dx[i] * j][y + dy[i] * j] == turn) break;
                    grid[x + dx[i] * j][y + dy[i] * j] = turn;
                }
            }
            grid[x][y] = turn;

            if (turn == 1) turn = 2;
            else turn = 1;
            candidate.erase(point(x, y));
            aroundCandidateFunc(x, y);
        }
    }


    return 0;
}