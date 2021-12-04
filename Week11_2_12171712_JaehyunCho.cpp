//
// W11_2: Cutting_Paper
// Created by 조재현 on 2021/11/12.
//

#include <iostream>
#include <cstring>

using namespace std;

int t, n;
int grid[1024][1024];
char input;
int rNum, rSize, bNum, bSize;

void clear() {
    for (auto &i: grid) {
        memset(i, 0, sizeof(i));
    }
    n = 0;
    rNum = 0;
    rSize = 0;
    bNum = 0;
    bSize = 0;
}

void solve(int a, int b, int c, int d) {
    int state = grid[a][c];
    for (int i = a; i < b; i++) {
        for (int j = c; j < d; j++) {
            if (grid[i][j] != state) {
                solve(a, (a + b) / 2, c, (c + d) / 2);
                solve((a + b) / 2, b, c, (c + d) / 2);
                solve(a, (a + b) / 2, (c + d) / 2, d);
                solve((a + b) / 2, b, (c + d) / 2, d);
                return;
            }
        }
    }
    if (state == 1) {
        ++rNum;
        rSize += (b - a) * (b - a);
    } else {
        ++bNum;
        bSize += (b - a) * (b - a);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> input;
                if (input == 'R') {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = 0;
                }
            }
        }
        solve(0, n, 0, n);
        cout << rNum << ' ' << rSize << ' ' << bNum << ' ' << bSize << '\n';
        clear();
    }

    return 0;
}