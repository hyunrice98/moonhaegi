//
// W7_2: Hamburger_Store
// Created by 조재현 on 2021/10/15.
//

#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

int t, m, n, k, x, y;

struct Point {
    int x;
    int y;
    double dist;

    Point(int x, int y, double dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

struct comp {
    bool operator()(Point a, Point b) {
        if (a.dist == b.dist) {
            if (a.x == b.x) {
                return a.y < b.y;
            }
            return a.x < b.x;
        }
        return a.dist < b.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        priority_queue<Point, vector<Point>, comp> stores;

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            stores.push(Point(x, y, sqrt(x * x + y * y)));
            if (stores.size() > k)
                stores.pop();
        }

        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            stores.push(Point(x, y, sqrt(x * x + y * y)));
            stores.pop();
            cout << stores.top().x << ' ' << stores.top().y << '\n';
        }
    }
}