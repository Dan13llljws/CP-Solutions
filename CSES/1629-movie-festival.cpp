#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> p(n);
	for (auto &x : p) cin >> x.first >> x.second;
	vector<pair<int,int>> dp(n + 1);
	sort(p.begin(), p.end(), [](auto a, auto b){return a.second < b.second;});
	for (int i = 1; i <= n; i++){
		dp[i] = {p[i - 1].second, dp[i - 1].second};
		int t = upper_bound(dp.begin(), dp.begin() + i, make_pair(p[i - 1].first, n)) - dp.begin() - 1;
		dp[i].second = max(dp[i].second, dp[t].second + 1);
	}
	cout << dp[n].second << '\n';
}
