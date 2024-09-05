#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;


ll f(int val, ll target, int& n, vector<vector<ll>>& dp) {
    if (target == 0) return 1;
    if (val > n) return 0;
    if (dp[val][target] != -1) return dp[val][target];

    ll nTake = f(val + 1, target, n, dp) % mod;
    ll take = 0;
    if (val <= target) {
        take = f(val + 1, target - val, n, dp) % mod;
    }
    return dp[val][target] = (take + nTake) % mod;
}


int main() {
    int n; cin >> n;
    ll total = n * (n + 1) / 2;
    if (total % 2) {
        cout << 0 << endl; return 0;
    }
    ll target = total / 2;
    vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, -1));

    cout << f(1, target, n, dp) / 2 << endl;
}