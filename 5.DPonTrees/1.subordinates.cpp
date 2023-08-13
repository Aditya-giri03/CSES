#include <bits/stdc++.h>
using namespace std;
int N;

int dfs(int node, vector<vector<int>> &gp, vector<int> &dp)
{
    int sub = 0;

    for (auto v : gp[node])
    {
        sub += dfs(v, gp, dp);
    }

    dp[node] = sub;
    return sub + 1;
}
int main()
{
    int n;
    cin >> n;
    N = n;
    vector<vector<int>> gp(n);
    for (int i = 1; i < n; i++)
    {
        int boss;
        cin >> boss;
        boss--;
        gp[boss].push_back(i);
    }

    vector<int> dp(N, 0);
    dfs(0, gp, dp);

    for (int val : dp)
    {
        cout << val << " ";
    }
    return 0;
}