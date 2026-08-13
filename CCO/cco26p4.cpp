#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> g(m, vector<int>(n));
  if (n == 1) {
    cout << 1LL * (m / 2) * ((k + 1) / 2) << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> g[j][i];
  ll ans = 0;
  for (int j = 0; j < m / 2; j++) {
    auto work = [&](const vector<int> &l, const vector<int> &r) -> ll {
      ll diff = 0, best = 1e18;
      vector<int> pre(n + 2), suf(n + 2);
      for (int i = 0; i < n; i++) {
        ll d = abs(l[i] - r[i]);
        pre[i + 1] = suf[i + 1] = max(l[i], k - l[i]) - d;
        diff += d;
      }
      for (int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], pre[i]);
      for (int i = n; i; i--) suf[i] = max(suf[i + 1], suf[i]);
      for (int i = 0; i < n; i++) {
        ll C = max(pre[i], suf[i + 2]);
        /* 4 lines: K - x, x, C + a_r - x, C - a_r + x, highest intersection */
        ll x1 = k / 2, x2 = (k - (C - r[i])) / 2, x3 = (C + r[i]) / 2; // x4 = r[i]
        ll val = max({k - x1, k - x2, C + r[i] - x3, C});
        best = min(best, diff - abs(l[i] - r[i]) + val);
      }
      return best;
    };
    ans += min(work(g[j], g[m - j - 1]), work(g[m - j - 1], g[j]));
  }
  cout << ans << '\n';
}