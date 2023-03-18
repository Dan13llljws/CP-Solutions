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
	vector<int> in(n + 1), low(n + 1), inst(n + 1), st, p(n + 1);
	int t = 0, cnt = 0;
	function<void(int)> dfs = [&](int src){
		low[src] = in[src] = ++t, st.push_back(src), inst[src] = 1;
		for (int v : adj[src]){
			if (!in[v]) dfs(v), low[src] = min(low[src], low[v]);
			else if (inst[v]) low[src] = min(low[src], in[v]);
		}
		if (low[src] == in[src]){
			cnt++;
			while(1){
				int v = st.back();
				st.pop_back();
				p[v] = cnt, inst[v] = 0;
				if (v == src) break;
			}
		}
	};
	for (int i = 1; i <= n; i++)
		if (!in[i]) dfs(i);
	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) cout << p[i] << ' ';
}
