#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  map<int,int> lst;
  ll ans = 0;
  for (int i = 0, j = 0; i < n; i++) {
    int x = a[i];
    if (lst.count(x)) j = max(j, lst[x] + 1);  
    ans += i - j + 1;
    lst[x] = i;
  }
  cout << ans << '\n';
}