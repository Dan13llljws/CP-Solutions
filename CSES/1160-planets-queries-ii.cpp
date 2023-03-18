#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> t(n + 1);
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> t[i];
		adj[t[i]].push_back(i);
	}
	vector<int> dep(n + 1), p(n + 1), in(n + 1), out(n + 1), rt(n + 1), pos(n + 1);
	int cnt = 0, tt = 0;
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
		for (int j = 0; j < sz.back(); j++){
			pos[cycle[j]] = j;
			function<void(int)> dfs = [&](int src){
				vis[src] = 1;
				in[src] = ++tt;
				rt[src] = cycle[j];
				for (int v : adj[src]){
					if (p[v]) continue;
					dep[v] = dep[src] + 1;
					p[v] = p[src];
					dfs(v);
				}
				out[src] = tt;
			};
			dfs(cycle[j]);
		}
	}
	auto anc = [&](int u, int v){
		return in[u] <= in[v] && out[u] >= out[v];
	};
	while(q--){
		int a, b;
		cin >> a >> b;
		if (dep[b]){
			if (anc(b, a)) cout << dep[a] - dep[b] << '\n';
			else cout << -1 << '\n';
		} else {
			if (p[a] != p[b]) cout << -1 << '\n';
			else cout << (pos[b] - pos[rt[a]] + sz[p[a]]) % sz[p[a]] + dep[a] << '\n';
		}
	}
			
}
		
		

