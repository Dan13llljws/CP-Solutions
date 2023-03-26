#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
#define mid ((l1 + r1) >> 1)
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, mx[MM<<2], mn[MM<<2], lz[MM<<2]; ll ans; pair<int,int> p[MM];
void push_down(int i){
    if (!lz[i]) return;
    lz[lc] += lz[i], mx[lc] += lz[i], mn[lc] += lz[i];
    lz[rc] += lz[i], mx[rc] += lz[i], mn[rc] += lz[i], lz[i] = 0;
}
void upd(int i, int l, int r, int v, int l1 = 1, int r1 = 1e5){
    if (l == l1 && r == r1){mx[i] += v, mn[i] += v, lz[i] += v; return;}
    push_down(i);
    if (r <= mid) upd(lc, l, r, v, l1, mid);
    else if (l > mid) upd(rc, l, r, v, mid + 1, r1);
    else upd(lc, l, mid, v, l1, mid), upd(rc, mid + 1, r, v, mid + 1, r1);
    mx[i] = max(mx[lc], mx[rc]), mn[i] = min(mn[lc], mn[rc]);
}
int get(int i, int p, int l1 = 1, int r1 = 1e5){
    if (l1 == r1) return mx[i];
    push_down(i);
    if (p <= mid) return get(lc, p, l1, mid);
    return get(rc, p, mid + 1, r1);
}
int gmn(int i, int k, int l1 = 1, int r1 = 1e5){
    if (l1 == r1) return l1;
    push_down(i);
    if (mn[lc] < k) return gmn(lc, k, l1, mid);
    return gmn(rc, k, mid + 1, r1);
}
int gmx(int i, int k, int l1 = 1, int r1 = 1e5){
    if (l1 == r1) return l1;
    push_down(i);
    if (mx[rc] >= k) return gmx(rc, k, mid + 1, r1);
    return gmx(lc, k, l1, mid);
}
int main(){
    n = re;
    for (int i = 0; i < n; i++) p[i] = {re, re};
    sort(p, p + n);
    for (int i = 0; i < n; i++){
        int h = p[i].first, k = p[i].second, t = get(1, h - k + 1) + 1;
        upd(1, h - k + 1, h, 1);
        int l = gmn(1, t), r = gmx(1, t);
        if (l < r) upd(1, h - k + 1, r, -1), upd(1, l, l + r - h + k - 1, 1);
    }
    for (int i = 1, t; i <= 1e5; i++) t = get(1, i), ans += 1LL * t * (t - 1) / 2;
    printf("%lld\n", ans);
}
