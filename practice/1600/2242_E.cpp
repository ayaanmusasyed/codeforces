#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

void dfs(int node, int parent,
         const vector<vector<int>>& adj,
         vector<int>& sz,
         vector<int>& parents) {
         
    parents[node] = parent;
    sz[node] = 1;

    for (int neighbour : adj[node]) {
        if (neighbour == parent) continue;

        dfs(neighbour, node, adj, sz, parents);
        sz[node] += sz[neighbour];
    }
}

void solve() { 
    int n; cin >> n;
    vector<int> vertex_cost(n + 1); 

    for (int i = 1; i < n + 1; i++) { 
        cin >> vertex_cost[i];
    }

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> sz(n + 1);
    vector<int> parent(n + 1);

    int root = 1;  // Any vertex works
    dfs(root, 0, adj, sz, parent);

    ll res = 0; 
    
    for (int i = 1; i <= n; ++i) {
        ll sum = 0;
        ll pairs = 0;
        ll triples = 0;

        for (int p : adj[i]) {
            ll component_size;

            if (p == parent[i]) {
                component_size = n - sz[i];
            } else {
                component_size = sz[p];
            }

            triples += component_size * pairs;
            pairs += component_size * sum;
            sum += component_size;
        }

        ll root_value = sqrtl(vertex_cost[i]);

        if (root_value * root_value == vertex_cost[i]) {
            res += pairs + triples;
        }
    }
    cout << res << "\n";
}

int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    int t; cin >> t;
     
    while (t--) { 
        solve();
    }

    return 0; 
}