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
    vector<int> cut_vertex(n);
    auto dfs = [&](auto self, int src, int par) -> void{
        low[src] = in[src] = ++t;
        int ch = 0;
        for (int v : adj[src]){
            if (v == par) continue;
            if (in[v]) low[src] = min(low[src], in[v]);
            else {
                self(self, v, src), low[src] = min(low[src], low[v]);
                if (par != -1 && low[v] >= in[src]) cut_vertex[src] = 1;
                ch++;
            }
        }
        if (par == -1 && ch > 1) cut_vertex[src] = 1;
    };
    dfs(dfs, 0, -1);
    cout << accumulate(cut_vertex.begin(), cut_vertex.end(), 0) << '\n';
    for (int i = 0; i < n; i++)
        if (cut_vertex[i]) cout << i + 1 << ' ';
    cout << '\n';
}
