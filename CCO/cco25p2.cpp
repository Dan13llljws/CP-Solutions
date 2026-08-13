#include "bits/stdc++.h"
using namespace std;

using ll = long long;

inline ll h(ll x) { return x * x * x * 1237123 + 19260817; }
inline ll f(ll x) { return h(x<<31>>31) | h(x >> 31); }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> sz(n), pa(n);
	vector<ll> tot(n), hsh(n);
	unordered_map<ll,int> mp, tmp;
	auto dfs = [&](auto self, int src, int par) -> void {
		sz[src] = 1, pa[src] = par;
		for (int v : adj[src]) {
			if (v == par) continue;
			self(self, v, src);
			sz[src] += sz[v];
			tot[src] += tot[v];
			hsh[src] += f(hsh[v]);
		}
		tot[src] += sz[src];
		mp[hsh[src]]++;
	};
	dfs(dfs, 0, 0);

	auto check = [&](auto self, int src, int par, int d) -> void {
		tmp[hsh[src]] += d;
		for (int v : adj[src])
			if (v != par) self(self, v, src, d + 1);
	};

	unordered_set<ll> good_hash;
	for (int i = 0; i < n; i++)
		if (tot[i] + m == n) {
			cout << i << endl;
			tmp.clear();
			check(check, i, pa[i], 1);
			bool good = 1;
			for (const auto &[h, cnt] : tmp) 
				if (cnt > mp[h]) { good = 0; break; }
			if (good)
				good_hash.insert(hsh[i]);
		}
	cout << good_hash.size() << '\n';
}