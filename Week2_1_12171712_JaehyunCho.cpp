//
// W2_1: Matching_Sentences
// Created by 조재현 on 2021/09/10.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int t, n, m, k, answer;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> m;

        string sentence[2001];
        queue<string> word[21];

        // 입력
        for (int i = 0; i < m; i++) {
            cin >> sentence[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                cin >> s;
                word[i].push(s);
            }
        }

        // 해결
        for (int i = 0; i < m; i++) {
            answer = 0;
            for (int j = 0; j < n; j++) {
                if (sentence[i] == word[j].front()) {
                    word[j].pop();
                    answer = 1;
                    break;
                }
            }
            if (answer == 0) break;
        }
        cout << answer << '\n';
    }

    return 0;
}