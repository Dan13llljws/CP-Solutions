#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i >= n / 2) ans += 2 * (a[i] == a[i - n / 2]);
  }
  cout << ans << '\n';
}
