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
 
		auto get_w = [&](auto self, int src, int par, const vector<vector<int>> &adj) -> int {
			sz[src] = 1;
			for (int v : adj[src])
				if (v != par) sz[src] += self(self, v, src, adj);
			return sz[src];
		};
 
		auto get_c = [&](auto self, int src, int par, const vector<vector<int>> &adj) -> int {
			for (int v : adj[src])
				if (v != par && 2 * sz[v] >= n) return self(self, v, src, adj);
			return src;
		};
 
		get_w(get_w, 0, 0, adj1);
		int c1 = get_c(get_c, 0, 0, adj1);
		get_w(get_w, 0, 0, adj2);
		int c2 = get_c(get_c, 0, 0, adj2);
		int c3 = -1;
		for (int v : adj2[c2]) {
			if (2 * sz[v] >= n) c3 = v;
		}
 
		auto hash_tree = [&](auto self, int src, int par, vector<vector<int>> &adj, vector<ll> &hsh) -> void {
			hsh[src] = sz[src] = 1;
			vector<int> ch;
			for (int v : adj[src]) {
				if (v == par) continue;
				self(self, v, src, adj, hsh);
				ch.push_back(v), sz[src] += sz[v];
			}
			sort(ch.begin(), ch.end(), [&](int i, int j) {
					return hsh[i] < hsh[j];
			});
			for (int c : ch) {
				hsh[src] = (hsh[src] * p[sz[c]] + hsh[c]) % mod;
			}
			hsh[src] = hsh[src] * 2 % mod;
		};
 
		hash_tree(hash_tree, c1, c1, adj1, hsh1);
		hash_tree(hash_tree, c2, c2, adj2, hsh2);
		bool same = hsh1[c1] == hsh2[c2];
		if (c3 != -1) {
			hash_tree(hash_tree, c3, c3, adj2, hsh2);
			same |= hsh1[c1] == hsh2[c3];
		}
		cout << (same ? "YES" : "NO") << '\n';
	}
}

