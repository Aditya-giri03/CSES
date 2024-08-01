#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int& i : coins)
    {
        cin >> i;
    }
    // vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    vector<int> prev(x + 1, 0), curr(x + 1, 0);
    prev[0] = 1;
    curr[0] = 1;
    // for (int i = 0; i <= n; i++)
    //     dp[i][0] = 1;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int target = 1; target <= x; target++)
        {
            int ways = 0;
            // not take/skip
            ways = (ways + prev[target]) % mod;
            // take
            if (target - coins[idx] >= 0)
                ways = (ways + curr[target - coins[idx]]) % mod;

            curr[target] = ways;
        }
        prev = curr;
    }
    cout << prev[x] << endl;

    return 0;
}