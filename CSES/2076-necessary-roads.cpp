#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> in(n), low(n);
    int t = 0;
    vector<pair<int,int>> bridges;
    auto dfs = [&](auto self, int src, int par) -> void{
        low[src] = in[src] = ++t;
        for (int v : adj[src]){
            if (v == par) continue;
            if (in[v]) low[src] = min(low[src], in[v]);
            else self(self, v, src), low[src] = min(low[src], low[v]);
            if (low[v] > in[src]) bridges.push_back({src + 1, v + 1});
        }
    };
    dfs(dfs, 1, 1);
    cout << bridges.size() << '\n';
    for (auto [u, v] : bridges) cout << u << ' ' << v << '\n';
}
