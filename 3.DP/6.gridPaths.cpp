#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int f(int i, int j, vector<vector<char>>& grid, int& n, vector<vector<int>>& dp) {

    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '*') return 0;
    if (i == n - 1 && j == n - 1) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    int down = f(i + 1, j, grid, n, dp);
    int right = f(i, j + 1, grid, n, dp);

    return dp[i][j] = (down + right) % mod;
}

int main() {
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << f(0, 0, grid, n, dp);
    return 0;
}