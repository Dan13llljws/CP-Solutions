#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  vector<pair<int,int>> l, r;
  for (int i = 0, j = 0; i < n && j < n;) {
    if (a[i] != b[j]) {
      while(i < n && a[i] != b[j]) i++;
      if (i == n) return cout << "NO\n", 0;
      if (j < i) l.emplace_back(j, i);
      while(j <= i && a[i] == b[j]) j++;
    }
    if (a[i] == b[j]) {
      while(j < n && a[i] == b[j]) j++;
      if (j - 1 > i) r.emplace_back(i, j - 1);
      i++;
    }
  }
  cout << "YES\n";
  cout << l.size() + r.size() << '\n';
  for (auto [x, y] : l) cout << "L " << x << ' ' << y << '\n';
  reverse(r.begin(), r.end());
  for (auto [x, y] : r) cout << "R " << x << ' ' << y << '\n';
}
