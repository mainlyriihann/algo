#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using ll = long long;

struct Edge {
    ll u, v, w;
};

int main() {
    ll n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<ll> dist(n + 1, 0);
    vector<ll> parent(n + 1);

    for (int i = 1; i <= n; i++) parent[i] = i;

    int x = -1;

    // BELLMAN-FORD CORE FIX
    for (int i = 1; i <= n; i++) {
        x = -1;

        for (auto e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    int y = x;

    for (int i = 0; i < n; i++) {
        y = parent[y];
    }

    vector<int> cycle;
    int cur = y;

    while (true) {
        cycle.push_back(cur);
        cur = parent[cur];
        if (cur == y) {
            cycle.push_back(y);
            break;
        }
    }

    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (auto v : cycle) {
        cout << v << " ";
    }
}