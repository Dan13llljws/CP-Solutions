#include <bits/stdc++.h>
using namespace std;
const int MM = 50005;
bitset<MM> g[MM];
vector<int> ord, adj[MM], rev[MM], adj_scc[MM];
int cmp, ans[MM], vis[MM], p[MM];
void dfs(int src){
    vis[src] = 1;
    for (int v : adj[src])
        if (!vis[v]) dfs(v);
    ord.push_back(src);
}
void dfs1(int src){
    vis[src] = 1, p[src] = cmp;
    for (int v : rev[src])
        if (!vis[v]) dfs1(v);
}
void dfs2(int src){
    if (vis[src]) return;
    vis[src] = 1;
    for (int v : adj_scc[src])
        dfs2(v), g[src] |= g[v];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i);
    memset(vis, 0, sizeof vis);
    reverse(ord.begin(), ord.end());
    for (int v : ord)
        if (!vis[v]) dfs1(v), cmp++;
    for (int i = 0; i < n; i++)
        for (int v : adj[i])
            if (p[i] != p[v]) adj_scc[p[i]].push_back(p[v]), g[p[i]][p[v]] = 1;
    for (int i = 0; i < cmp; i++) g[i][i] = 1;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < cmp; i++)
        dfs2(i);
    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << (g[p[a]][p[b]] ? "YES" : "NO") << '\n';
    }
}
