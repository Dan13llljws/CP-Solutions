#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(2 * m), rev(2 * m);
	for (int i = 0; i < n; i++){
		int a, b;
		char c, d;
		cin >> c >> a >> d >> b;
		a--, b--, a *= 2, b *= 2;
		if (c == '-') a++;
		if (d == '-') b++;
		adj[a^1].push_back(b);
		adj[b^1].push_back(a);
	}
	for (int i = 0; i < 2 * m; i++)
		for (int v : adj[i]) 
			rev[v].push_back(i);
	vector<int> vis(2 * m), ord, p(2 * m);
	function<void(int)> dfs = [&](int src){
		vis[src] = 1;
		for (int v : adj[src])
			if (!vis[v]) dfs(v);
		ord.push_back(src);
	};
	for (int i = 0; i < 2 * m; i++)
		if (!vis[i]) dfs(i);
	int cnt = 0;
	function<void(int)> dfs1 = [&](int src){
		p[src] = cnt;
		for (int v : rev[src])
			if (!p[v]) dfs1(v);
	};
	reverse(ord.begin(), ord.end());
	for (int x : ord)
		if (!p[x]) cnt++, dfs1(x);
	vector<char> ans;
	for (int i = 0; i < m; i++){
		if (p[2 * i] == p[2 * i + 1]){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		ans.push_back(p[2 * i] > p[2 * i + 1] ? '+' : '-');
	}
	for (char c : ans) cout << c << ' ';
}
		
