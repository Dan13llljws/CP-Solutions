#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<string> g(n);
	for (auto &x : g) cin >> x;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			if (g[i - 1][j - 1] == '*') continue;
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	cout << dp[n][n] << '\n';	
}


