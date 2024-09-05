#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int f(int i, int j, string& m, string& n, vector<vector<int>>& dp) {
    if (i == -1 && j == -1) return 0;
    if (i == -1) return j + 1;
    if (j == -1) return i + 1;
    if (dp[i][j] != -1) return dp[i][j];
    if (m[i] == n[j]) return dp[i][j] = f(i - 1, j - 1, m, n, dp);
    return dp[i][j] = 1 + min({ f(i - 1, j, m, n, dp), f(i, j - 1, m, n, dp),f(i - 1, j - 1, m, n, dp) });
}

int main() {
    string m, n; cin >> m >> n;
    vector<vector<int>> dp(m.size(), vector<int>(n.size(), -1));
    cout << f(m.size() - 1, n.size() - 1, m, n, dp) << endl;
}