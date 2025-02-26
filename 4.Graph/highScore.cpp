#include<bits/stdc++.h>
using namespace std;
const long INF = 1e14;

bool checkNodeNReachable(int& u, int& n, vector<vector<int>>& g) {
    // BFS
    queue<int> q;
    vector<bool> vis(n + 1, false);
    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (node == n) return true;
        for (auto adj : g[node]) {
            if (!vis[adj]) {
                vis[adj] = true;
                q.push(adj);
            }
        }
    }
    // End of BFS
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> tunnels(m);
    vector <vector<int> > g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, x; cin >> a >> b >> x;
        tunnels[i] = { a,b,x };
        g[a].push_back(b);
    }
    vector<long> dist(n + 1, -1 * INF);
    dist[1] = 0;


    // bellman ford algo [inverse as need to find max points]
    for (int itr = 0; itr < n - 1; itr++) {
        for (auto e : tunnels) {
            int u = e[0], v = e[1], wt = e[2];
            if (dist[u] != -1 * INF && dist[u] + wt > dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (auto e : tunnels) {
        int u = e[0], v = e[1], wt = e[2];
        if (dist[u] != -1 * INF && dist[u] + wt > dist[v]) {
            // need to check if from u -> can reach node 'n' or not
            // there is a positive cycle in  graph but can it improve score of node `n` or it is in other branch of g i.e. can't improve score of n
            if (checkNodeNReachable(u, n, g)) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << dist[n] << endl;
    return 0;
}