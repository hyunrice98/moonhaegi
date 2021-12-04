//
// W12_2: Room_Hunting
// Created by 조재현 on 2021/11/19.
// boj:1946
//

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int t, n;
pair<int, int> rooms[500001];

void clear() {
    for (auto& room : rooms) {
        room = {0, 0};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        clear();
        for (int i = 0; i < n; i++) {
            cin >> rooms[i].first >> rooms[i].second;
        }
        sort(rooms, rooms + n, greater<>());
        int answer = 1;
        int dist = rooms[0].second;
        for (int i = 1; i < n; i++) {
            if (rooms[i].second < dist) {
                answer++;
                dist = rooms[i].second;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}