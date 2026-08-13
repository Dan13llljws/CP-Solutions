#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const int MOD = 998244353;

int dep(int x) { return 32 - __builtin_clz(x); }
void add(ll &x, ll y) { x = (x + y) % MOD; }
bool is_anc(int u, int v) {
	int i = dep(v) - dep(u);
	return (v >> i) == u;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<vector<pair<int,int>>> adj(1 << n);
	for (int i = 2; i < (1 << n); i++) {
		int w; cin >> w;
		adj[i].emplace_back(i / 2, w);
	}
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}

	auto subtree_size = [&](int u) -> int { return (1 << (n - dep(u) + 1)) - 1; };

	vector<ll> d(1 << n, 1e18), w(1 << n);
	ll ans = 0;
	for (int i = 2; i < (1 << n); i++) 
		w[i] = adj[i][0].second * 1LL * subtree_size(i) % MOD;
	for (int i = (1 << n) - 1; i > 1; i--) add(w[i / 2], w[i]);	// calculate up edge contribution

	auto traverse_subtree = [&](int src, auto f) -> void {
		for (int l = src, size = 1; l < (1 << n); l <<= 1, size <<= 1)
			for (int j = l; j < l + size; j++) f(j);
	};

	[&](this auto self, int root) -> void {
		if (dep(root) == n) return;
		priority_queue<pair<int,int>> q;

		traverse_subtree(root, [&](int x) { 
			if (d[x] != 1e18) d[x] += adj[root][0].second, q.emplace(-d[x], x); 
		});
		d[root] = 0;
		q.emplace(0, root);
		while(q.size()) {
			auto [dis, u] = q.top(); q.pop();
			if (-dis > d[u]) continue;
			for (auto [v, w] : adj[u])
				if (is_anc(root, v) && d[v] > d[u] + w)
					d[v] = d[u] + w, q.emplace(-d[v], v);
		}

		ll lsum = 0, rsum = 0, lcnt = 1, rcnt = 1;
		traverse_subtree(root * 2, [&](int x) {
			if (d[x] != 1e18) add(lsum, d[x]), lcnt++;
		});
		traverse_subtree(root * 2 + 1, [&](int x) {
			if (d[x] != 1e18) add(rsum, d[x]), rcnt++;
		});
		add(ans, lsum * (subtree_size(root * 2 + 1) + 1));
		add(ans, w[root * 2] * rcnt);
		add(ans, rsum * (subtree_size(root * 2) + 1));
		add(ans, w[root * 2 + 1] * lcnt);
		self(root * 2), self(root * 2 + 1);
	}(1);

	cout << ans << '\n';
}