#include <bits/stdc++.h>
using namespace std;
# define ll long long
const int mod = 1000000007;

// ll f(int i, int j, vector<int>& val, vector<vector<ll>>& dp) {

//     if (i == j) return val[i];
//     if (dp[i][j] != -1) return dp[i][j];

//     ll a = val[i] - f(i + 1, j, val, dp);
//     ll b = val[j] - f(i, j - 1, val, dp);

//     return dp[i][j] = max(a, b);
// }

int main() {
    int n; cin >> n;
    vector<int> val(n);
    ll total = 0;
    for (int& i : val) {
        cin >> i;
        total += i;
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) dp[i][j] = val[i];
            else {
                dp[i][j] = max(val[i] - dp[i + 1][j], val[j] - dp[i][j - 1]);
            }
        }
    }

    cout << (total + dp[0][n - 1]) / 2 << endl;
}