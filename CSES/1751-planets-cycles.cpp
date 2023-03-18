#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> t(n + 1);
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> t[i];
		adj[t[i]].push_back(i);
	}
	vector<int> dep(n + 1), p(n + 1);
	int cnt = 0;
	vector<int> vis(n + 1), sz(1);
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		int x = 0;
		for (int j = i;; j = t[j]){
			if (vis[j]){
				x = j;
				break;
			}
			vis[j] = 1;
		}
		cnt++;
		vector<int> cycle;
		for (int j = x;; j = t[j]){
			cycle.push_back(j); p[j] = cnt;
			if (cycle.size() > 1 && j == x) break;
		}
		cycle.pop_back();
		sz.push_back(cycle.size());
		for (int j : cycle){
			function<void(int)> dfs = [&](int src){
				vis[src] = 1;
				for (int v : adj[src]){
					if (p[v]) continue;
					dep[v] = dep[src] + 1;
					p[v] = p[src];
					dfs(v);
				}
			};
			dfs(j);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << dep[i] + sz[p[i]] << ' ';
}
		
		
