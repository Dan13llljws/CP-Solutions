#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<array<int, 3>> a(n);
	for (auto &x : a) cin >> x[0] >> x[1] >> x[2];
	sort(a.begin(), a.end(), [](auto x, auto y){return x[1] < y[1];});
	vector<pair<int, ll>> dp(n + 1);
	for (int i = 1; i <= n; i++){
		dp[i] = {a[i - 1][1], dp[i - 1].second};
		int t = lower_bound(dp.begin(), dp.begin() + i, make_pair(a[i - 1][0], 0LL)) - dp.begin() - 1;
		dp[i].second = max(dp[i].second, dp[t].second + a[i - 1][2]);
	}
	cout << dp[n].second << '\n';
}

