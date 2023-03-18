#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<bool> vis(n + 1);
	while(m--){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	vector<int> c;
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			queue<int> q;
			vis[i] = 1;
			q.push(i);
			c.push_back(i);
			while(!q.empty()){
				int x = q.front(); q.pop();
				for (int v : adj[x])
					if (!vis[v]) 
						vis[v] = 1, q.push(v);
			}
			ans++;
		}
	}
	cout << ans - 1 << '\n';
	for (int i = 1; i < ans; i++)
		cout << c[i - 1] << ' ' << c[i] << '\n';
}
