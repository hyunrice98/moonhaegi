//
// W7_2:
// Created by 조재현 on 2021/10/15.
//

#include <iostream>
#include <queue>

using namespace std;

struct ham {
    int x;
    int y;
    int dist;

    ham() {}

    ham(int x, int y) {
        this->x = x;
        this->y = y;
        this->dist = x * x + y * y;
    }
};

struct comp {
    bool operator()(ham a, ham b) {
        if (a.dist == b.dist) {
            if (a.x == b.x) {
                return a.y > b.y;
            }
            return a.x > b.x;
        }
        return a.dist > b.dist;
    }
};

struct comp2 {
    bool operator()(ham a, ham b) {
        if (a.dist == b.dist) {
            if (a.x == b.x) {
                return a.y < b.y;
            }
            return a.x < b.x;
        }
        return a.dist < b.dist;
    }
};

int t, m, n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        priority_queue<ham, vector<ham>, comp2> s_pq;
        priority_queue<ham, vector<ham>, comp> l_pq;
        queue<ham> q;

        cin >> m >> n >> k;
        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            s_pq.push(ham(x, y));
        }
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            q.push(ham(x, y));
        }

        for (int i = k; i <= m; i++) {
            ham temp = s_pq.top();
            s_pq.pop();
            l_pq.push(temp);
        }

        for (int i = 0; i < n; i++) {
            ham h = q.front();
            q.pop();
            s_pq.push(h);
            ham temp = s_pq.top();
            s_pq.pop();
            l_pq.push(temp);
            ham top = l_pq.top();
            cout << top.x << ' ' << top.y << '\n';
        }
    }

    return 0;
}
