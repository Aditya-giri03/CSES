#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long INF = 1e16;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v,w });
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));

    priority_queue < pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>> > pq;
    // 0 -> not used coupon | 1 -> coupon used
    pq.push({ 0,{1,0} }); // dist, node, isCouponUsed

    while (!pq.empty()) {
        auto it = pq.top(); pq.pop();
        ll d = it.first, node = it.second.first, isCouponUsed = it.second.second;

        for (auto adj : g[node]) {
            ll v = adj.first, wt = adj.second;
            if (!isCouponUsed) {
                // still not using coupon
                if (d + wt < dist[v][0]) {
                    dist[v][0] = d + wt;
                    pq.push({ dist[v][0] ,{v,0} });
                }
                // using coupon for this edge/flight
                if (d + (wt / 2) < dist[v][1]) {
                    dist[v][1] = d + (wt / 2);
                    pq.push({ dist[v][1],{v,1} });
                }
            }
            else {
                if (d + wt < dist[v][1]) {
                    dist[v][1] = d + wt;
                    pq.push({ dist[v][1] ,{v,1} });
                }
            }
        }
    }

    cout << dist[n][1] << endl;

    return 0;
}