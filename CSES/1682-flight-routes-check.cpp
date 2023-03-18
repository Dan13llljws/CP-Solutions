#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	vector<int> in(n + 1), low(n + 1);
	int t = 0, f = 1, cnt = 0;
	function<void(int)> dfs = [&](int src){
		low[src] = in[src] = ++t, cnt++;
		for (int v : adj[src]){
			if (in[v]) low[src] = min(low[src], in[v]);
			else dfs(v), low[src] = min(low[src], low[v]);
		}
		if (src != 1 && low[src] == in[src]) f = 0;
	};
	dfs(1);
	if (cnt == n && f) cout << "YES\n";
	else {
		cout << "NO\n";
		for (int i = 2; i <= n; i++){
			if (!in[i]){
				cout << 1 << ' ' << i << '\n';
				break;
			}
			if (low[i] == in[i]){
				cout << i << ' ' << 1 << '\n';
				break;
			}
		}
	}
		
}
	




