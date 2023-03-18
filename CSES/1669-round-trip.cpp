#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
vector<bool> vis(MM);
vector<int> st;
vector<vector<int>> adj(MM);
bool dfs(int src, int par){
	if (vis[src]){
		int start = 0;
		while(st[start] != src) start++;
		cout << st.size() - start << '\n';
		for (int i = start; i < (int)st.size(); i++) 
			cout << st[i] << ' ';
		return 1;
	}
	vis[src] = 1;
	for (int v : adj[src]){
		if (v == par) continue;
		st.push_back(v);
		if (dfs(v, src)) return 1;
		st.pop_back();
	}
	return 0;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bool flag = 0;
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			st.push_back(i);
			flag |= dfs(i, 0);
			st.pop_back();
		}
		if (flag) break;
	}
	if (!flag) cout << "IMPOSSIBLE\n";
}
