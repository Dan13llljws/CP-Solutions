#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  vector<int> dp1(1 << 20), dp2(1 << 20);
  for (int &x : a) cin >> x, dp1[x]++, dp2[x]++;
  for (int i = 0; i < 20; i++) 
    for (int j = 0; j < (1 << 20); j++) 
      if (j >> i & 1) dp1[j] += dp1[j ^ (1 << i)];
      else dp2[j] += dp2[j ^ (1 << i)];
  for (int x : a) 
    cout << dp1[x] << ' ' << dp2[x] << ' ' << n - dp1[((1 << 20) - 1) ^ x] << '\n';
}
