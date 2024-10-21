#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>>& g, vector<bool>& vis) {
    vis[node] = true;

    for (int adj : g[node]) {
        if (!vis[adj]) {
            dfs(adj, g, vis);
        }
    }
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
    vector<int> unconnected_cities;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, g, vis);
            unconnected_cities.push_back(i);
        }
    }

    int sz = unconnected_cities.size();
    cout << sz - 1 << endl;
    for (int i = 0; i < sz - 1; i++) {
        cout << unconnected_cities[i] << " " << unconnected_cities[i + 1] << endl;
    }

    return 0;
}