#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main() {
    int T; cin >> T;
    vector<vector<int>> dp(1e6 + 1, vector<int>(2, 0));
    // base case
    dp[0][0] = 1; dp[0][1] = 1;

    for (int i = 1; i < 1e6 + 1; i++) {
        dp[i][0] = (1LL * dp[i - 1][0] + dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (1LL * dp[i - 1][1] + dp[i - 1][1] + dp[i - 1][1] + dp[i - 1][1] + dp[i - 1][0]) % mod;
    }

    while (T--) {
        int n; cin >> n;
        cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << endl;
    }
    return 0;
}