#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  vector<array<int,3>> st;
  for (int i = 0; i < n; i++) {
    ll b; cin >> b;
    while(st.size() && st.back()[2] < i) st.pop_back();
    int l, r;
    if (st.size()) {
      auto [p, lp, rp] = st.back(); st.pop_back();
      ll prev = 1LL * (rp - p + 1) * (p - lp + 1);
      if (prev == b) l = lp, r = rp;
      else l = p + 1, r = i + b / (i - p) - 1;
    } else {
      l = 0, r = i + b / (i + 1) - 1;
    }
    st.push_back({i, l, r});
    println("{}", st);
    a[i] = n - (r - l + 1) + 1;
  }
  for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
}