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

// WAY_2: dfs double times
//#include <iostream>
//#include <vector>
//#include <utility>
//
//using namespace std;
//
//#define P pair<int, int>
//
//int t, n, u, v, d;
//vector<vector<P>> tree;
//bool visited[2001];
//int dist[2001];
//
//void dfs(int x) {
//    visited[x] = true;
//    for (P p: tree[x]) {
//        if (!visited[p.first]) {
//            dist[p.first] = dist[x] + p.second;
//            dfs(p.first);
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    cin >> t;
//    while (t--) {
//        cin >> n;
//        memset(visited, false, 2001);
//        memset(dist, 0, 2001);
//        tree.clear();
//        tree.resize(n + 1);
//        for (int i = 0; i < n - 1; i++) {
//            cin >> u >> v >> d;
//            tree[u].push_back(make_pair(v, d));
//            tree[v].push_back(make_pair(u, d));
//        }
//
//        dfs(1);
//        int big = -1, bigIdx = 1;
//        for (int i = 1; i <= n; i++) {
//            if (dist[i] > big) {
//                big = dist[i];
//                bigIdx = i;
//            }
//        }
//
//        memset(visited, false, 2001);
//        memset(dist, 0, 2001);
//
//        dfs(bigIdx);
//
//        sort(dist + 1, dist + n + 1);
//        cout << dist[n] << '\n';
//    }
//
//    return 0;
//}