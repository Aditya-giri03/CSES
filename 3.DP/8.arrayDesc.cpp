#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;


int f(int idx, int prev, vector<int>& nums, int& m, vector<vector<int>>& dp) {

    if (idx == nums.size()) return 1;
    if (dp[idx][prev] != -1) return dp[idx][prev];
    long ways = 0;

    if (nums[idx] == 0) {
        if (prev - 1 > 0) ways = (ways + f(idx + 1, prev - 1, nums, m, dp)) % mod;
        ways += f(idx + 1, prev, nums, m, dp);
        if (prev + 1 <= m) ways = (ways + f(idx + 1, prev + 1, nums, m, dp)) % mod;
    }
    else {
        if (abs(nums[idx] - prev) > 1) ways = 0;
        else ways = (ways + f(idx + 1, nums[idx], nums, m, dp)) % mod;
    }
    return dp[idx][prev] = (int)ways % mod;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int& i : nums) {
        cin >> i;
    }
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    int res = 0;
    if (nums[0] == 0) {
        for (int i = 1; i <= m; i++) {
            res = (res + f(1, i, nums, m, dp)) % mod;
        }
    }
    else {
        res = f(1, nums[0], nums, m, dp);
    }
    cout << res << endl;

    return 0;
}