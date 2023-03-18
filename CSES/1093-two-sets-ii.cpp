#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int fpow(int a, int b){
	int ret = 1;
	while(b){
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod, b >>= 1;
	}
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if (n * (n + 1) % 4){
		cout << 0 << ' ';
		return 0;
	}
	vector<int> dp(n * n + 5);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = n * n; j >= i; j--)
			dp[j] = (dp[j] + dp[j - i]) % mod;
	cout << 1LL * dp[n * (n + 1) / 4] * fpow(2, mod - 2) % mod << '\n';
}


