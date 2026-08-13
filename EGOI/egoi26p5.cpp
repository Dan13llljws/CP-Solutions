#include "bits/stdc++.h"
#include "../lib/debug.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, d; cin >> n >> d;
  vector<int> t(n);
  for (int &x : t) cin >> x;
  vector<int> lst(n, -1), sum(n);
  auto upd = [&](int i, int day) {
    if (!i) return;
    if (t[i] < t[i - 1]) {
      if (lst[i] == -1) lst[i] = day + 1;
    } else {
      if (lst[i] != -1) {
        sum[i] += day - lst[i] + 1;
        lst[i] = -1;
      }
    }
  };
  for (int i = 1; i < n; i++) upd(i, -1);
  dbg(lst);
  dbg(sum);
  for (int i = 0; i < d; i++) {
    char c; cin >> c;
    if (c == '!') {
      int r, x; cin >> r >> x;
      t[r] = x;
      upd(r, i);
      if (r < n - 1) upd(r + 1, i);
    } else {
      int r; cin >> r;
      int ans = sum[r];
      if (lst[r] != -1) ans += i - lst[r] + 1;
      cout << ans << '\n';
    }
  dbg(i);
  dbg(lst);
  dbg(sum);
  }
}