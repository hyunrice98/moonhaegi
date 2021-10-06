//
// W5_2: Town_Redevelopment
// Created by 조재현 on 2021/10/01.
// boj: 2110

#include <iostream>

using namespace std;

int n, m, answer;
int houseArr[1000001];

bool check(int length) {
    int house = 1;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (house <= houseArr[i]) {
            house = houseArr[i] + length;
            count++;
        }
        if (count == m) {
            return true;
        }
    }
    return false;
}

int solution(int left, int right) {
    int mid;
    if (left == right) return left;
    if (left + 1 == right) {
        if (check(right) == true)
            return right;
        else
            return left;
    }
    mid = (left + right) / 2;
    if (check(mid))
        return solution(mid, right);
    else
        return solution(left, mid - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> houseArr[i];
    }
    answer = solution(1, houseArr[n] - 1);
    cout << answer;

    return 0;
}