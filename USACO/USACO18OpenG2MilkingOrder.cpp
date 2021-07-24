#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, m, t, ans[MM], in[MM]; vector<pair<int,int>> adj[MM*2]; priority_queue<int> q;
bool go(int x){
	memset(in, 0, sizeof in); t = 0; 
	for (int i = 1; i <= n; i++)
		for (auto v : adj[i]) if (v.first < x) in[v.second]++;
	for (int i = 1; i <= n; i++)
		if (!in[i]) q.push(-i);
	while(q.size()){
		int src = -q.top(); q.pop();
		ans[t++] = src;
		for (auto v : adj[src])
			if (v.first < x && !--in[v.second]) q.push(-v.second);
	}
	return t == n;
}
int main(){
	//freopen("milkorder.in", "r", stdin); freopen("milkorder.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int x, p = 0; scanf("%d", &x);
		for (int v; x; x--){
			scanf("%d", &v);
			if (p) adj[p].push_back({i, v});
			p = v;
		}
	}
	int l = 0, r = m;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if (go(mid)) l = mid;
		else r = mid - 1;
	}
	go(l);
	for (int i = 0; i < n; i++) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
}
	
		
		
