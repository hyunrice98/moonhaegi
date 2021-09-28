//
// W3_2: Good_Neighbour
// Created by 조재현 on 2021/09/17.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, answer;

struct RoadInfo {
    int neighbour;
    int distance;

    RoadInfo(int neighbour, int distance) {
        this->neighbour = neighbour;
        this->distance = distance;
    }
};

vector<vector<RoadInfo>> house;
bool visitedHouse[2001];

int treeSearch(int u) {
    int maxDistance = 0;
    int secondMaxDistance = 0;
    int tempDistance;

    visitedHouse[u] = true;
    for (int i = 0; i < house[u].size(); i++) {
        if (!visitedHouse[house[u][i].neighbour]) {
            tempDistance = treeSearch(house[u][i].neighbour) + house[u][i].distance;
            if (tempDistance > maxDistance) {
                swap(tempDistance, maxDistance);
            }
            if (tempDistance > secondMaxDistance) {
                swap(tempDistance, secondMaxDistance);
            }
        }
    }
    answer = max(answer, maxDistance + secondMaxDistance);
    return maxDistance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;

        house.clear();
        house.resize(n + 1);
        memset(visitedHouse, false, sizeof(visitedHouse));

        for (int i = 1; i <= n - 1; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            house[u].push_back(RoadInfo(v, d));
            house[v].push_back(RoadInfo(u, d));
        }
        answer = 0;
        treeSearch(1);
        cout << answer << '\n';
    }

    return 0;
}