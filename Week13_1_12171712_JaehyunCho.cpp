//
// W13_1: Word_Puzzles
// Created by 조재현 on 2021/11/26.
//

#include <iostream>
#include <string>

using namespace std;

int n, m;
string puzzle[3001];
int f[3001];

bool kmpMatch(string t, string p) {
    int i = 0;
    int j = 0;
    while (i < t.size()) {
        if (t[i] == p[j]) {
            if (j == p.size() - 1) return true;
            i++;
            j++;
        } else if (j > 0) {
            j = f[j - 1];
        } else {
            i++;
        }
    }
    return false;
}

void failureFunction(string p) {
    f[0] = 0;
    int i = 1;
    int j = 0;
    while (i < p.size()) {
        if (p[i] == p[j]) {
            f[i] = j + 1;
            i++;
            j++;
        } else if (j > 0) {
            j = f[j - 1];
        } else {
            f[i] = 0;
            i++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> puzzle[i];
    }

    string text, word;
    for (int i = 0; i < n; i++) {
        text += puzzle[i];
        text += "$";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            text += puzzle[j][i];
        }
        text += "$";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            text += puzzle[j][i + j];
        }
        text += "$";
    }

    while (m--) {
        cin >> word;
        failureFunction(word);
        kmpMatch(text, word) ? cout << 1 << '\n' : cout << 0 << '\n';
    }

    return 0;
}