#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<vector<pair<int,int>>> adj(1<<n);
	for (int i = 0; i < (1 << n); i++) adj[i>>1].push_back({i & ((1<<(n-1))-1), i});
	vector<int> ans;
	function<void(int)> dfs = [&](int src){
		while(adj[src].size()){
			auto v = adj[src].back();
			adj[src].pop_back();
			dfs(v.first);
			ans.push_back(v.second);
		}
	};
	dfs(0);
	for (int x : ans) cout << (x & 1);
	for (int i = 0; i < n - 1; i++) cout << 0;
}

