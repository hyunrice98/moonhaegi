//
// W13_2: Message_Management
// Created by 조재현 on 2021/11/26.
//

#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int t, n, m;
set<int> s;
int input[500001];
int result[500001];

void reset() {
    s.clear();
    memset(input, 0, sizeof(input));
    memset(result, 0, sizeof(result));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        reset();
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> input[i];
        }
        for (int i = m - 1; i >= 0; i--) {
            s.insert(input[i]);
            result[i] = n - s.size();
        }
        for (int i = 0; i < m; i++) {
            cout << result[i] << '\n';
        }
    }

    return 0;
}

