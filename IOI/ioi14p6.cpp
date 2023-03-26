#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5;
struct node{int l, r, v; ll s;} seg[MM*50];
int n, m, s, t, a[MM], id[MM], pos[MM], rt[MM]; ll ans, dp[2][MM*3]; 
void upd(int &i, int p, int v, int l1 = 0, int r1 = n - 1){
    seg[++t] = seg[i], i = t, seg[i].v++, seg[i].s += v;
    if (l1 == r1){seg[i].v = 1, seg[i].s = v; return;}
    int mid = (l1 + r1) >> 1;
    if (p <= mid) upd(seg[i].l, p, v, l1, mid);
    else upd(seg[i].r, p, v, mid + 1, r1);
}
ll get(int i, int k, int l1 = 0, int r1 = n - 1){
    if (!i || k <= 0) return 0;
    if (l1 == r1) return seg[i].s;
    int mid = (l1 + r1) >> 1;
    if (seg[seg[i].l].v >= k) return get(seg[i].l, k, l1, mid);
    return seg[seg[i].l].s + get(seg[i].r, k - seg[seg[i].l].v, mid + 1, r1);
}
void solve(int l, int r, int ql, int qr, int dir){
    if (l > r) return;
    int mid = (l + r) >> 1, bid = ql; ll best = 0;
    for (int i = ql; i <= qr; i++){
        int rem = mid - i - i * dir;
        if (rem > 0){
            ll cur = get(rt[i], rem);
            if (cur >= best) best = cur, bid = i;
        }
    } dp[dir][mid] = best, solve(l, mid - 1, ql, bid, dir), solve(mid + 1, r, bid, qr, dir);
}
void run(){
    for (int i = 1; i <= t; i++) seg[i].l = seg[i].r = seg[i].v = seg[i].s = 0;
    t = 0;
    for (int i = s, j = 0; i < n; i++, j++) upd(rt[j], pos[i], a[i]), rt[j + 1] = rt[j];
    solve(0, m, 0, n - s - 1, 1);
    for (int i = 1; i <= t; i++) seg[i].l = seg[i].r = seg[i].v = seg[i].s = 0;
    t = 0;
    for (int i = s - 1, j = 1; i >= 0; i--, j++) upd(rt[j], pos[i], a[i]), rt[j + 1] = rt[j];
    solve(0, m, 0, s, 0); 
    for (int i = 0; i <= m; i++) ans = max(ans, dp[0][i] + dp[1][m - i]);
}
long long int findMaxAttraction(int N, int start, int d, int attraction[]){
    n = N, s = start, m = d;
    for (int i = 0; i < n; i++) a[i] = attraction[i], id[i] = i;
    sort(id, id + n, [&](int i, int j){return a[i] > a[j];});
    for (int i = 0; i < n; i++) pos[id[i]] = i;
    run(), s = n - s - 1, reverse(pos, pos + n), reverse(a, a + n), run(); return ans;
}
