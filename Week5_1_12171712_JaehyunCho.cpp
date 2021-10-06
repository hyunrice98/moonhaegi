//
// W5_1: Signal_Interpretation
// Created by 조재현 on 2021/10/01.
//

#include <iostream>

using namespace std;

int t, n;
int x[5001];

void print(int size) {
    for (int i = 0; i < size; i++) {
        cout << x[i] << " ";
    }
    cout << '\n';
}

void checkIdentical() {
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (x[j] != x[j % i]) break;
            if (j == n - 1) {
                print(i);
                return;
            }
        }
    }
    print(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        checkIdentical();
    }

    return 0;
}