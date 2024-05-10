#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
 
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<vector<int>> adj1(n), adj2(n);
		for (int i = 1; i < n; i++) {
			int a, b; cin >> a >> b; a--, b--;
			adj1[a].push_back(b);
			adj1[b].push_back(a);
		}
		for (int i = 1; i < n; i++) {
			int a, b; cin >> a >> b; a--, b--;
			adj2[a].push_back(b);
			adj2[b].push_back(a);
		}
		vector<ll> hsh1(n), hsh2(n), p(n + 1);
		p[0] = 1;
		for (int i = 1; i <= n; i++) 
			p[i] = p[i - 1] * 4 % mod;
		vector<int> sz(n);
		auto hash_tree = [&](auto self, int src, int par, vector<vector<int>> &adj, vector<ll> &hsh) -> void {
			hsh[src] = sz[src] = 1;
			for (int i = 0; i < (int)adj[src].size(); i++) {
				if (adj[src][i] == par) adj[src].erase(adj[src].begin() + i);
			}
			int m = adj[src].size();
			vector<int> id(m);
			iota(id.begin(), id.end(), 0);
			for (int v : adj[src]) {
				self(self, v, src, adj, hsh);
				sz[src] += sz[v];
			}
			sort(id.begin(), id.end(), [&](int i, int j) {
				return hsh[adj[src][i]] < hsh[adj[src][j]];
			});
			for (int i = 0; i < m; i++) {
				int j = adj[src][id[i]];
				hsh[src] = (hsh[src] * p[sz[j]] + hsh[j]) * 2 % mod;
			}
		};
		hash_tree(hash_tree, 0, 0, adj1, hsh1);
		hash_tree(hash_tree, 0, 0, adj2, hsh2);
		cout << (hsh1[0] == hsh2[0]? "YES" : "NO") << '\n';
	}
}


