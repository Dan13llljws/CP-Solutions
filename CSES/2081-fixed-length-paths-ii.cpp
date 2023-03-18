#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int n, k1, k2, w[MM], vis[MM], bit[MM]; long long ans; vector<int> adj[MM], tmp, reset;
void upd(int x){
	for (; x <= n + 1; x += x & -x)
		bit[x]++, reset.push_back(x);
}
int get(int x){
	int ret = 0;
	for (; x; x -= x & -x) 
		ret += bit[x];
	return ret;
}
int get_w(int src, int par){
	w[src] = 1;
	for (int v : adj[src])
		if (v != par && !vis[v]) w[src]+= get_w(v, src);
	return w[src];
}
int get_cent(int src, int par, int wt){
	for (int v : adj[src])
		if (v != par && !vis[v] && w[v] > wt / 2) return get_cent(v, src, wt);
	return src;
}
void dfs(int src, int par, int d){
	if (d > k2) return;
	if (d >= k1 && d <= k2) ans++;
	ans += get(k2 - d) - get(max(0, k1 - d - 1));
	tmp.push_back(d);
	for (int v : adj[src])
		if (!vis[v] && v != par) dfs(v, src, d + 1);
}
void get_ans(int src){
	for (int v : adj[src]){
		if (vis[v]) continue;
		dfs(v, src, 1);
		for (int x : tmp) upd(x);
		tmp.clear();
	}
	for (int x : reset) bit[x] = 0;
	reset.clear();
}
void decomp(int src){
	get_ans(src);
	vis[src] = 1;
	for (int v : adj[src])
		if (!vis[v]) decomp(get_cent(v, v, get_w(v, v)));
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k1 >> k2;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	decomp(get_cent(1, 1, get_w(1, 1)));
	cout << ans << '\n';
}

