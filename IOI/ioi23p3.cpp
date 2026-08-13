#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

using ll = long long;

int biggest_stadium(int N, vector<vector<int>> F) {
  struct State {
    int t, b, l, r;
  };
  vector<vector<int>> psa(N + 1, vector<int>(N + 1));
  vector<vector<int>> n0(N + 1, vector<int>(N + 2, N + 1));
  vector<vector<int>> n1(N + 1, vector<int>(N + 2, N + 1));
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      psa[i][j] = F[i - 1][j - 1] + psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
  for (int i = 1; i <= N; i++) {
    for (int j = N; j; j--) {
      n1[i][j] = n1[i][j + 1], n0[i][j] = n0[i][j + 1];
      if (F[i - 1][j - 1]) n1[i][j] = j;
      else n0[i][j] = j;
    }
  }

  auto get = [&](int t, int b, int l, int r) {
    int res = psa[b][r] - psa[t - 1][r] - psa[b][l - 1] + psa[t - 1][l - 1];
    return res;
  };

  vector<queue<State>> q(N + 1);
  gp_hash_table<ll, int> dp;
  ll B = N + 2;
  auto encode = [&](int t, int b, int l, int r) {
    return (((1LL * t * B + (b + 1)) * B + l) * B + r);
  };
  auto add = [&](int t, int b, int l, int r, int v) {
    ll x = encode(t, b, l, r);
    auto [it, inserted] = dp.insert({x, v});
    if (inserted) q[r - l + 1].emplace(t, b, l, r);
    else if (v > it->second) it->second = v;
  };

  int ans = 0;
  for (int i = 1; i <= N + 1; i++) add(i, i - 1, 1, N, 0);
  for (int s = N; s;) {
    while(s >= 0 && q[s].empty()) s--;
    if (s < 0) break;
    auto [t, b, l, r] = q[s].front(); q[s].pop();
    int v = dp[encode(t, b, l, r)];
    if (l <= r) {
      int nt = *ranges::lower_bound(views::iota(1, t), true, {}, [&](int nt) { return !get(nt, b, l, r); });
      int nb = *ranges::lower_bound(views::iota(b, N + 1), false, greater<>{}, [&](int nb) {return !get(nt, nb, l, r); }) - 1;
      int nv = v + (nb - nt - b + t) * (r - l + 1);
      ans = max(ans, nv);

      if (nt > 1) {
        int i = n0[nt - 1][l];
        while(i <= r) {
          int j = n1[nt - 1][i];
          j = min(j, r + 1);
          if (i <= j) add(nt, nb, i, j - 1, nv);
          i = n0[nt - 1][j];
        }
      }
      if (nb < N) {
        int i = n0[nb + 1][l];
        while(i <= r) {
          int j = n1[nb + 1][i];
          j = min(j, r + 1);
          if (i <= j) add(nt, nb, i, j - 1, nv);
          i = n0[nb + 1][j];
        }
      }
    }
  }
  return ans;
}