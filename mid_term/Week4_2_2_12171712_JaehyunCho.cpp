//
// W4_2: Two_Line_Segments
// Created by 조재현 on 2021/09/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        double a1, b1, a2, b2;
        double x, y;

        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (x3 > x4) {
            swap(x3, x4);
            swap(y3, y4);
        }

        if (x1 == x2 && x3 == x4) {
            if (x1 != x3) cout << 1 << '\n';
            else if (x1 == x3) {
                if (y1 > y2) swap(y1, y2);
                if (y3 > y4) swap(y3, y4);
                if (y1 > y4 || y3 > y2) cout << 1 << '\n';
                if (y1 == y4 || y3 == y2) cout << 2 << '\n';
                if ((y1 <= y3 && y4 <= y2) || (y3 <= y1 && y2 <= y4)) cout << 4 << '\n';
                if ((y1 > y3 && y1 < y4 && y4 < y2) || (y3 > y1 && y3 < y2 && y2 < y4)) cout << 3 << '\n';
            }
        } else if (x1 == x3) {
            if (y1 > y2) swap(y1, y2);
            if (y3 > y4) swap(y3, y4);
            if (y1 > y4 || y3 == y2) cout << 1 << '\n';
            if (y1 == y4 || y3 == y2) cout << 2 << '\n';
            if ((y1 <= y3 && y4 <= y2) || (y3 <= y1 && y2 <= y4)) cout << 4 << '\n';
            if ((y1 > y3 && y1 < y4 && y4 < y2) || (y3 > y1 && y3 < y2 && y2 < y4)) cout << 3 << '\n';
        } else if (x3 == x4) {
            a1 = (double) (y2 - y1) / (x2 - x1);
            b1 = y1 - a1 * x1;
            y = a1 * x3 + b1;
            if ((min(y1, y2) <= y && y <= max(y1, y2)) && (min(y3, y4) <= y <= max(y3, y4)) && (x1 <= x3 && x3 <= x2))
                cout << 2 << '\n';
            else cout << 1 << '\n';
        } else if (x1 == x2) {
            a2 = (double) (y4 - y3) / (x4 - x3);
            b2 = y3 - a2 * x3;
            y = a2 * x1 + b2;
            if ((min(y3, y4) <= y && y <= max(y3, y4)) && (min(y1, y2) <= y <= max(y1, y2)) && (x3 <= x1 && x1 <= x2))
                cout << 2 << '\n';
            else cout << 1 << '\n';
        } else {
            a1 = (double) (y2 - y1) / (x2 - x1);
            b1 = y1 - a1 * x1;
            a2 = (double) (y4 - y3) / (x4 - x3);
            b2 = y3 - a2 * x3;
            if (a1 == a2 && b1 == b2) {
                if (x1 > x4 && x3 > x2) cout << 1 << '\n';
                if (x1 == x4 || x3 == x2) cout << 2 << '\n';
                if ((x1 <= x3 && x4 <= x2) || (x3 <= x1 && x2 <= x4)) cout << 4 << '\n';
                if ((x1 > x3 && x1 < x4 && x4 < x2) || (x3 > x1 && x3 < x2 && x2 < x4)) cout << 3 << '\n';
            } else if (a1 == a2 && b1 != b2) cout << 1 << '\n';
            else {
                x = (double) (b2 - b1) / (a1 - a2);
                if ((x1 <= x && x <= x2) && (x3 <= x <= x4)) cout << 2 << '\n';
                else cout << 1 << '\n';
            }
        }
    }

    return 0;
}