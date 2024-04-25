#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll fpow(ll x, ll k) {
	ll ret = 1;
	while(k) {
		if (k & 1) ret = ret * x % mod;
		x = x * x % mod, k >>= 1;
	} 
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	vector<int> vis(n);
	auto dfs = [&](auto self, int src) -> void {
		vis[src] = 1;
		for (int v : adj[src]) 
			if (!vis[v]) self(self, v);
	};
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) dfs(dfs, i), cnt++;
	}
	cout << fpow(2, m - n + cnt) << '\n';
}
