#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define pb push_back
#define lc i << 1 
#define rc i << 1 | 1
const int mod = 1e9 + 7, base = 131, MM = 2e5 + 5;
struct node{int l, r, v;}seg[MM << 2];
int n, m, rt, t, k[MM], idx[MM], B[MM], C[MM], L[MM], in[MM], out[MM]; ll w[MM], ans;
vector<int> adj[MM];
void push_up(int i){
	if (C[seg[lc].v] > C[seg[rc].v]) seg[i].v = seg[lc].v;
	else seg[i].v = seg[rc].v;
}
void build(int i, int l, int r){
	seg[i].l = l, seg[i].r = r;
	if (l == r){
		seg[i].v = idx[l]; return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid); build(rc, mid + 1, r);
	push_up(i);
}
void update(int i, int pos){
	if (seg[i].l == pos && seg[i].r == pos){
		seg[i].v = 0; return;
	}
	int mid = seg[i].l + seg[i].r >> 1;
	if (pos <= mid) update(lc, pos);
	else update(rc, pos);
	push_up(i);
}
int query(int i, int l, int r){
	if (seg[i].l == l && seg[i].r == r) return seg[i].v;
	int mid = seg[i].l + seg[i].r >> 1;
	if (r <= mid) return query(lc, l, r);
	if (l > mid) return query(rc, l, r);
	int a = query(lc, l, mid), b = query(rc, mid + 1, r);
	if (C[a] > C[b]) return a;
	return b;
}
void dfs(int src){
	in[src] = ++t, idx[t] = src;
	for (int v : adj[src]) dfs(v);
	out[src] = t;
}
void dfs2(int src){
	w[src] = C[src], k[src] = 1;
	for (int v : adj[src]){
		dfs2(v);
		w[src] += w[v], k[src] += k[v];
	}
	while(w[src] > m){
		int id = query(1, in[src], out[src]);
		update(1, in[id]);
		k[src]--, w[src] -= C[id], C[id] = 0;
	}
	ans = max(ans, 1LL * L[src] * k[src]);
}
int main(){
	n = re, m = re;
	for (int i = 1; i <= n; i++){
		B[i] = re, C[i] = re, L[i] = re;
		if (B[i]) adj[B[i]].pb(i);
		else rt = i;
	}
	dfs(rt); build(1, 1, n); dfs2(rt);
	pr(ans);
	return 0;
}
