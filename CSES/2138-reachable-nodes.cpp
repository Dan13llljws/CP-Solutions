#include <bits/stdc++.h>
using namespace std;
const int MM = 50005;
bitset<MM> g[MM];
vector<int> adj[MM];
int ans[MM], vis[MM];
void dfs(int src){
    if (vis[src]) return;
    vis[src] = g[src][src] = 1;
    for (int v : adj[src])
        dfs(v), g[src] |= g[v];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        g[u][v] = 1;
    }
    for (int i = 0; i < n; i++) dfs(i), cout << g[i].count() << ' ';
    cout << '\n';
}


