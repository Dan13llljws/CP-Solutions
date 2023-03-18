#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b), adj[b].push_back(a);
    } 
    int ans = 1e9;
    for (int i = 1; i <= n; i++){
        vector<int> vis(n + 1), d(n + 1);
        queue<array<int,2>> q;
        q.push({i, 0}), vis[i] = 1, d[i] = 0;
        while(q.size()){
            int u = q.front()[0], p = q.front()[1]; q.pop();
            for (int v : adj[u]){
                if (v == p) continue;
                if (!vis[v]) vis[v] = 1, q.push({v, u}), d[v] = d[u] + 1;
                else ans = min(ans, d[u] + d[v] + 1);
            }
        }
    }
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
}

