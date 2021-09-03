//
// W1_2: Block_Tower
// Created by jaehyun on 2021/09/03.
//

#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
stack<int> minS;
stack<int> maxS;

void clearStacks() {
    while (!s.empty()) s.pop();
    while (!minS.empty()) minS.pop();
    while (!maxS.empty()) maxS.pop();
}

void putBlock(int x) {
    s.push(x);

    if (minS.empty() || x <= minS.top()) minS.push(x);
    if (maxS.empty() || x >= maxS.top()) maxS.push(x);

    cout << minS.top() << ' ' << maxS.top() << '\n';
}

void deleteBlock() {
    if (s.empty()) return;

    if (minS.top() == s.top()) minS.pop();
    if (maxS.top() == s.top()) maxS.pop();

    s.pop();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        clearStacks();
        int n;
        cin >> n;
        while (n--) {
            int oper;
            cin >> oper;
            if (oper == 1) {
                int x;
                cin >> x;
                putBlock(x);
            }
            if (oper == 2) {
                deleteBlock();
            }
        }
    }

    return 0;
}