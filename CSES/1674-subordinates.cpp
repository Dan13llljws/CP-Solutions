#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> w;
int dfs(int src){
	w[src] = 1;
	for (int v : adj[src])
		w[src] += dfs(v);
	return w[src];
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	adj.resize(n + 1), w.resize(n + 1);
	for (int i = 2, x; i <= n; i++){
		cin >> x;
		adj[x].push_back(i);
	}
	w[1] = dfs(1);
	for (int i = 1; i <= n; i++)
		cout << w[i] - 1 << ' ';
}
