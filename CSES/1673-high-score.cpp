#include <bits/stdc++.h>
using namespace std;
const int MM = 2505;
vector<bool> vis(MM), vis1(MM);
vector<long long> dist(MM, -1e18);
vector<vector<pair<int, int>>> adj(MM);
vector<vector<int>> rev(MM);
void dfs(int src){
	vis[src] = 1;
	for (auto v : adj[src])
		if (!vis[v.second])
			dfs(v.second);
}
void dfs1(int src){
	vis1[src] = 1;
	for (int v : rev[src])
		if (!vis1[v])
			dfs1(v);
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		rev[b].push_back(a);
	}
	dfs(1); 
	dfs1(n);
	dist[1] = 0;
	for (int t = 0; t < 2; t++)
		for (int i = 0; i < n; i++){
			bool f = 0;
			for (int j = 1; j <= n; j++)
				for (auto v : adj[j])
					if (dist[v.second] < dist[j] + v.first){
						if (vis[v.second] && vis1[v.second])
							f = 1;
						dist[v.second] = dist[j] + v.first;
					}
			if (f && t){
				cout << -1 << '\n';
				return 0;
			}
		}
	cout << dist[n] << '\n';
}
