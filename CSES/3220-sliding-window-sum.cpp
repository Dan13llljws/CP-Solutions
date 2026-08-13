#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, k, a, b, c, x; cin >> n >> k >> x >> a >> b >> c;
  vector<ll> d(n);
  ll sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    d[i] = i ? (a * d[i - 1] + b) % c : x;
    sum += d[i];
    if (i >= k) sum -= d[i - k];
    if (i >= k - 1) ans ^= sum;
  }
  cout << ans << '\n';
}