//
// W7_1:
// Created by 조재현 on 2021/10/15.
//

#include <iostream>
#include <cstring>

using namespace std;

int t, n, m;
int arr[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            arr[a][b] = 1;
            arr[b][a] = -1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (arr[j][i] == arr[i][k] && arr[j][i] != 0)
                        arr[j][k] = arr[j][i];
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            int result = 0;
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] == 1) result++;
            }
            cout << result << ' ';
        }
        cout << '\n';

        for (auto & i : arr) {
            memset(i, 0, sizeof(int) * 101);
        }
    }

    return 0;
}