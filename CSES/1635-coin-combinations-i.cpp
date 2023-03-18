#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> dp(x + 1);
	dp[0] = 1;
	vector<int> c(n);
	for (int &v : c) cin >> v;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < n; j++)
			if (i + c[j] <= x) dp[i + c[j]] = (dp[i + c[j]] + dp[i]) % mod;
	cout << dp[x] << '\n';
}
