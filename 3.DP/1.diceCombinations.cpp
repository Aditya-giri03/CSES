#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

// 1. Memoization
int solve(int target, vector<int> &dp)
{
    if (target == 0)
        return 1;

    if (dp[target] != -1)
        return dp[target];

    int ways = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (target - i >= 0)
        {
            ways = (ways + (solve(target - i, dp) % mod)) % mod;
        }
        else
            break;
    }
    return dp[target] = ways;
}

// 2. Tabulation
int solve2(int target)
{
    vector<int> dp(target + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
                dp[i] = (dp[i] + (dp[i - j]) % mod) % mod;
        }
    }
    return dp[target];
}

int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1, -1);
    // cout << solve(n, dp) << endl;
    cout << solve2(n) << endl;
    return 0;
}