#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, 1e18));
	for (int i = 0; i < m; i++){
		int a, b, c;
		 cin >> a >> b >> c;
		 dist[a][b] = dist[b][a] = min(dist[a][b], 1LL * c);
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	while(q--){
		int a, b;
		cin >> a >> b;
		if (dist[a][b] == 1e18) 
			cout << -1 << '\n';
		else 
			cout << dist[a][b] << '\n';
	}
}
