// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// vector<vector<int>> tree;
// vector<ll> subtreeAns;
// vector<int> subtreeSize;
// vector<ll> ans;

// void preprocessing(int src, int par)
// {
//     int nodeCnt = 1;
//     ll subAns = 0;

//     for (int child : tree[src])
//     {
//         if (child == par)
//             continue;
//         preprocessing(child, src);
//         nodeCnt += subtreeSize[child];
//         subAns += subtreeAns[child] + subtreeSize[child];
//     }
//     subtreeAns[src] = subAns;
//     subtreeSize[src] = nodeCnt;
// }
// void solve(int src, int par, ll partialAns, int &n)
// {
//     ans[src] = subtreeAns[src] + partialAns + (n - subtreeSize[src]);

//     for (int child : tree[src])
//     {
//         if (child == par)
//             continue;
//         ll chilParAns = ans[src] - subtreeAns[child] - subtreeSize[child];
//         solve(child, src, chilParAns, n);
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     tree.resize(n + 1);
//     subtreeAns.resize(n + 1);
//     subtreeSize.resize(n + 1);
//     ans.resize(n + 1);

//     for (int i = 0; i < n - 1; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         tree[u].push_back(v);
//         tree[v].push_back(u);
//     }
//     preprocessing(1, 1);
//     solve(1, 1, 0, n);

//     for (int i = 1; i <= n; i++)
//     {
//         cout << ans[i] << " ";
//     }
//     return 0;
// }

// Better Method
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> tree;
vector<int> subtreeSize;
vector<ll> ans;

void preprocessing(int src, int par)
{
    int nodeCnt = 1;

    for (int child : tree[src])
    {
        if (child == par)
            continue;
        preprocessing(child, src);
        nodeCnt += subtreeSize[child];
        ans[1] += subtreeSize[child]; // calculating ans for node 1(root)
    }
    subtreeSize[src] = nodeCnt;
}

void solve(int src, int par, int &n)
{
    for (int child : tree[src])
    {
        if (child == par)
            continue;
        ans[child] = ans[src] - subtreeSize[child] + (n - subtreeSize[child]);
        solve(child, src, n);
    }
}

int main()
{
    int n;
    cin >> n;
    tree.resize(n + 1);
    subtreeSize.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    preprocessing(1, 1);

    solve(1, 1, n);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}