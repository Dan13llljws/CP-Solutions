#include "bits/stdc++.h"
using namespace std;

vector<int> label(int n, [[maybe_unused]] int k, vector<int> u, vector<int> v) {
	vector<vector<int>> adj(n);
	for (auto [a, b] : views::zip(u, v)) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> ans(n);
	int t = 0;
	[&](this auto &&self, int src, int par, int dep) -> void {
		if (!dep) ans[src] = t++;
		for (int v : adj[src])
			if (v != par) self(v, src, dep ^ 1);
		if (dep) ans[src] = t++;
	}(0, 0, 0);
	return ans;
}

int find_next_station(int s, int t, vector<int> c) {
	if (c.back() < s) { // c is tin
		if (c.size() > 1 && t >= c[1] && t < s) return *--ranges::upper_bound(c, t);
		else return c[0];
	} else { // c is tout
		if (c.size() > 1 && t > s && t <= c[c.size() - 2]) return *ranges::lower_bound(c, t);
		else return c.back();
	}
}