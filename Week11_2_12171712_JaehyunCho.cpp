//
// W11_2: Cutting_Paper
// Created by 조재현 on 2021/11/12.
//

#include <iostream>
#include <cstring>

using namespace std;

char paper[1025][1025];
int t, n;

struct paperInfo {
    int redNumber;
    int redSize;
    int blueNumber;
    int blueSize;

    paperInfo() {
        redNumber = redSize = blueNumber = blueSize = 0;
    }
};

void clear() {
    for (int i = 0; i < 1025; i++) {
        memset(paper[i], '\0', sizeof(paper[i]));
    }
}

paperInfo solution(int x, int y, int size) {
    paperInfo result;
    if (size == 1) {
        if (paper[x][y] == 'R') result.redNumber = result.redSize = 1;
        else result.blueNumber = result.blueSize = 1;
        return result;
    }

    paperInfo status[4];
    status[0] = solution(x, y, size / 2);
    status[1] = solution(x + size / 2, y, size / 2);
    status[2] = solution(x, y + size / 2, size / 2);
    status[3] = solution(x + size / 2, y + size / 2, size / 2);

    for (paperInfo s: status) {
        result.redNumber += s.redNumber;
        result.redSize += s.redSize;
        result.blueNumber += s.blueNumber;
        result.blueSize += s.blueSize;
    }

    if (result.redNumber == 0)
        result.blueNumber = 1;
    if (result.blueNumber == 0)
        result.redNumber = 1;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> paper[i][j];
            }
        }
        paperInfo answer = solution(0, 0, n);
        cout << answer.redNumber << ' ' << answer.redSize << ' ' << answer.blueNumber << ' ' << answer.blueSize << '\n';
        clear();
    }

    return 0;
}