#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 2e5 + 5;
struct LazySegTree{
    struct node{ll sum; int mx, lz;}seg[MM<<2];
    #define lc (i << 1)
    #define rc (i << 1) | 1
    int n;
    LazySegTree(int _n) : n(_n){}
    void push_down(int i, int l, int r){
        if (seg[i].lz == -1) return;
        seg[lc].lz = seg[rc].lz = seg[lc].mx = seg[rc].mx = seg[i].lz;
        int mid = (l + r) >> 1;
        seg[lc].sum = 1LL * (mid - l + 1) * seg[i].lz;
        seg[rc].sum = 1LL * (r - mid) * seg[i].lz;
        seg[i].lz = -1;
    }
    void push_up(int i){
        seg[i].mx = max(seg[lc].mx, seg[rc].mx);
        seg[i].sum = seg[lc].sum + seg[rc].sum;
    }
    void update(int i, int l, int r, int v, int l1, int r1){
        if (l == l1 && r == r1){
            seg[i].lz = seg[i].mx = v;
            seg[i].sum = 1LL * (r - l + 1) * v;
            return;
        } int mid = (l1 + r1) >> 1;
        push_down(i, l1, r1);
        if (r <= mid) update(lc, l, r, v, l1, mid);
        else if (l > mid) update(rc, l, r, v, mid + 1, r1);
        else update(lc, l, mid, v, l1, mid), update(rc, mid + 1, r, v, mid + 1, r1);
        push_up(i);
    }
    void update(int l, int r, int v){ update(1, l, r, v, 0, n - 1); }
    ll get(int i, int l, int r, int l1, int r1){
        if (l == l1 && r == r1) return seg[i].sum;
        int mid = (l1 + r1) >> 1;
        push_down(i, l1, r1);
        if (r <= mid) return get(lc, l, r, l1, mid);
        if (l > mid) return get(rc, l, r, mid + 1, r1);
        return get(lc, l, mid, l1, mid) + get(rc, mid + 1, r, mid + 1, r1);
    }
    ll get(int l, int r){ return get(1, l, r, 0, n - 1); }
    int lower_bound(int i, int v, int l1, int r1){
        if (l1 == r1) return l1 + (v >= seg[i].mx);
        int mid = (l1 + r1) >> 1;
        push_down(i, l1, r1);
        if (seg[lc].mx >= v) return lower_bound(lc, v, l1, mid);
        return lower_bound(rc, v, mid + 1, r1);
    }
    int lower_bound(int v){ return lower_bound(1, v, 0, n - 1); }
    #undef lc
    #undef rc
};
    
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<ll> ans(q), psa(n + 1);
    for (int &x : a) cin >> x;
    for (int i = 1; i <= n; i++) psa[i] = psa[i - 1] + a[i - 1];
    vector<vector<pair<int,int>>> qs(n);
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        qs[--l].push_back({i, r});
    }
    LazySegTree seg(n);
    for (int i = n - 1; i >= 0; i--){
        int k = seg.lower_bound(a[i]);
        seg.update(i, k - 1, a[i]);
        for (auto [id, r] : qs[i])
            ans[id] = seg.get(i, r - 1) - psa[r] + psa[i];
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
