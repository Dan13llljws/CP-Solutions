#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> dp(x + 1);
	vector<int> w(n), v(n);
	for (int &y : w) cin >> y;
	for (int &y : v) cin >> y;
	for (int i = 0; i < n; i++)
		for (int j = x; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[x] << '\n';
}


