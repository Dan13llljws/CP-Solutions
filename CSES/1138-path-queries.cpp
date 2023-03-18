#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int n, t;
vector<int> in(MM), hvy(MM), fa(MM), head(MM);
vector<long long> bit(MM);
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
}
void update(int x, int v){
	for (; x <= n; x += x & -x)
		bit[x] += v;
}
long long query(int x){
	long long ret = 0;
	for (; x; x -= x & -x)
		ret += bit[x];
	return ret;
}
long long get(int x){
	long long ret = 0;
	while(x){
		ret += query(in[x]) - query(in[head[x]] - 1);
		x = fa[head[x]];
	}
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
		update(in[i], a[i]);
	while(q--){
		int tp;
		cin >> tp;
		if (tp == 1){
			int s, x;
			cin >> s >> x;
			update(in[s], x - a[s]);
			a[s] = x;
		} else {
			int x;
			cin >> x;
			cout << get(x) << '\n';
		}
	}
}
