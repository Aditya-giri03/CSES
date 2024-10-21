#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> status;

    for (int i = 0; i < n; i++)
    {
        int enter, exit;
        cin >> enter >> exit;
        status.push_back({ enter, 1 });
        status.push_back({ exit, -1 });
    }

    sort(status.begin(), status.end());
    int maxCust = 0;

    int cnt = 0;
    for (int i = 0; i < status.size(); i++)
    {
        cnt += status[i].second;
        maxCust = max(maxCust, cnt);
    }

    cout << maxCust;

    return 0;
}
/*
3
5 8
2 4
3 9

2,1 3,1 4,-1 5,1 8,-1 9,-1
*/