#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
vector<vector<pair<int, int>>> adj1(MM), adj2(MM);
vector<long long> dist1(MM), dist2(MM);
void dijkstra(int src, vector<long long> &dist, vector<vector<pair<int, int>>> adj){
	fill(dist.begin(), dist.end(), 1e18);
	dist[src] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
	q.push({0, src});
	while(!q.empty()){
		int cur = q.top().second;
		long long d = q.top().first;
		q.pop();
		if (d > dist[cur]) continue;
		for (auto v : adj[cur])
			if (dist[v.second] > dist[cur] + v.first){
				dist[v.second] = dist[cur] + v.first;
				q.push({dist[v.second], v.second});
			}
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj1[a].push_back({c, b});
		adj2[b].push_back({c, a});
	}
	dijkstra(1, dist1, adj1);
	dijkstra(n, dist2, adj2);
	long long ans = 1e18;
	for (int i = 1; i <= n; i++)
		for (auto v : adj1[i])
			ans = min(ans, dist1[i] + v.first / 2 + dist2[v.second]);
	cout << ans << '\n';
}
