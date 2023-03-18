#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define lc i << 1
#define rc i << 1 | 1
int n, t;
vector<int> in(MM), out(MM), hvy(MM), fa(MM), head(MM), seg(MM<<2);
vector<vector<int>> adj(MM);
int dfs(int src){
	int cur = 1, mx = 0;
	for (int v : adj[src]){
		if (v == fa[src]) continue;
		fa[v] = src;
		int tmp = dfs(v);
		cur += tmp;
		if (tmp > mx) 	
			mx = tmp, hvy[src] = v;	
	}
	return cur;
}
void hld(int src, int h){
	in[src] = ++t, head[src] = h;
	if (hvy[src])
		hld(hvy[src], h);
	for (int v : adj[src])
		if (v != fa[src] && v != hvy[src]) hld(v, v);
	out[src] = t;
}
bool anc(int u, int v){
	return in[u] <= in[v] && out[u] >= out[v];
}
void upd(int i, int p, int v, int l1 = 1, int r1 = n){
	if (l1 == r1){
		seg[i] = v;
		return ;
	}
	int mid = (l1 + r1) >> 1;
	if (p <= mid) upd(lc, p, v, l1, mid);
	else upd(rc, p, v, mid + 1, r1);
	seg[i] = max(seg[lc], seg[rc]);
}
int qry(int i, int l, int r, int l1 = 1, int r1 = n){
	if (l == l1 && r == r1) return seg[i];
	int mid = (l1 + r1) >> 1;
	if (r <= mid) return qry(lc, l, r, l1, mid);
	if (l > mid) return qry(rc, l, r, mid + 1, r1);
	return max(qry(lc, l, mid, l1, mid), qry(rc, mid + 1, r, mid + 1, r1));
} 
int get(int u, int v){
	int ret = 0;
	for (; head[u] != head[v]; u = fa[head[u]]){
		if (anc(head[u], head[v])) swap(u, v);
		ret = max(ret, qry(1, in[head[u]], in[u]));
	}
	if (anc(v, u)) swap(u, v);
	ret = max(ret, qry(1, in[u], in[v]));
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1); hld(1, 1);
	for (int i = 1; i <= n; i++)	
		upd(1, in[i], a[i]);
	while(q--){
		int tp;
		cin >> tp;
		if (tp == 1){
			int s, x;
			cin >> s >> x;
			upd(1, in[s], x);
		} else {
			int u, v;
			cin >> u >> v;
			cout << get(u, v) << ' ';
		}
	}
}

