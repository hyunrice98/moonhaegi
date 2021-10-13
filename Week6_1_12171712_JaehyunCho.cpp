//
// W5_1: Signal_Interpretation
// Created by 조재현 on 2021/10/08.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct customerInfo {
    int useTime;
    int cost;
};

struct counterInfo {
    int endTime;
    int number;
};

struct compare {
    bool operator()(counterInfo a, counterInfo b) {
        if (a.endTime == b.endTime) {
            return a.number > b.number;
        }
        return a.endTime > b.endTime;
    }
};

customerInfo customer[100001];
priority_queue<counterInfo, vector<counterInfo>, compare> counterPQ;

int costAnswer[20001];
int n, m, timeAnswer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> customer[i].useTime >> customer[i].cost;
    }

    for (int i = 0; i < n; i++) {
        counterPQ.push({customer[i].useTime, i});
        costAnswer[i] += customer[i].cost;
        timeAnswer = max(timeAnswer, customer[i].useTime);
    }
    for (int i = n; i < m; i++) {
        counterInfo counterTemp = counterPQ.top();
        counterPQ.pop();
        counterTemp.endTime += customer[i].useTime;
        costAnswer[counterTemp.number] += customer[i].cost;
        timeAnswer = max(timeAnswer, counterTemp.endTime);
        counterPQ.push(counterTemp);
    }

    cout << timeAnswer << '\n';
    for (int i = 0; i < n; i++) {
        cout << costAnswer[i] << '\n';
    }

    return 0;
}