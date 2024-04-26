#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
 * dp[i][j] = min(dp[i - 1][k - 1], cost(k, j))
 * best[i][j] <= best[i][j + 1]
 */
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<ll> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i], b[i] = a[i] * i;
		a[i] += a[i - 1], b[i] += b[i - 1];
	}
	vector<vector<ll>> cost(n + 2, vector<ll>(n + 2, 1e18));
	for (int l = 1; l <= n; l++) {
		// sum |a - b| => sum cj*j - sum ci*i
		for (int r = l, i = l; r <= n; r++) {
			auto next = [&](int j) {
				return b[r] + b[l - 1] - 2 * b[j] - (a[r] + a[l - 1] - 2 * a[j]) * j;
			};
			cost[l][r] = next(i);
			while(i < r && next(i + 1) < cost[l][r]) cost[l][r] = next(++i);
		}
	}
	vector<ll> dp(n + 1, 1e18), new_dp(n + 1, 1e18);
	dp[0] = 0;
	auto solve = [&](auto self, int l, int r, int ql, int qr) -> void {
		if (l > r) return;
		int mid = (l + r) >> 1;
		int best = ql;
		for (int i = ql; i <= qr; i++) 
			if (dp[i] + cost[i + 1][mid] < new_dp[mid]) 
				new_dp[mid] = dp[i] + cost[i + 1][mid], best = i;
		self(self, l, mid - 1, ql, best);
		self(self, mid + 1, r, best, qr);
	};
	for (int i = 0; i < k; i++) {
		solve(solve, 1, n, 0, n - 1);
		dp = new_dp, new_dp.assign(n + 1, 1e18);
	}
	cout << dp[n] << '\n';
}
