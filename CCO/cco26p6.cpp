#include "bits/stdc++.h"
using namespace std;

using ll = long long;

const int MM = 51, MOD = 1e9 + 7;

int p2[MM], fac[MM]; // # comp, # B-W, # W-B, # W-W, (# B-B is # comp - all)

void add(int &x, ll y) { x = (x + y) % MOD; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n; cin >> n;
  string s; cin >> s;

  p2[0] = 1, fac[0] = 1;
  for (int i = 1; i <= n; i++) p2[i] = p2[i - 1] * 2 % MOD, fac[i] = 1LL * fac[i - 1] * i % MOD;

  unordered_map<array<int, 4>, int, decltype([](auto &a) {
    size_t h = 0;
    for (int x : a) h = h * 239017 + x + 1;
    return h;
  })> dp;
  dp[{0, 0, 0, 0}] = 1;
  for (int i = 2; i < n; i++) {
    // own comp, append to an end, merge 2 intervals
    bool white = s[i] == 'W', black = !white;
    decltype(dp) ndp;
    for (auto [state, val] : dp) {
      auto [c, bw, wb, ww] = state;
      // assert(bw + wb + ww <= c);
      int bb = c - bw - wb - ww;
      ll v = val % MOD;
      add(ndp[{c, bw, wb, ww}], v);
      add(ndp[{c + 1, bw, wb, ww + white}], v);
      add(ndp[{c, bw, wb, ww}], v * (white * (ww + wb) + black * (bb + bw)));
      if (bw >= black && wb >= white) add(ndp[{c, bw - black, wb - white, ww + white}], v * (white * wb + black * bw));
      if (ww >= black && bb >= white) add(ndp[{c, bw + white, wb + black, ww - black}], v * (white * bb + black * ww));
      array<int,4> ways = white ? array<int,4>{wb * ww, wb * (wb - 1), bb * ww, bb * wb}
                                : array<int,4>{ww * bw, ww * bb, bw * (bw - 1), bw * bb};
      for (int l : {0, 1}) for (int r : {0, 1}) {
        int nbw = bw - black * (l + !r) + (l & !r);
        int nwb = wb - white * (!l + r) + ((!l) & r);
        int nww = ww - white * !r - black * !l + (!l & !r);
        int nbb = bb - white * l - black * r + (l & r);
        if (nbw < 0 || nwb < 0 || nww < 0 || nbb < 0) continue;
        add(ndp[{c - 1, nbw, nwb, nww}], v * ways[l << 1 | r]);
      }
    }
    swap(dp, ndp);
  }

  int ans = 0;
  for (auto [state, val] : dp) {
    auto [c, bw, wb, ww] = state;
    if (bw + wb + ww == c) add(ans, 1LL * val * p2[ww] % MOD * fac[c]);
  }
  cout << ans % MOD << '\n';
}