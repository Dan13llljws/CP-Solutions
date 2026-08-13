#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  map<int,int> f;
  while(n--) {int x; cin >> x; f[x]++;}
  int ans = 1;
  for (auto [_, y] : f) ans = 1LL * ans * (y + 1) % mod;
  ans = (ans + mod - 1) % mod;
  cout << ans << '\n';
}