
#include <bits/stdc++.h>
using namespace std;
vector<int> dp(200001, 0);
int res = 0;

int solve(int node, int par, unordered_map<int, vector<int>> &gp)
{
    int maxHt = 0, secMaxHt = 0;
    for (int v : gp[node])
    {
        if (v == par)
            continue;
        int ht = solve(v, node, gp);

        if (ht > maxHt)
        {
            secMaxHt = maxHt;
            maxHt = ht;
        }
        else if (ht > secMaxHt)
            secMaxHt = ht;
    }

    res = max(res, maxHt + secMaxHt + 1);
    // cout << "node" << node << " : " << res << " maxHt : " << maxHt + 1 << endl;

    return maxHt + 1;
}
int main()
{
    int n;
    cin >> n;

    unordered_map<int, vector<int>> gp(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }

    solve(1, -1, gp);
    cout << res - 1 << endl; // want num of edges so -1

    return 0;
}