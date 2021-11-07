//
// W9_1: Geometric_series
// Created by 조재현 on 2021/10/29.
//

#include <iostream>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int t;
ll X, N, M;

pll geoSeries(ll x, ll n) {
    if (n == 1) return {x % M, x % M};

    pll half = geoSeries(x, n / 2);
    // X^(N/2) mod M
    ll exp = half.first;
    // X^1+X^2+...+X^(N/2) mod M
    ll sum = half.second;

    if (n % 2 == 0) return {(exp * exp) % M, ((1 + exp) * sum) % M};
    else return {(x * exp * exp) % M, (x + x * (1 + exp) * sum) % M};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> X >> N >> M;
        // {X^N mod M, X^1+X^2+...+X^N mod M}
        pll answer = geoSeries(X, N);
        cout << answer.second << '\n';
    }
    return 0;
}