#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4 + 5;
int n, m, t, d[MM], p[MM], w[MM]; long long ans; vector<pair<int,int>> adj[MM]; priority_queue<pair<int,int>> q;
int dfs(int src){
	for (auto v : adj[src]) w[src] += dfs(v.second);
	ans = max(ans, 1LL * (d[src] - t) * w[src]);
	return w[src];
}
int main(){
	//freopen("shortcut.in", "r", stdin); freopen("shortcut.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++) scanf("%d", w + i);
	for (int i = 0, a, b, c; i < m; i++){
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({c, b}), adj[b].push_back({c, a});
	}
	memset(d, 0x3f, sizeof d); d[1] = 0, q.push({0, 1});
	while(!q.empty()){
		int src = q.top().second, dis = -q.top().first; q.pop();
		if (dis > d[src]) continue;
		for (auto v : adj[src])
			if (d[v.second] > d[src] + v.first)
				d[v.second] = d[src] + v.first, p[v.second] = src, q.push({-d[v.second], v.second});
			else if (d[v.second] == d[src] + v.first) p[v.second] = min(p[v.second], src);
	}
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i <= n; i++) adj[p[i]].push_back({0, i});
	dfs(1); printf("%lld\n", ans);
}
	
