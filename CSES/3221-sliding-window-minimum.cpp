#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, k, a, b, c, x; cin >> n >> k >> x >> a >> b >> c;
  deque<pair<int,int>> q;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    while(q.size() && q.front().second <= i - k) q.pop_front();
    while(q.size() && q.back().first >= x) q.pop_back();
    q.push_back({x, i});
    if (i >= k - 1) ans ^= q.front().first;
    x = (1LL * a * x + b) % c;
  }
  cout << ans << '\n';
}