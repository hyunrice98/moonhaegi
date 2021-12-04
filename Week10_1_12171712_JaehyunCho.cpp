//
// W10_1: Escape_Room
// Created by 조재현 on 2021/11/05.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t, a, b;
// road[a]: movable room number from a
vector<int> road[10000];
int check[10000];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    for (int i = 0; i < 10000; i++) {
        if (i != 0) road[i].push_back(i - 1);
        if (i != 9999) road[i].push_back(i + 1);

        // reverse order
        int num = 0;
        int temp = i;
        for (int j = 0; j <= 3; j++) {
            num = num * 10 + temp % 10;
            temp /= 10;
        }
        road[i].push_back(num);
    }

    cin >> t;
    while (t--) {
        for (int & i : check) i = 10000;
        cin >> a >> b;
        check[a] = 0;
        q.push(a);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < road[now].size(); i++) {
                if (check[road[now][i]] > check[now] + 1) {
                    q.push(road[now][i]);
                    check[road[now][i]] = check[now] + 1;
                }
            }
        }
        cout << check[b] << '\n';
    }

    return 0;
}