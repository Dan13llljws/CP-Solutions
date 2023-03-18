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
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++){
		if (!ans[i]){
			queue<int> q;
			q.push(i);
			ans[i] = 1;
			while(!q.empty()){
				int src = q.front(); q.pop();
				for (int v : adj[src]){
					if (ans[v] == ans[src]){
						cout << "IMPOSSIBLE\n";
						return 0;
					} else if (!ans[v]) { 
						ans[v] = ans[src] == 1 ? 2 : 1;
						q.push(v);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) 
		cout << ans[i] << ' ';
}
