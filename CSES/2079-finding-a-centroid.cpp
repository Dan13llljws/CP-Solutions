#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	vector<int> w(n + 1);
	function<int(int,int)> get_wt = [&](int src, int par){
		w[src] = 1;
		for (int v : adj[src])
			if (v != par) w[src] += get_wt(v, src);
		return w[src];
	};
	function<int(int,int)> get_cent = [&](int src, int par){
		for (int v : adj[src])
			if (v != par && w[v] > n / 2) return get_cent(v, src);
		return src;
	};
	get_wt(1, 1);
	cout << get_cent(1, 1) << '\n';
}	

