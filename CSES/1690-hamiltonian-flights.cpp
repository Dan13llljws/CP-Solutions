#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[1<<20][20];
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>(n));
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a][b]++;
	}
	//vector<vector<int>> dp(1 << n, vector<int>(n));
	dp[1][0] = 1;
	for (int mask = 0; mask < (1 << n); mask++)
		for (int i = 0; i < n; i++)
			if (mask >> i & 1)	
				for (int j = 0; j < n; j++)
					if (!(mask >> j & 1)) 
						dp[mask|(1<<j)][j] = (dp[mask|(1<<j)][j] + 1LL * adj[i][j] * dp[mask][i]) % mod;
	cout << dp[(1<<n)-1][n - 1] << '\n';
}
	



