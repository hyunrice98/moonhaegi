//
// Gichul1_A: DNA
// Created by 조재현 on 2021/09/07.
//

#include <iostream>
#include <string>

using namespace std;

char letters[4] = {'A', 'C', 'G', 'T'};

// m: indices of string input
// n: length of string input
void solve(int m, int n) {
    string genes[51];
    for (int i = 0; i < m; i++) {
        cin >> genes[i];
    }

    // Printing best DNA
    string best;
    for (int i = 0; i < n; i++) {
        int freqs[4] = {0, 0, 0, 0};
        for (int j = 0; j < m; j++) {
            switch (genes[j][i]) {
                case 'A':
                    freqs[0]++;
                    break;
                case 'C':
                    freqs[1]++;
                    break;
                case 'G':
                    freqs[2]++;
                    break;
                case 'T':
                    freqs[3]++;
                    break;
                default:
                    cout << "YOU FUCKED UP\n";
            }
        }
        int max = -123456789, maxIndex = 0;
        for (int j = 0; j < 4; j++) {
            if (freqs[j] > max) {
                max = freqs[j];
                maxIndex = j;
            }
        }
        best += letters[maxIndex];
    }
    cout << best << '\n';

    // Printing hemming length
    int length = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (best[j] != genes[i][j]) length++;
        }
    }
    cout << length << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        solve(m, n);
    }

    return 0;
}