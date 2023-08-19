#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int solve(int target, vector<int> &coins, vector<int> &dp)
{
    if (target == 0)
        return 1;
    if (dp[target] != -1)
        return dp[target];

    int ways = 0;
    for (int &val : coins)
    {
        if (target - val >= 0)
        {
            ways = (ways + solve(target - val, coins, dp)) % mod;
        }
    }
    return dp[target] = ways % mod;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &i : coins)
    {
        cin >> i;
    }
    vector<int> dp(x + 1, -1);
    cout << solve(x, coins, dp);

    return 0;
}