//
// W2_2: Securing_Resources
// Created by 조재현 on 2021/09/10.
//

#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, answer, flag;
int resourceA[10001], resourceB[10001];
pair<int, int> resourceSum[10001];

void reset() {
    memset(resourceA, 0, sizeof(resourceA));
    memset(resourceB, 0, sizeof(resourceB));
    for (auto &i: resourceSum) {
        i = {0, 0};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        reset();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> resourceA[i] >> resourceB[i];
            resourceSum[i] = {resourceA[i] + resourceB[i], i};
        }
        sort(resourceSum, resourceSum + n, greater<>());
        answer = 0;
        flag = 1;

        for (int i = 0; i < n; i++) {
            if (flag == 1) {
                answer += resourceA[resourceSum[i].second];
                flag = 0;
            } else if (flag == 0) {
                answer -= resourceB[resourceSum[i].second];
                flag = 1;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}