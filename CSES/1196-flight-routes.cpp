#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int,int>>> adj(n + 1);
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
	vector<vector<ll>> d(n + 1);
	q.push({0, 1});
	while(!q.empty()){
		int src = q.top().second; ll di = q.top().first; q.pop();
		if ((int)d[src].size() >= k) continue;
		d[src].push_back(di);
		for(auto v : adj[src])
			q.push({di + v.first, v.second});
	}
	for (ll x : d[n]) cout << x << ' ';
}
