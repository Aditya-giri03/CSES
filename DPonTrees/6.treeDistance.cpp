// probmlem : https://codeforces.com/contest/161/problem/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long;

vector<vector<int>> dist; // dist[u][x] - tells count of node at dist x from node u's subtree
vector<vector<int>> res;  // dist[u][x] - tells count of node at dist x from node u total
vector<vector<int>> tree;

void findDist(int src, int par, int &k)
{

    dist[src][0] = 1;

    for (int child : tree[src])
    {
        if (child == par)
            continue;
        findDist(child, src, k);
        for (int d = 1; d <= k; d++)
        {
            dist[src][d] += dist[child][d - 1];
        }
    }
}

void solve(int src, int par, int &k)
{
    // cout << "NODe : " << src << endl;

    for (int d = k; d >= k - 2; d--)
    {
        res[src][d] = dist[src][d];
    }

    if (par != 0) // not root node
    {
        for (int d = k; d >= k - 2; d--)
        {
            res[src][d] += res[par][d - 1] - dist[src][d - 2];
        }
    }

    for (int child : tree[src])
    {
        if (child == par)
            continue;
        solve(child, src, k);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    tree.resize(n + 1);
    dist.resize(n + 1, vector<int>(k + 1, 0));
    res.resize(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    findDist(1, 1, k);
    cout << "FOUND DIST" << endl;
    cout << dist[1][k] << endl;
    cout << dist[2][k] << endl;
    cout << dist[3][k] << endl;
    solve(1, 0, k);
    cout << "FOUND ANS" << endl;
    cout << res[1][k] << endl;
    cout << res[2][k] << endl;
    cout << res[3][k] << endl;
    cout << res[4][k] << endl;
    cout << res[5][k] << endl;

    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += res[i][k];
    }

    cout << (cnt / 2);

    return 0;
}