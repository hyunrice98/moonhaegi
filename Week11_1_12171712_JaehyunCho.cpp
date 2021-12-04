//
// W11_1: Making_English_Words
// Created by 조재현 on 2021/11/12.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int score[24];
int needAlphabet[24][27];
int restAlphabet[10000000][27];

int m, answer;
string word;
int getScore[10000000];

void solution() {
    getScore[0] = 0;
    for (int i = 0; i < m; i++) {
        int status = 1 << i;
        for (int j = 0; j < status; j++) {
            bool flag = false;
            for (int k = 0; k < 26; k++) {
                if (restAlphabet[j][k] < needAlphabet[i][k]) flag = true;
            }
            if (flag == true) continue;
            for (int k = 0; k < 26; k++) restAlphabet[j + status][k] = restAlphabet[j][k] - needAlphabet[i][k];
            getScore[j + status] = getScore[j] + score[i];
            answer = max(answer, getScore[j + status]);
        }
    }
}

int main() {
    for (int i = 0; i < 26; i++) cin >> restAlphabet[0][i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> word >> score[i];
        for (char j : word) {
            ++needAlphabet[i][j - 'a'];
        }
    }
    solution();
    cout << answer;
    return 0;
}