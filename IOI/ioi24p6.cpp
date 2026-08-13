#include "bits/stdc++.h"
using namespace std;

int perform_experiment(vector<int> E);

vector<int> find_colours(int N, vector<int> X, vector<int> Y) {
  vector<vector<int>> adj(N);
  for (auto [u, v] : views::zip(X, Y)) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> dsu(N, -1);
  auto find = [&](this auto &&self, int x) -> int { return dsu[x] == x ? x : dsu[x] = self(dsu[x]); };
  auto unite = [&](int x, int y) { dsu[find(x)] = find(y); };

  auto query = [&](const vector<int> &v, int col) {
    vector<int> c(N, col);
    for (int u : v) c[u] = -1;
    int res = perform_experiment(c);
    int components_cnt = 0;
    vector<bool> vis(N, false);
    for (int i = 0; i < N; i++) {
      if (vis[i] || c[i] == -1) continue;
      components_cnt++;

      queue<int> q;
      vis[i] = true;
      q.push(i);
      while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur])
          if (!vis[nxt] && c[nxt] == c[cur]) {
            vis[nxt] = true;
            q.push(nxt);
          }
      }
    }
    return res - components_cnt;
  };

  for (int u = 0; u < N; u++) {
    dsu[u] = u;
    unordered_set<int> seen;
    vector<int> m;
    for (int v : adj[u])
      if (dsu[v] != -1 && !seen.count(find(v))) m.push_back(v), seen.insert(find(v));
    if (m.empty()) continue;
    m.push_back(u);
    int e = m.size() - query(m, N);
    m.pop_back();
    while(e--) {
      int l = 0, r = m.size();
      while(l < r - 1) {
        int mid = (l + r) / 2;
        vector<int> v(m.begin() + l, m.begin() + mid);
        v.push_back(u);
        if (query(v, N) > mid - l) l = mid;
        else r = mid;
      }
      unite(u, m[l]);
      m.erase(m.begin() + l);
    }
  }

  vector<vector<int>> f(N);
  for (int i = 0; i < N; i++) f[find(i)].push_back(i);

  vector<int> vis(N);
  array<vector<vector<int>>,2> gs;
  [&](this auto &&self, int u, int val) -> void {
    if (u == find(u)) gs[val].push_back(f[u]);
    vis[u] = 1;
    for (int v : adj[u])
      if (!vis[v]) self(v, val ^ (find(v) != find(u)));
  }(0, 0);

  if (gs[1].empty()) {
    for (int i = 0; i < N; i++)
      if (query({0}, i) == 0)
        return vector<int>(N, i);
  }

  auto flatten = [&](vector<vector<int>> v) {
    return v | views::join | ranges::to<vector<int>>();
  };

  vector<int> ans(N);
  for (auto g : gs) {
    for (int col = 0; col < N; col++) {
      auto m = flatten(g);
      while (query(m, col) < (int)g.size()) {
        int l = 0, r = g.size();
        while(l < r - 1) {
          int mid = (l + r) / 2;
          auto cur = flatten(vector<vector<int>>(g.begin() + l, g.begin() + mid));
          if (query(cur, col) < mid - l) r = mid;
          else l = mid;
        }
        for (int u : g[l]) ans[u] = col;
        g.erase(g.begin() + l);
        m = flatten(g);
      }
    }
  }

  return ans;
}
