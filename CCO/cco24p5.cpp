#include "bits/stdc++.h"
using namespace std;

using ll = long long;

const int mod = 1e6 + 3;
const int MM = 5e5 + 5;
#define lc i << 1 
#define rc i << 1 | 1
struct Node {
  int sum, mn, lz;
} seg[2][MM * 4];

int n;

void push_down(Node seg[], int i) {
  if (!seg[i].lz) return;
  int &z = seg[i].lz;
  seg[lc].lz += z, seg[rc].lz += z;
  seg[lc].mn += z, seg[rc].mn += z;
  z = 0;
}

Node comb(Node a, Node b) {
  if (a.mn == b.mn) return {(a.sum + b.sum) % mod, a.mn, 0};
  Node ret = a.mn < b.mn ? a : b;
  ret.lz = 0;
  return ret;
}

void upd_dp(Node seg[], int i, int p, int v, int l = 0, int r = n) {
  if (l == r) { seg[i].sum = v; return; }
  int mid = (l + r) / 2; push_down(seg, i);
  if (p <= mid) upd_dp(seg, lc, p, v, l, mid);
  else upd_dp(seg, rc, p, v, mid + 1, r);
  seg[i] = comb(seg[lc], seg[rc]);
}

void upd_mn(Node seg[], int i, int l, int r, int v, int l1 = 0, int r1 = n) {
  if (l == l1 && r == r1) { seg[i].mn += v, seg[i].lz += v; return; }
  int mid = (l1 + r1) / 2; push_down(seg, i);
  if (r <= mid) upd_mn(seg, lc, l, r, v, l1, mid);
  else if (l > mid) upd_mn(seg, rc, l, r, v, mid + 1, r1);
  else upd_mn(seg, lc, l, mid, v, l1, mid), upd_mn(seg, rc, mid + 1, r, v, mid + 1, r1);
  seg[i] = comb(seg[lc], seg[rc]);
}

Node get_dp(Node seg[], int i, int l, int l1 = 0, int r1 = n) {
  if (l == l1) return seg[i];
  int mid = (l1 + r1) / 2; push_down(seg, i);
  if (l > mid) return get_dp(seg, rc, l, mid + 1, r1);
  return comb(get_dp(seg, lc, l, l1, mid), seg[rc]);
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> p(n + 1);
  vector<vector<int>> lst(2, vector<int>(n + 1)), cnt(2, vector<int>(n + 1));
  upd_dp(seg[0], 1, 0, 1), upd_dp(seg[1], 1, 0, 1);
  int l[2] = {0, 0}, max_p_diff = 0;
  for (int i = 1; i <= n; i++) {
    int x = a[i], par = i & 1;
    cnt[par][x]++;
    if (lst[par][x]) p[i] = lst[par][x];
    if (lst[par ^ 1][x]) max_p_diff = max(max_p_diff, lst[par ^ 1][x]); // check that this is computed correctly
    lst[par][x] = i;
    while(cnt[par][x] > 1) {
      if ((l[par] & 1) == par) cnt[par][a[l[par]]]--;
      l[par]++;
    }
    upd_mn(seg[par], 1, p[i], i - 1, 1);
    if (p[i]) upd_mn(seg[par], 1, p[p[i]], p[i] - 1, -1);
    auto a = get_dp(seg[1], 1, max(l[0] - 1, max_p_diff)), b = get_dp(seg[0], 1, max(l[1] - 1, max_p_diff));
    int dp = ((a.mn ? 0 : a.sum) + (b.mn ? 0 : b.sum)) % mod;
    if (i == n) cout << dp << '\n';
    upd_dp(seg[1], 1, i, dp), upd_dp(seg[0], 1, i, dp);
  }
}
