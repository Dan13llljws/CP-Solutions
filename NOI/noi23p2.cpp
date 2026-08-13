#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int tests; cin >> tests >> tests;

	auto add = [](ll &x, ll y) {
		x += y;
		if (x >= MOD) x -= MOD;
	};

	while(tests--) [&]() {
		int n, m, k; cin >> n >> m >> k;
		vector<int> f(n + 1);
		for (int i = 2; i <= n; i++) cin >> f[i];
		// k = 0, attach or subdivide, E + V
		vector<ll> dp(1 << k);
		dp[0] = 1;
		for (int i = n; i < n + m; i++) {
			vector<ll> ndp(1 << k);
			for (int mask = 0; mask < (1 << k); mask++) {
				if (mask & 1) add(ndp[mask >> 1], dp[mask]);
				else {
					// attach or subdivide
					add(ndp[mask >> 1], dp[mask] * (2 * (i + __builtin_popcount(mask)) - 1) % MOD);
					// attach 2
					for (int j = 1; j <= k; j++)
						if (!(mask >> j & 1))
							add(ndp[(mask | (1 << j)) >> 1], dp[mask] * (__builtin_popcount(mask) + i - 1) % MOD);
				}
			}
			dp = ndp;
		}
		cout << dp[0] << '\n';
	}();
}