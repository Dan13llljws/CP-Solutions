#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int m, x, l;
vector<int> s;
vector<vector<ll>> p, dp;

void init(int L, int N, vector<ll> T, vector<int> W, int X, int M, vector<int> S) {
  m = M, x = X, l = L, s = S;
  vector<ll> k; vector<int> w;
  for (int i = 0; i < N; i++) {
    if (W[i] > X) w.push_back(W[i]), k.push_back(T[i]);
  }
  N = w.size();
  p.resize(M, vector<ll>(N)); dp.resize(M, vector<ll>(N, -1));
  vector<vector<ll>> t(M, vector<ll>(N)), e(M, vector<ll>(N));
  e[0] = t[0] = k;
  vector<int> ord(from_range, views::iota(0, N));
  ranges::sort(ord, {}, [&](int x) { return make_pair(t[0][x], w[x]); });
  for (int j = 0; j < N; j++) p[0][j] = t[0][ord[j]];
  for (int i = 1; i < M; i++) {
    for (int j = 0; j < N; j++)
      e[i][j] = t[i - 1][j] + 1LL * w[j] * (s[i] - s[i - 1]);
    ll mx = 0;
    for (int j = 0; j < N; j++) {
      t[i][ord[j]] = max(e[i][ord[j]], mx);
      mx = max(mx, e[i][ord[j]]);
    }
    ranges::sort(ord, {}, [&](int x) { return make_pair(t[i][x], w[x]); });
    for (int j = 0; j < N; j++) p[i][j] = t[i][ord[j]];
  }
  dp[M - 1] = p[M - 1];
  for (int i = M - 2; i >= 0; i--) {
    for (int j = 0; j < N; j++) {
      int j1 = ranges::lower_bound(p[i], p[i][j]) - p[i].begin() - 1;
      if (j1 == -1) dp[i][j] = p[i][j] + 1LL * (L - s[i]) * X;
      else {
        ll cur = p[i][j];
        auto ran = views::iota(i, M);
        auto it = ranges::lower_bound(ran, true, {}, [&](int i1) {
          return p[i1][j1] >= cur + 1LL * (s[i1] - s[i]) * X;
        });
        dp[i][j] = it == ran.end() ? p[i][j] + 1LL * (L - s[i]) * X : dp[*it][j1];
      }
    }
  }
}


ll arrival_time(ll Y) {
  int j1 = ranges::lower_bound(p[0], Y) - p[0].begin() - 1;
  if (j1 == -1) return 1LL * l * x + Y;
  auto ran = views::iota(0, m);
  auto it = ranges::lower_bound(ran, true, {}, [&](int i1) {
    return p[i1][j1] >= Y + 1LL * s[i1] * x;
  });
  return it == ran.end() ? 1LL * l * x + Y : dp[*it][j1];
}