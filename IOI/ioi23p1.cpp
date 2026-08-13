#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int max_score(int N, int X, int Y, ll K, vector<int> U, vector<int> V, vector<int> W) {
  vector<vector<pair<int,int>>> adj(N);
  for (auto [u, v, w] : views::zip(U, V, W)) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  int ans = 0;

  { // disjoint
    vector<ll> d(N, 1e18);
    int cnt = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.emplace(0, X), d[X] = 0;
    q.emplace(0, Y), d[Y] = 0;
    ll tot = 0;
    while(q.size()) {
      auto [dis, u] = q.top(); q.pop();
      if (dis > d[u]) continue;
      if (tot + d[u] > K) break;
      cnt++, tot += d[u];
      for (auto [v, w] : adj[u]) {
        if (d[v] > d[u] + w) d[v] = d[u] + w, q.emplace(d[v], v);
      }
    }
    ans = cnt;
  }

  auto bfs = [&](int src) {
    vector<ll> d(N, 1e18);
    queue<int> q;
    q.push(src);
    d[src] = 0;
    while(q.size()) {
      int u = q.front(); q.pop();
      for (auto [v, w] : adj[u]) {
        if (d[v] > d[u] + w) d[v] = d[u] + w, q.push(v);
      }
    }
    return d;
  };

  auto dx = bfs(X), dy = bfs(Y);
  vector<ll> mn(N), mx(N);
  for (int i = 0; i < N; i++) {
    mn[i] = min(dx[i], dy[i]);
    mx[i] = max(dx[i], dy[i]);
  }

  vector<ll> items;
  vector<int> bad;
  int c = 0;
  ll need = 0, rsum = 0;
  for (int i = 0; i < N; i++) {
    if (dx[Y] == dx[i] + dy[i]) {
      c++, need += mn[i];
      items.push_back(mx[i] - mn[i]);
    } else {
      if (mx[i] - mn[i] >= mn[i]) items.push_back(mn[i]), items.push_back(mx[i] - mn[i]);
      else bad.push_back(i), rsum += mx[i];
    }
  }
  ranges::sort(items);
  ranges::sort(bad, {}, [&](int x) { return mx[x]; });

  int t = items.size();
  items[0] += need;
  for (int i = 1; i < t; i++) items[i] += items[i - 1];

  ll mn_one = 1e18;
  for (int i = 0; i < t; i++) {
    ll rem = K - items[i];
    if (rem < 0) break;
    while(rsum > rem) {
      int j = bad.back(); bad.pop_back();
      rsum -= mx[j];
      mn_one = min(mn_one, mn[j]);
    }
    int cur = i + 1 + c + 2 * bad.size();
    if (rem - rsum >= mn_one) cur++;
    ans = max(ans, cur);
  }

  return ans;
}