#include <bits/stdc++.h>
using namespace std;
int N;
int dp[200001][2];

void solve(int node, int par, vector<vector<int>> &tree)
{
    dp[node][0] = 0;
    dp[node][1] = 0;

    bool leaf = 1;

    for (auto child : tree[node])
    {
        if (child == par)
            continue;
        leaf = 0;
        solve(child, node, tree); // getting ans of all child subtrees
    }

    if (leaf)
        return;

    vector<int> preffix;
    vector<int> suffix;

    for (auto child : tree[node])
    {
        if (child != par)
        {
            preffix.push_back(max(dp[child][0], dp[child][1]));
            suffix.push_back(max(dp[child][0], dp[child][1]));
        }
    }

    for (int i = 1; i < preffix.size(); i++)
    {
        preffix[i] += preffix[i - 1];
    }
    for (int i = suffix.size() - 2; i >= 0; i--)
    {
        suffix[i] += suffix[i + 1];
    }

    dp[node][0] = suffix[0]; // not taking edge at curr node

    int childNo = 0;
    for (auto child : tree[node])
    {
        if (child == par)
            continue;

        int leftChildrenAns = (childNo == 0) ? 0 : preffix[childNo - 1];
        int rightChildrenAns = (childNo == suffix.size() - 1) ? 0 : suffix[childNo + 1];

        dp[node][1] = max(dp[node][1], 1 + leftChildrenAns + dp[child][0] + rightChildrenAns);
        childNo++;
    }
}

int main()
{
    int n;
    cin >> n;
    N = n;
    vector<vector<int>> tree(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    solve(1, 0, tree);

    cout << max(dp[1][0], dp[1][1]);

    return 0;
}