#include <iostream>
#include <algorithm>

using namespace std;

struct Print {
    void NO_INTERSECT() {
        cout << 1 << '\n';
    }
    void ONE_INTERSECT() {
        cout << 2 << '\n';
    }
    void PARTIAL_OVERLAP() {
        cout << 3 << '\n';
    }
    void CONTAIN() {
        cout << 4 << '\n';
    }
};

int main() {
    Print p;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int t, X, Y;

    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (x3 > x4) {
            swap(x3, x4);
            swap(y3, y4);
        }
        // 두 선분이 y축과 평행
        if (x1 == x2 && x3 == x4) {
            if (x1 != x3) p.NO_INTERSECT();
            else if (x1 == x3) {
                if (y1 > y2) swap(y1, y2);
                if (y3 > y4) swap(y3, y4);
                if (y1 > y4 || y3 > y2) p.NO_INTERSECT();
                if (y1 == y4 || y3 == y2) p.ONE_INTERSECT();
                if ((y1 <= y3 && y4 <= y2) || (y3 <= y1 && y2 <= y4)) p.CONTAIN();
                if ((y1 > y3 && y1 < y4 && y4 < y2) || (y3 > y1 && y3 < y2 && y2 < y4)) p.PARTIAL_OVERLAP();
            }
        }
        // L1은 y축과 평행, L2는 x축과 평행
        else if (x1 == x2 && y3 == y4) {
            X = x1;
            Y = y3;
            if ((min(y1, y2) <= Y && Y <= max(y1, y2)) && (x3 <= X && X <= y4)) p.ONE_INTERSECT();
            else p.NO_INTERSECT();
        }
        // L1은 x축과 평행, L2는 y축과 평행
        else if (y1 == y2 && x3 == x4) {
            X = x3;
            Y = y1;
            if ((x1 <= X && X <= x2) && (min(y3, y4) <= Y && Y <= max(y3, y4))) p.ONE_INTERSECT();
            else p.NO_INTERSECT();
        }
        // 두 선분이 X축과 평행
        else if (y1 == y2 && y3 == y4) {
            if (y1 != y3) p.NO_INTERSECT();
            else if (y1 == y3) {
                if (x1 > x4 || x3 > x2) p.NO_INTERSECT();
                if (x1 == x4 || x3 == x2) p.ONE_INTERSECT();
                if ((x1 <= x3 && x4 <= x2) || (x3 <= x1 && x2 <= x4)) p.CONTAIN();
                if ((x1 > x3 && x1 < x4 && x4 < x2) || (x3 > x1 && x3 < x2 && x2 < x4)) p.PARTIAL_OVERLAP();
            }
        }
    }
}