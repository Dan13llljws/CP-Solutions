#include "bits/stdc++.h"
using namespace std;

using ll = long long;

const int MM = 1e5 + 5;
ll psa[MM];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q; cin >> n >> q;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    vector<pair<int,ll>> p;
    int x; cin >> x;
    mx = max(mx, x);
    // 13 -> 13 6 4 3 2 2 1 1 1 ...
    int y = 1, z = x;
    psa[1] += x;
    while(z) {
      y = x / z;
      int yp = y, zp = z;
      p.emplace_back(y, z);
      y++;
      z = x / y;
      psa[yp + 1] += z - zp;
    }
  }
  for (int i = 1; i <= mx + 1; i++) psa[i] += psa[i - 1];
  while(q--) {
    ll k; cin >> k;
    int mn = (mx + k - 1) / k; // min mode
    cout << (psa[mn] >= k ? "YES\n" : "NO\n");
  }
}