#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
 * dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum(l, r))
 * best[l][r - 1] <= best[l][r] <= best[l + 1][r]
 */
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<ll> a(n + 2);
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, 1e18));
	vector<vector<ll>> best(n + 2, vector<ll>(n + 2));
	for (int len = 1; len <= n; len++) {
		for (int l = 1, r = len; r <= n; l++, r++) {
			if (len == 1) { dp[l][r] = 0, best[l][r] = l; continue; }
			for (int i = best[l][r - 1]; i <= best[l + 1][r]; i++) {
				ll cost = dp[l][i] + dp[i + 1][r] + a[r] - a[l - 1];
				if (cost < dp[l][r]) dp[l][r] = cost, best[l][r] = i;
			}
		}
	}	
	cout << dp[1][n] << '\n';
}
