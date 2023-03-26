#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lc i << 1
#define rc i << 1 | 1
const int MM = 5e5 + 5, mod = 1e9 + 7;
struct node{ll mp, mx; double p, x;}seg[MM<<2];
int n; ll x[MM], y[MM];
void push_up(int i){
    seg[i].x = seg[lc].x + seg[rc].x, seg[i].mx = seg[lc].mx * seg[rc].mx % mod;
    if (seg[lc].p > seg[rc].p + seg[lc].x)
        seg[i].p = seg[lc].p, seg[i].mp = seg[lc].mp;
    else seg[i].p = seg[rc].p + seg[lc].x, seg[i].mp = seg[rc].mp * seg[lc].mx % mod;
}
void build(int i, int l1 = 0, int r1 = n - 1){
    if (l1 == r1){
        seg[i].mp = x[l1] * y[l1] % mod, seg[i].mx = x[l1];
        seg[i].p = log(x[l1]) + log(y[l1]), seg[i].x = log(x[l1]); 
        return;
    } int mid = (l1 + r1) >> 1; 
    build(lc, l1, mid), build(rc, mid + 1, r1); push_up(i);
}
void upd(int i, int t, int p, int v, int l1 = 0, int r1 = n - 1){
    if (l1 == r1){
       if (t){
            seg[i].mp = x[l1] * v % mod, seg[i].p = log(x[l1]) + log(v);
            return;
       } else {
            seg[i].mp = y[l1] * v % mod, seg[i].p = log(y[l1]) + log(v);
            seg[i].mx = v, seg[i].x = log(v); return;
       }
    } int mid = (l1 + r1) >> 1;
    if (p <= mid) upd(lc, t, p, v, l1, mid);
    else upd(rc, t, p, v, mid + 1, r1);
    push_up(i);
}
int init(int N, int X[], int Y[]){
    n = N;
    for (int i = 0; i < N; i++) x[i] = X[i], y[i] = Y[i];
    build(1); return seg[1].mp;
}
int updateX(int pos, int val){
    upd(1, 0, pos, val), x[pos] = val;
    return seg[1].mp;
}
int updateY(int pos, int val){
    upd(1, 1, pos, val), y[pos] = val;
    return seg[1].mp;
}
int main(){}
