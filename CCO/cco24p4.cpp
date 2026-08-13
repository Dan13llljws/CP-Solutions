#include "bits/stdc++.h"
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
const int MM = 4005;
int n, k, f[MM], l[MM], r[MM], w[MM], s[MM];
ll dp[MM][MM], fac[MM], inv[MM];

ll fpow(ll x, int k) {
  ll ret = 1;
  while(k) {
    if (k & 1) ret = ret * x % mod;
    x = x * x % mod, k >>= 1;
  } 
  return ret;
}

ll c(int a, int b) { return a >= b ? fac[a] * inv[b] % mod * inv[a - b] % mod : 0;}

void dfs(int src, bool is_lc) {
  s[src] = f[src], w[src] = 1;
  int lc = l[src], rc = r[src];
  if (lc) dfs(lc, 1);
  if (rc) dfs(rc, 0);
  s[src] += s[lc] + s[rc];
  w[src] += w[lc] + w[rc];
  if (w[src] < s[src]) { cout << 0 << '\n'; exit(0); }
  if (!is_lc) swap(lc, rc);
  for (int i = 0; i + s[src] < w[src]; i++) {
    for (int j = 0; j <= f[src]; j++) {
      int lft = min(j + i, w[lc] - s[lc]);
      int rit = f[src] - j + i - (lft - j);
      if (j > w[lc] - s[lc] || rit > w[rc] - s[rc]) continue;
      dp[src][i] = (dp[src][i] + c(lft, j) * dp[lc][lft] % mod * c(rit, f[src] - j) % mod * dp[rc][rit] % mod) % mod;
    }
    dp[src][i] = dp[src][i] * fac[f[src]] % mod;
  }
  int i = w[src] - s[src];
  if (i >= 0) {
    for (int j = 0; j <= f[src]; j++) {
      int lft = w[lc] - s[lc], rit = w[rc] - s[rc];
      dp[src][i] = (dp[src][i] + fac[f[src]] * c(lft, j) % mod * dp[lc][lft] % mod * c(rit, f[src] - j) % mod * dp[rc][rit] % mod) % mod;
      if (f[src]) dp[src][i] = (dp[src][i] + fac[f[src]] * c(lft, j) % mod * dp[lc][lft] % mod * c(rit, f[src] - j - 1) % mod * dp[rc][rit] % mod) % mod;
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int x; cin >> x;
    f[x]++;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  inv[n] = fpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  dp[0][0] = 1, dfs(1, 1);
  cout << dp[1][0] << '\n';
}
