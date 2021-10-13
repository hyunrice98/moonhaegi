//
// W5_1: Signal_Interpretation
// Created by 조재현 on 2021/10/08.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Point {
    int x;
    int y;
};

int check[1001][1001];
bool visited[1001][1001];

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, -1, 1, 0, -1, 1};
Point inha, safe, knight, gunner;
int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> inha.x >> inha.y >> safe.x >> safe.y >> knight.x >> knight.y >> gunner.x >> gunner.y;
        for (int i = 0; i < 1001; i++) {
            memset(visited[i], false, sizeof(bool) * 1001);
            memset(check[i], 0, sizeof(int) * 1001);
        }

        // attack range for gunner
        for (int i = 0; i < 8; i++) {
            for (int j = 1; j <= n; j++) {
                // out of grid index
                if (gunner.x + dx[i] * j == 0 || gunner.x + dx[i] * j == n + 1 ||
                    gunner.y + dy[i] * j == 0 || gunner.y + dy[i] * j == n + 1)
                    break;
                // stuck by knight
                if (gunner.x + dx[i] * j == knight.x && gunner.y + dy[i] * j == knight.y)
                    break;
                check[gunner.x + dx[i] * j][gunner.y + dy[i] * j] = -1;
            }
        }
        // attack range for knight
        for (int i = 0; i < 8; i++) {
            if (knight.x + dx[i] == 0 || knight.x + dx[i] == n + 1 ||
                knight.y + dy[i] == 0 || knight.y + dy[i] == n + 1)
                continue;
            check[knight.x + dx[i]][knight.y + dy[i]] = -1;
        }
        // queue for dfs
        queue<Point> q;
        // start from inha's place
        q.push({inha.x, inha.y});
        // no element in queue -> exit
        while (!q.empty()) {
            Point now = q.front();
            q.pop();
            visited[now.x][now.y] = true;
            for (int i = 0; i < 8; i++) {
                // out of grid index
                if (now.x + dx[i] == 0 || now.x + dx[i] == n + 1 ||
                    now.y + dy[i] == 0 || now.y + dy[i] == n + 1)
                    continue;
                // attack range of enemy || already visited place
                if (check[now.x + dx[i]][now.y + dy[i]] != 0 ||
                    visited[now.x + dx[i]][now.y + dy[i]])
                    continue;
                check[now.x + dx[i]][now.y + dy[i]] = check[now.x][now.y] + 1;
                q.push({now.x + dx[i], now.y + dy[i]});
            }
        }
        cout << check[safe.x][safe.y] << '\n';
    }

    return 0;
}
