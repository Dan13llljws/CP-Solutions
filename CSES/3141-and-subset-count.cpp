#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;
 
int ceil_log2(int n) {
  return __builtin_popcount(n) == 1 ? n : 1 << (32 - __builtin_clz(n));
}

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = (res * 1LL * a) % mod;
    a = (a * 1LL * a) % mod;
    b >>= 1;
  }
  return res;
}
 
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n;
  vector<int> f(m = ceil_log2(n + 1));
  for (int i = 0; i < n; i++) { int x; cin >> x; f[x]++; }
  for (int i = 31; i >= 0; i--) 
    for (int mask = m - 1; mask >= 0; mask--) 
      if (mask & (1 << i)) 
        f[mask ^ (1 << i)] = (f[(mask ^ (1 << i))] + f[mask]) % mod;
  for (int i = 0; i < m; i++) f[i] = (fpow(2, f[i]) - !!i + mod) % mod;
  for (int i = 31; i >= 0; i--) 
    for (int mask = m - 1; mask >= 0; mask--) 
      if (mask & (1 << i)) 
        f[(mask ^ (1 << i))] = (f[(mask ^ (1 << i))] - f[mask] + mod) % mod;
  f[0] = (f[0] - 1 + mod) % mod;
  for (int i = 0; i <= n; i++) cout << f[i] << ' ';
  cout << '\n';
}