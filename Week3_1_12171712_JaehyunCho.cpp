//
// W3_1: Directory
// Created by 조재현 on 2021/09/17.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> graph;
int length[50001];
int ans[50001];

void dfs(int n) {
    for (int c: graph[n]) {
        ans[c] = ans[n] + length[c] + 1;
        dfs(c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        graph.clear();
        graph.resize(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
        }
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            length[i] = s.size();
        }

        ans[1] = 4;
        dfs(1);

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << '\n';
        }
    }
}
