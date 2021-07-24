#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4 + 5;
int n, m, k, w[MM], d[2][MM]; vector<array<int,2>> adj[MM]; priority_queue<array<int,3>> q;
int main(){
	freopen("dining.in", "r", stdin); freopen("dining.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++){
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({c, b}), adj[b].push_back({c, a});
	}
	for (int i = 0, a, b; i < k; i++) scanf("%d%d", &a, &b), w[a] = max(w[a], b);
	memset(d, 0x3f, sizeof d); d[0][n] = 0; q.push({0, 0, n});
	while(q.size()){
		int src = q.top()[2], vis = q.top()[1], dis = -q.top()[0]; q.pop();
		if (dis > d[vis][src]) continue;
		if (!vis && w[src] && d[1][src] > d[0][src] - w[src])
			d[1][src] = d[0][src] - w[src], q.push({-d[1][src], 1, src});
		for (auto v : adj[src])
			if (d[vis][v[1]] > d[vis][src] + v[0])
				d[vis][v[1]] = d[vis][src] + v[0], q.push({-d[vis][v[1]], vis, v[1]});
	}
	for (int i = 1; i < n; i++)
		puts(d[1][i] <= d[0][i] ? "1" : "0");
}

