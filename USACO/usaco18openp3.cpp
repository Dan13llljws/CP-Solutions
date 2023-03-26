#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
const int mod = 1e9 + 7, MM = 5e4 + 5;
int n, m, t, a[MM], b[MM], seg[MM<<2], lz[MM<<2], in[MM], out[MM], fa[MM], head[MM], hvy[MM], dep[MM]; vector<int> adj[MM];
int dfs(int src){
    int ret = 1, mx = 0, cur;
    for (int v : adj[src]){
        if (v == fa[src]) continue;
        fa[v] = src, dep[v] = dep[src] + 1;
        ret += cur = dfs(v);
        if (cur > mx) mx = cur, hvy[src] = v;
    } return ret;
}
void hld(int src, int h){
    head[src] = h, in[src] = ++t;
    if (hvy[src]) hld(hvy[src], h);
    for (int v : adj[src])
        if (v != fa[src] && v != hvy[src]) hld(v, v);
    out[src] = t;
}
void push_down(int i){
    lz[lc] = min(lz[lc], lz[i]), lz[rc] = min(lz[rc], lz[i]);
    seg[lc] = min(seg[lc], seg[i]), seg[rc] = min(seg[rc], seg[i]);
    lz[i] = 0x3f3f3f3f;
}
void upd(int i, int l, int r, int v, int l1 = 1, int r1 = n){
    if (l == l1 && r == r1){seg[i] = min(seg[i], v), lz[i] = min(lz[i], v); return;}
    int mid = (l1 + r1) >> 1; push_down(i);
    if (r <= mid) upd(lc, l, r, v, l1, mid);
    else if (l > mid) upd(rc, l, r, v, mid + 1, r1);
    else upd(lc, l, mid, v, l1, mid), upd(rc, mid + 1, r, v, mid + 1, r1);
}
int get(int i, int p, int l1 = 1, int r1 = n){
    if (l1 == r1) return seg[i];
    int mid = (l1 + r1) >> 1; push_down(i);
    if (p <= mid) return get(lc, p, l1, mid);
    return get(rc, p, mid + 1, r1);
}
void U(int u, int v, int w){
    for (; head[u] != head[v]; u = fa[head[u]]){
        if (dep[head[u]] < dep[head[v]]) swap(u, v);
        upd(1, in[head[u]], in[u], w);
    }
    if (dep[u] < dep[v]) swap(u, v);
    if (u != v) upd(1, in[v] + 1, in[u], w);
}
int main(){
    n = re, m = re, memset(seg, 0x3f, sizeof seg), memset(lz, 0x3f, sizeof lz);
    for (int i = 1; i < n; i++){
        a[i] = re, b[i] = re;
        adj[a[i]].push_back(b[i]), adj[b[i]].push_back(a[i]);
    } dfs(1), hld(1, 1);
    while(m--){
        int u = re, v = re, w = re;
        U(u, v, w);
    }
    for (int i = 1; i < n; i++){
        if (dep[a[i]] < dep[b[i]]) swap(a[i], b[i]);
        int x = get(1, in[a[i]]);
        printf("%d\n", x > 1e9 ? -1 : x);
    } 
}
