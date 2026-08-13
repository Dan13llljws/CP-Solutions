#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int dig[20], d;
ll dp[20][10][2][2], suf[20], p[20];
ll rec(int i, int cur, bool lim, bool lead) {
  ll &ret = dp[i][cur][lim][lead];
  if (ret != -1) return ret;
  if (!i) return ret = cur == d && (cur || lead);
  int to = lim ? dig[i - 1] : 9;
  ret = 0;
  if (cur == d && (cur || lead)) {
    ret = lim ? suf[i - 1] + 1 : p[i];
  }
  for (int j = 0; j <= to; j++) 
    ret += rec(i - 1, j, lim && j == to, j || lead);
  return ret;
}

int main() {
  ll x; cin >> x;
  ll l = 0, r = 1e18;
  p[0] = 1;
  for (int i = 1; i < 19; i++) p[i] = p[i - 1] * 10;
  while(l < r) {
    ll mid = (l + r + 1) / 2;
    ll tmp = mid;
    int up = 0;
    while(tmp) {
      dig[up++] = tmp % 10;
      tmp /= 10;
    } 
    suf[0] = dig[0];
    for (int i = 1; i < up; i++) 
      suf[i] = suf[i - 1] + p[i] * dig[i];
    bool good = 1;
    for (int i = 0; i < 10; i++) {
      memset(dp, -1, sizeof(dp));
      d = i, good &= rec(up, 0, 1, 0) <= x;
    }
    if (good) l = mid;
    else r = mid - 1;
  }
  cout << l << '\n';
}