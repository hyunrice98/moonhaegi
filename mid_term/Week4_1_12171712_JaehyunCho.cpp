//
// W4_1: Esports_Games
// Created by 조재현 on 2021/09/24.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int a2 = a;
        int b2 = b;

        int gcd = abs(a - b);
        // up
        int upCase = 0;
        while (true) {
            if (a % gcd == 0 && b % gcd == 0) break;
            a++;
            b++;
            upCase += x;
        }

        // down
        int downCase = 0;
        while (true) {
            if (a2 == 0 || b2 == 0) {
                downCase = 2100000000;
                break;
            }
            if (a2 % gcd == 0 && b2 % gcd == 0) break;
            a2--;
            b2--;
            downCase += y;
        }

        int result = (upCase < downCase) ? upCase : downCase;
        cout << gcd << ' ' << result << '\n';
    }

    return 0;
}