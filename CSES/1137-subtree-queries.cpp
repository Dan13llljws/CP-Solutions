#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
vector<int> in(MM), out(MM); 
vector<long long> bit(MM);
vector<vector<int>> adj(MM);
int n, t;
void dfs(int src, int par){
	in[src] = ++t;
	for (int v : adj[src])
		if (v != par) dfs(v, src);
	out[src] = t;
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
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> n >> q;
	vector<long long> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		update(in[i], a[i]);
	while(q--){
		int tp;
		cin >> tp;
		if (tp == 1){
			int x, y;
			cin >> x >> y;
			update(in[x], y - a[x]);
			a[x] = y;
		} else {
			int x;
			cin >> x;
			cout << query(out[x]) - query(in[x] - 1) << '\n';
		}
	}
}
