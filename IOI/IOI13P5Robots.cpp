#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define lc i << 1
#define rc i << 1 | 1
const int MM = 5e4 + 5, MN = 1e6 + 5;
struct node{ll v, mn;}seg[MM<<2];
int a, b, t, x[MM], y[MM]; pii p[MN];
void push_up(int i){seg[i].v = seg[lc].v + seg[rc].v; seg[i].mn = min(seg[rc].mn, seg[lc].mn + seg[rc].v);}
void build(int i, int v, int l1 = 0, int r1 = b - 1){
    if (!b) return;
    if (l1 == r1){seg[i].v = seg[i].mn = v; return;}
    int mid = (l1 + r1) >> 1;
    build(lc, v, l1, mid), build(rc, v, mid + 1, r1), push_up(i);
}
void upd(int i, int p, int v, int l1 = 0, int r1 = b - 1){
    if (l1 == r1){seg[i].mn += v, seg[i].v += v; return;}
    int mid = (l1 + r1) >> 1;
    if (p <= mid) upd(lc, p, v, l1, mid);
    else upd(rc, p, v, mid + 1, r1);
    push_up(i);
}
bool check(int mid){
    build(1, mid); ll need = 0, j = t - 1; priority_queue<int> q;
    while(j >= 0 && (!a || p[j].first >= x[a - 1])){
        if (!b) return 0;
        int tmp = upper_bound(y, y + b, p[j].second) - y;
        if (tmp >= b) return 0;
        upd(1, tmp, -1), j--;
    }
    if (seg[1].mn < 0) return 0;
    for (int i = a - 1; i >= 0; i--){
        while(j >= 0 && (i == 0 || p[j].first >= x[i - 1])) q.push(p[j].second), j--;
        need += mid;
        while(need && q.size()) q.pop(), need--;
        while(q.size()){
            if (!b) return 0;
            int tmp = q.top(); q.pop();
            tmp = upper_bound(y, y + b, tmp) - y;
            if (tmp >= b) return 0;
            upd(1, tmp, -1);
        } if (seg[1].mn < 0) return 0;
    } return 1;
}
int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]){
    sort(X, X + A), sort(Y, Y + B); a = A, b = B, t = T;
    for (int i = 0; i < A; i++) x[i] = X[i];
    for (int i = 0; i < B; i++) y[i] = Y[i];
    for (int i = 0; i < T; i++){
        p[i] = {W[i], S[i]};
        if ((!A || W[i] >= X[A - 1]) && (!B || S[i] >= Y[B - 1])) return -1;
    }
    sort(p, p + t, [](pii aa, pii bb){return aa.first < bb.first;});
    int l = 1, r = t;
    while(l < r){
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    } return l;

