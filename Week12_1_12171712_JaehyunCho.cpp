//
// W12_1: Triangle_Path
// Created by 조재현 on 2021/11/19.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n;
int tri[101][101];
int dp[101][101];
int result[101];

void clear() {
    memset(result, 0, sizeof(result));
    for (int i = 0; i < 101; i++) {
        memset(tri[i], 0, sizeof(tri[i]));
        memset(dp[i], 0, sizeof(dp[i]));
    }
}

int solve(int a, int b) {
    if (dp[a][b] != 0) return dp[a][b];
    if (a == b) {
        dp[a][b] = solve(a - 1, b - 1) + tri[a][b];
    } else if (b == 0) {
        dp[a][b] = solve(a - 1, b) + tri[a][b];
    } else {
        dp[a][b] = min(solve(a - 1, b - 1), solve(a - 1, b)) + tri[a][b];
    }
    return dp[a][b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> tri[i][j];
            }
        }

        dp[0][0] = tri[0][0];
        for (int i = 0; i < n; i++) {
            result[i] = solve(n - 1, i);
        }
        sort(result, result + n);
        cout << result[0] << '\n';
    }

    return 0;
}