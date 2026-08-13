#include "bits/stdc++.h"
using namespace std;
 
int ceil_log2(int n) {
  return __builtin_popcount(n) == 1 ? n : 1 << (32 - __builtin_clz(n));
}
 
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int m = ceil_log2(n);
  a.resize(m);
  auto rec = [&](auto self, int l, int r) -> void {
    int len = r - l;
    if (len == 1) return;
    int mid = (l + r) / 2;
    self(self, l, mid); self(self, mid, r);
    for (int i = l; i < mid; i++) a[i + len / 2] ^= a[i];
  };
  rec(rec, 0, m);
  a = vector<int>(a.begin() + n - k, a.end());
  a.resize(m);
  rec(rec, 0, m);
  for (int i = 0; i < k; i++) cout << a[i] << ' ';
  cout << '\n';
}