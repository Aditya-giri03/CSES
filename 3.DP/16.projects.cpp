#include <bits/stdc++.h>
using namespace std;
# define ll long long
const int mod = 1000000007;

bool cmp(const int& n, const pair<int, pair<int, int>>& p) {
    return n < p.first;
}

ll maxAmt(int idx, vector<pair<int, pair<int, int>>>& projects, vector<ll>& dp) {
    if (idx >= projects.size()) return 0;
    if (dp[idx] != -1) return dp[idx];

    int endTime = projects[idx].second.first;
    int nextIdx = upper_bound(projects.begin() + idx, projects.end(), endTime, cmp) - projects.begin();
    // cout << "idx: " << idx << " endTime: " << endTime << " nextIdx: " << nextIdx << endl;

    ll take = projects[idx].second.second + maxAmt(nextIdx, projects, dp);
    ll nTake = maxAmt(idx + 1, projects, dp);

    return dp[idx] = max(take, nTake);
}

int main() {
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> projects(n); // start, end, reward
    for (int i = 0; i < n; i++) {
        int a, b, p; cin >> a >> b >> p;
        projects[i].first = a;
        projects[i].second.first = b;
        projects[i].second.second = p;
    }

    sort(projects.begin(), projects.end());
    vector<ll> dp(n, -1);
    cout << maxAmt(0, projects, dp) << endl;
    return 0;
}