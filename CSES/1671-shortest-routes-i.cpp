#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<long long> dist(n + 1, 1e18);
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
	q.push({0, 1});
	dist[1] = 0;
	while(!q.empty()){
		int src = q.top().second; 
		long long d = q.top().first;
		q.pop();
		if (d > dist[src]) continue;
		for (auto v : adj[src]){
			if (dist[v.second] > dist[src] + v.first){
				dist[v.second] = dist[src] + v.first;
				q.push({dist[v.second], v.second});
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
}
