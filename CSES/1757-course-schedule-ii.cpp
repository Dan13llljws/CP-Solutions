#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<int> in(n);
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b; a--, b--;
    adj[b].push_back(a);
    in[a]++;
  }
  priority_queue<int> q;
  for (int i = 0; i < n; i++) 
    if (!in[i]) q.push(i);
  vector<int> ans;
  while(q.size()) {
    int u = q.top(); q.pop();
    ans.push_back(u + 1);
    for (int v : adj[u]) 
      if (!--in[v]) q.push(v);
  }
  reverse(ans.begin(), ans.end());
  for (int x : ans) cout << x << ' ';
  cout << '\n';
}
