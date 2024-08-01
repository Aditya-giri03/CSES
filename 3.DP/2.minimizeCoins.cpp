#include <bits/stdc++.h>
using namespace std;

int solve(int target, vector<int>& coins, vector<int>& dp) {
    if (target == 0)
        return 0;

    if (dp[target] != -1)
        return dp[target];

    int ways = 1e9;
    for (int val : coins)
    {
        if (target - val >= 0)
        {
            ways = min(ways, solve(target - val, coins, dp));
        }
    }
    return dp[target] = ways + 1;
}
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        coins.push_back(val);
    }
    vector<int> dp(x + 1, -1);
    int res = solve(x, coins, dp);

    cout << ((res >= 1e9) ? -1 : res);

    return 0;
}