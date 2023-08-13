#include <bits/stdc++.h>
using namespace std;
vector<int> depth(200001, 0);
vector<int> res(200001, 0);

void getDepth(int node, int par, vector<vector<int>> &tree)
{
    int d = 0;
    for (int v : tree[node])
    {
        if (v == par)
            continue;
        getDepth(v, node, tree);
        d = max(d, 1 + depth[v]);
    }

    depth[node] = d;
}

void solve(int node, int par, int parAns, vector<vector<int>> &tree)
{ // parAns - best ans of parent(above) nodes
    vector<int> prefixMax, suffixMax;
    for (int v : tree[node])
    {
        if (v == par)
            continue;
        prefixMax.push_back(depth[v]);
        suffixMax.push_back(depth[v]);
    }
    // building prefix, suffix
    for (int i = 1; i < (int)prefixMax.size(); i++)
        prefixMax[i] = max(prefixMax[i], prefixMax[i - 1]);

    for (int i = (int)suffixMax.size() - 2; i >= 0; i--)
        suffixMax[i] = max(suffixMax[i], suffixMax[i + 1]);

    // finding ans for each child
    int childNum = 0;
    for (int v : tree[node])
    {
        if (v == par)
            continue;
        int op1 = childNum == 0 ? INT_MIN : prefixMax[childNum - 1];
        int op2 = childNum == (int)suffixMax.size() - 1 ? INT_MIN : suffixMax[childNum + 1];

        int partialAns = max(parAns, max(op1, op2)) + 1;
        solve(v, node, partialAns, tree);
        childNum++;
    }
    res[node] = max(parAns, (!prefixMax.empty()) ? prefixMax[prefixMax.size() - 1] : -1) + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    getDepth(1, 1, tree);

    solve(1, 1, -1, tree);

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}