#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	if (n == 1) return cout << 0 << '\n', 0;
	vector<vector<pair<int,int>>> adj(n);
	vector<int> a(m), b(m);
	for (int i = 0; i < m; i++) {
		int c; cin >> a[i] >> b[i] >> c; a[i]--, b[i]--;
		adj[a[i]].emplace_back(c, i);
		adj[b[i]].emplace_back(c, i);
	}
	vector<vector<pair<int,int>>> edj(m);
	for (int i = 0; i < n; i++) {
		ranges::sort(adj[i]);
		for (int j = 1; j < adj[i].size(); j++) {
			const auto &[w1, v1] = adj[i][j - 1];
			const auto &[w2, v2] = adj[i][j];
			edj[v1].emplace_back(v2, w2 - w1);
			edj[v2].emplace_back(v1, w2 - w1);
		}
	}

	priority_queue<pair<ll,int>> q;
	vector<ll> d(m, 1e18);
	for (const auto &[w, i] : adj[0]) {
		d[i] = w;
		q.push({-w, i});
	}
	while(q.size()) {
		auto [dist, u] = q.top(); q.pop();
		if (dist != -d[u]) continue;
		if (a[u] == n - 1 || b[u] == n - 1) {
			cout << d[u] << '\n';
			return 0;
		}
		for (const auto &[v, w] : edj[u]) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({-d[v], v});
			}
		}
	}
}