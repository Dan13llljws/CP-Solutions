#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(102));
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		if (!a){
			for (int j = 1; j <= m; j++){
				if (i == 1) dp[i][j] = 1;
				else dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % mod + dp[i - 1][j + 1]) % mod;
			}
		} else if (i == 1) dp[i][a] = 1;
		else dp[i][a] = ((dp[i - 1][a - 1] + dp[i - 1][a]) % mod + dp[i - 1][a + 1]) % mod;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) ans = (ans + dp[n][i]) % mod;
	cout << ans << '\n';
}


