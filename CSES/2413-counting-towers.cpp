#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	vector<vector<long long>> dp(1e6 + 5, vector<long long>(2));
	dp[1][1] = dp[1][0] = 1;
	for (int i = 2; i <= 1e6; i++){
		dp[i][0] = (dp[i - 1][0] * 4 + dp[i - 1][1]) % mod;
		dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % mod;
	}
	while(t--){
		int n;
		cin >> n;
		cout << (dp[n][0] + dp[n][1]) % mod << '\n';
	}
}
