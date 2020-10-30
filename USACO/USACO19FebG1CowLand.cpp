#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
const int mod = 1e9 + 7, MM = 1e5 + 5;
struct node{int l, r, v;}seg[MM<<2];
int n, q, t, w[MM], head[MM], hvy[MM], ord[MM], in[MM], out[MM], fa[MM]; vector<int> adj[MM];
void build(int i, int l, int r){
	seg[i].l = l, seg[i].r = r;
	if (l == r){seg[i].v = w[ord[l]]; return;}
	int mid = l + r >> 1;
	build(lc, l, mid); build(rc, mid + 1, r);
	seg[i].v = seg[lc].v ^ seg[rc].v;
}
void update(int i, int p, int v){
	if (seg[i].l == p && seg[i].r == p){seg[i].v = v; return;}
	int mid = seg[i].l + seg[i].r >> 1;
	if (p <= mid) update(lc, p, v);
	else update(rc, p, v);
	seg[i].v = seg[lc].v ^ seg[rc].v;
}
int query(int i, int l, int r){
	if (seg[i].l == l && seg[i].r == r) return seg[i].v;
	int mid = seg[i].l + seg[i].r >> 1;
	if (r <= mid) return query(lc, l, r);
	if (l > mid) return query(rc, l, r);
	return query(lc, l, mid) ^ query(rc, mid + 1, r);
}
int dfs(int src){
	int mx = 0, cur, ret = 1;
	for (int v : adj[src]){
		if (v == fa[src]) continue;
		fa[v] = src, ret += cur = dfs(v);
		if (cur > mx) hvy[src] = v, mx = cur;
	}
	return ret;
}
void hld(int src, int h){
	in[src] = ++t, ord[t] = src, head[src] = h;
	if (hvy[src]) hld(hvy[src], h);
	for (int v : adj[src])
		if (v != fa[src] && v != hvy[src]) hld(v, v);
	out[src] = t;
}
bool anc(int u, int v){return in[u] <= in[v] && out[u] >= out[v];}
int get(int a, int b){
	int ret = 0;
	while(head[a] != head[b]){
		if (anc(head[b], head[a])) swap(a, b);
		ret ^= query(1, in[head[b]], in[b]);
		b = fa[head[b]];
	}
	if (anc(b, a)) swap(a, b);
	return ret ^ query(1, in[a], in[b]);
}
int main(){
	n = re, q = re;
	for (int i = 1; i <= n; i++) w[i] = re;
	for (int i = 1; i < n; i++){
		int a = re, b = re;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1); hld(1, 1); build(1, 1, n);
	while(q--){
		int tp = re, a = re, b = re;
		if (tp == 1) update(1, in[a], b);
		else printf("%d\n", get(a, b));
	}
}

