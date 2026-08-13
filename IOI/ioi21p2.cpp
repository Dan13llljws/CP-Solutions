#include "bits/stdc++.h"
using namespace std;

vector<int> find_reachable(vector<int> r, vector<int> u, vector<int> v, vector<int> c) {
  int n = r.size();
  vector<vector<pair<int,int>>> adj(n);
  for (auto [u, v, c] : views::zip(u, v, c)) {
    adj[u].emplace_back(v, c);
    adj[v].emplace_back(u, c);
  }

  vector<int> vis(n), has_key(n), cands;
  vector<vector<int>> blocked(n), keys(n);
  int mn_p = 1e9;
  for (int i = 0; i < n; i++) keys[i].push_back(r[i]);

  // boruvka?
  vector<int> dsu(from_range, views::iota(0, n));
  auto find = [&](this auto &&self, int x) -> int { return x == dsu[x] ? x : dsu[x] = self(dsu[x]); };
  auto unite = [&](int x, int y) { dsu[find(x)] = find(y); };

  auto bfs = [&](int rt, auto &&relax) -> int {
    vector<int> used_cols, visited;
    queue<int> q;
    for (int k : keys[rt]) has_key[k] = 1;
    int ans = 0;
    vis[rt] = 1;
    q.push(rt);
    while(q.size()) {
      int u = q.front(); q.pop();
      visited.push_back(u);
      ans++; 
      if (!has_key[r[u]]) has_key[r[u]] = 1, keys[rt].push_back(r[u]);
      for (auto [v, c] : adj[u]) {
        if (has_key[c]) relax(v, q);
        else blocked[c].push_back(v), used_cols.push_back(c);
      }
      for (int v : blocked[r[u]]) relax(v, q);
      blocked[r[u]].clear();
    }
    for (int c : used_cols) blocked[c].clear();
    for (int k : keys[rt]) has_key[k] = 0;

    if (ans < mn_p) mn_p = ans, cands.clear();
    if (ans == mn_p) {
      for (int u : visited) cands.push_back(u);
    }
    return ans;
  };

  while(true) {
    vector<pair<int,int>> conn;
    vector<int> head;
    unordered_set<int> seen;
    for (int i = 0; i < n; i++)
      if (find(i) == i) head.push_back(i);
    
    mn_p = 1e9, cands.clear();
    for (int h : head) {
      bfs(h,[&](int v, auto &q) {
        if (!vis[v] && find(v) == h) q.push(v), vis[v] = 1;
        else if (find(v) != h && !seen.count(h)) seen.insert(h), conn.emplace_back(h, find(v));
      });
    }
    ranges::fill(vis, 0);

    if (conn.empty()) break;
    for (auto [u, v] : conn) unite(u, v);
  }

  vector<int> ans(n);
  for (int u : cands) ans[u] = 1;
  return ans;
}
