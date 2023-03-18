#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; 
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> dist(n + 1, 1e9), pre(n + 1);
	dist[1] = 1;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int src = q.front(); q.pop();
		for (int v : adj[src]){
			if (dist[v] > dist[src] + 1){
			dist[v] = dist[src] + 1;
				pre[v] = src;
				q.push(v);
			}
		}
	}
	if (dist[n] == 1e9) cout << "IMPOSSIBLE\n";
	else{
		vector<int> ans;
		for (int i = n; i; i = pre[i])
			ans.push_back(i);
		reverse(ans.begin(), ans.end());
		cout << dist[n] << '\n';
		for (int x : ans)
			cout << x << ' ';
	}
}
