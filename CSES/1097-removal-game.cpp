#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
	for (int len = 1; len <= n; len++)
		for (int l = 1, r = len; r <= n; l++, r++){
			if (len == 1) dp[l][r] = a[l] - a[l - 1];
			else dp[l][r] = a[r] -  a[l - 1] - min(dp[l + 1][r], dp[l][r - 1]);
		}
	cout << dp[1][n] << '\n';
}



