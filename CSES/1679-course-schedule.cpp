#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> in(n + 1);
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}
	queue<int> q;
	vector<int> ans;
	for (int i = 1; i <= n; i++)
		if (!in[i]) q.push(i);
	while(!q.empty()){
		int src = q.front(); q.pop();
		ans.push_back(src);
		for (int v : adj[src])
			if (!--in[v]) q.push(v);
	}
	if ((int)ans.size() != n) cout << "IMPOSSIBLE\n";
	else for (int x : ans) cout << x << ' ';
}
	


