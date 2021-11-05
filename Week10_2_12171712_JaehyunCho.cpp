//
// W10_2: Matryoshka
// Created by 조재현 on 2021/11/05.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n;
int arr[501];
int result[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(result, 0, sizeof(result));

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        result[0] = 1;
        for (int i = 1; i < n; i++) {
            result[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) result[i] = max(result[i], result[j] + 1);
            }
        }

        sort(result, result + n);
        cout << result[n - 1] << '\n';
    }

    return 0;
}

// 100000