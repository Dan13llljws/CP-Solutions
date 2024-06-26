#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<int> ans(n);
	priority_queue<pair<int,int>> q;
	for (int i = 0; i < n; i++) cin >> ans[i], q.push({ans[i], i});
	vector<vector<pair<int,int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		adj[a].push_back({b, c}), adj[b].push_back({a, c});
	}
	while(q.size()) {
		auto [x, u] = q.top(); q.pop();
		if (x < ans[u]) continue;
		for (auto [v, w] : adj[u]) {
			if (ans[v] < ans[u] - w) {
				ans[v] = ans[u] - w;
				q.push({ans[v], v});
			}
		}
	}
	for (int x : ans) cout << x << '\n';
}
