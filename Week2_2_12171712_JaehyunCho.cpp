//
// W2_2: Securing_Resources
// Created by 조재현 on 2021/09/10.
//

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int t, n, answer, flag;
int resourceA[10001];
int resourceB[10001];
pair<int, int> resourceSum[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> resourceA[i] >> resourceB[i];
            resourceSum[i] = make_pair(resourceA[i] + resourceB[i], i);
        }
        sort(resourceSum, resourceSum + n);
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