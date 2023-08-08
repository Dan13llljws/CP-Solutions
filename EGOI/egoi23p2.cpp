#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> lst(n, -1), poor(n, 1), win(m);
	vector<vector<int>> adj(m + 1);
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		if (!poor[y] && lst[y] != -1) adj[i].push_back(lst[y]);
		if (!poor[x]) adj[i].push_back(lst[x]);
		win[i] = x, poor[y] = 1, poor[x] = 0, lst[x] = i;
	}
	for (int i = 0; i < n; i++)
		if (!poor[i]) adj[m].push_back(lst[i]);
	vector<int> f(n), ans(n); 
	auto dfs = [&](auto self, int src, int mx, int id) -> void {
		if (src < m) ans[-id]++;
		for (int v : adj[src]){
			int u = -win[v];
			f[-u] += src - v;
			if (tie(mx, id) < tie(f[-u], u)) self(self, v, f[-u], u);
			else self(self, v, mx, id);
			f[-u] -= src - v;
		}
	};
	dfs(dfs, m, 0, -1);
	for (int x : ans) cout << x << ' ';
	cout << '\n';
}
