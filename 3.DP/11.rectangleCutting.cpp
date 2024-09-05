#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;



int main() {
    int a, b; cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }

            // vertical cut
            for (int v = 1; v < j; v++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][v] + dp[i][j - v]);
            }
            // horizontal cut
            for (int h = 1; h < i; h++) {
                dp[i][j] = min(dp[i][j], 1 + dp[h][j] + dp[i - h][j]);
            }
        }
    }
    cout << dp[a][b] << endl;
}