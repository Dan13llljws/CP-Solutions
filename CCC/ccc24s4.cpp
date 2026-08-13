#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b; a--, b--;
    adj[a].push_back({i, b});
    adj[b].push_back({i, a});
  }
  string ans(m, 'G');
  vector<int> vis(n);
  auto dfs = [&](auto self, int src, int f) -> void {
    vis[src] = 1;
    for (auto [id, v] : adj[src]) {
      if (vis[v]) continue;
      ans[id] = f ? 'R' : 'B';
      self(self, v, f^1);
    }
  };
  for (int i = 0; i < n; i++) 
    if (!vis[i]) vis[i] = 1, dfs(dfs, i, 0);
  cout << ans << '\n';
}
