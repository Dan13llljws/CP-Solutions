#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> dp(x + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		int c;
		cin >> c;
		for (int j = c; j <= x; j++)
			dp[j] = (dp[j] + dp[j - c]) % mod;
	}
	cout << dp[x] << '\n';
}

