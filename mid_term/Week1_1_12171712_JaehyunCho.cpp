//
// W1_A: Zigzag_Strings
// Created by jaehyun on 2021/09/03.
//

#include <iostream>
#include <string>

using namespace std;

void solve(const string &s, int k) {
    char arr[1001][101];

    for (auto &i: arr) {
        for (char &j: i) {
            j = '\0';
        }
    }

    int ctr = 0;
    int row = 0;
    while (ctr < s.length()) {
        for (int i = 0; i < k; i++) {
            if (ctr >= s.length()) break;
            row % 2 == 0 ? arr[row][i] = s[ctr] : arr[row][k - i - 1] = s[ctr];
            ctr++;
        }
        row++;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; arr[j][i] != '\0'; j++) {
            cout << arr[j][i];
        }
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        solve(s, k);
    }

    return 0;
}