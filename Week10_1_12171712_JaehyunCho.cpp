//
// W10_1: Escape_Room
// Created by 조재현 on 2021/11/05.
//

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int t, a, b;
int num[10001];

int reverseNum(int q) {
    string s = to_string(q);
    reverse(s.begin(), s.end());
    if (s.length() < 4) {
        while (s.length() != 4) s += '0';
    }
    return stoi(s);
}

int solve() {
    queue<int> q;
    q.push(a);
    num[a] = 0;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        if (tmp == b) return num[tmp];

        int addNum = tmp + 1;
        if (0 <= addNum && addNum <= 9999 && num[addNum] == 0) {
            num[addNum] = num[tmp] + 1;
            q.push(addNum);
            if (addNum == b)
                return num[addNum];
        }
        int subNum = tmp - 1;
        if (0 <= subNum && subNum <= 9999 && num[subNum] == 0) {
            num[subNum] = num[tmp] + 1;
            q.push(subNum);
            if (subNum == b)
                return num[subNum];
        }
        int reversedNum = reverseNum(tmp);
        if (0 <= reversedNum && reversedNum <= 9999 && num[reversedNum] == 0) {
            num[reversedNum] = num[tmp] + 1;
            q.push(reversedNum);
            if (reversedNum == b)
                return num[reversedNum];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        memset(num, 0, sizeof(num));
        cin >> a >> b;
        cout << solve() << '\n';
    }
    return 0;
}