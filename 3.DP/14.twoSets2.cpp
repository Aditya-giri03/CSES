#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;

// (a^b)% MOD
int binExpo(int a, int b, int MOD) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * 1LL * a) % MOD;
        }
        a = (a * 1LL * a) % MOD;
        b >>= 1;
    }
    return ans;
}
// Modular Multiplicative Inverse - MMI
int MMI(int A, int M) {
    return binExpo(A, M - 2, M);
}

// ll f(int val, ll target, int& n, vector<vector<ll>>& dp) {
//     if (target == 0) return 1;
//     if (val > n) return 0;
//     if (dp[val][target] != -1) return dp[val][target];

//     ll nTake = f(val + 1, target, n, dp) % mod;
//     ll take = 0;
//     if (val <= target) {
//         take = f(val + 1, target - val, n, dp) % mod;
//     }
//     return dp[val][target] = (take + nTake) % mod;
// }


// int main() {
//     int n; cin >> n;
//     ll total = n * (n + 1) / 2;
//     if (total % 2) {
//         cout << 0 << endl; return 0;
//     }
//     ll target = total / 2;
//     vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, -1));

//     cout << (f(1, target, n, dp) * MMI(2, mod)) % mod << endl;
// }


// === Approach 2: 1D dp for checking how many subset can make a paerticular sum ===

int main() {
    int n; cin >> n;
    int total = n * (n + 1) / 2;
    if (total % 2) {
        cout << 0 << endl; return 0;
    }
    int target = total / 2;
    vector<ll> dp(target + 1, 0);
    dp[0] = 1; // no of subsets that make up sum = 0

    for (int val = 1; val <= n; val++) {
        for (int subsetSum = target; subsetSum >= val; subsetSum--) {
            dp[subsetSum] = (dp[subsetSum] + dp[subsetSum - val]) % mod;
        }
    }
    cout << (dp[target] * MMI(2, mod)) % mod << endl;
}