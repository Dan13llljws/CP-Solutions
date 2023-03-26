#include <stdio.h>
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, m, t, tmp, in[MM], out[MM], head[MM], nxt[MM], to[MM], fa[MM], dep[MM], hvy[MM], h[MM], seg[MM<<2], lz[MM<<2];
int dfs(int src){
    int cur, mx = 0, ret = 1;
    for (int i = head[src]; i; i = nxt[i]){
        dep[to[i]] = dep[src] + 1, ret += cur = dfs(to[i]);
        if (cur > mx) mx = cur, hvy[src] = to[i];
    } return ret;
}
void hld(int src, int hd){
    h[src] = hd, in[src] = ++t;
    if (hvy[src] != -1) hld(hvy[src], hd);
    for (int i = head[src]; i; i = nxt[i])
        if (to[i] != hvy[src]) hld(to[i], to[i]);
    out[src] = t;
}
void push_down(int i, int l1, int r1){
    if (lz[i] == -1) return;
    int mid = (l1 + r1) >> 1; lz[lc] = lz[rc] = lz[i]; 
    seg[lc] = lz[i] * (mid + 1 - l1), seg[rc] = lz[i] * (r1 - mid), lz[i] = -1;
}
int get(int i, int l, int r, int v, int l1 = 1, int r1 = n){
    if (l == l1 && r == r1){tmp = seg[i], seg[i] = (r1 - l1 + 1) * v, lz[i] = v; return tmp;}
    int ret = 0, mid = (l1 + r1) >> 1; push_down(i, l1, r1);
    if (r <= mid) ret = get(lc, l, r, v, l1, mid);
    else if (l > mid) ret = get(rc, l, r, v, mid + 1, r1);
    else ret = get(lc, l, mid, v, l1, mid) + get(rc, mid + 1, r, v, mid + 1, r1);
    seg[i] = seg[lc] + seg[rc]; return ret;
}
int qry(int u){
    int ret = 0;
    for (; u != -1; u = fa[h[u]]) ret += get(1, in[h[u]], in[u], 1);
    return ret;
}
int main(){
    n = re, hvy[0] = fa[0] = -1;
    for (int i = 1; i < n; i++) hvy[i] = -1, fa[i] = re, nxt[i] = head[fa[i]], to[i] = i, head[fa[i]] = i;
    dfs(0), hld(0, 0), m = re; char c[10];
    while(m--){
        scanf("%s", c); int x = re;
        if (c[0] == 'i') printf("%d\n", dep[x] - qry(x) + 1);
        else printf("%d\n", get(1, in[x], out[x], 0));
    }
}
