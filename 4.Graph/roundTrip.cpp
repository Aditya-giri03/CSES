#include<bits/stdc++.h>
using namespace std;


bool dfs(int n, int p, vector<vector<int>>& g, vector<bool>& vis, vector<int>& par, pair<int, int>& cycleNodes) {

    vis[n] = true;
    for (int adj : g[n]) {
        if (adj == p) continue;
        if (vis[adj]) {
            cycleNodes.first = adj;
            cycleNodes.second = n;
            return true;
        }
        par[adj] = n;
        if (dfs(adj, n, g, vis, par, cycleNodes)) return true;
    }
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1);
    pair<int, int> cycleNodes;

    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, g, vis, parent, cycleNodes)) {
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    vector<int> path;
    int s = cycleNodes.first, e = cycleNodes.second;
    path.push_back(s);
    while (e != s) {
        path.push_back(e);
        e = parent[e];
    }
    path.push_back(s);

    cout << path.size() << endl;
    for (int p : path) cout << p << " ";

    return 0;
}