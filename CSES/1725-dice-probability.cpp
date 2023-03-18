#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	vector<double> dp(6 * n + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		vector<double> dp1(6 * n + 1);
		for (int j = 0; j <= 6 * i; j++)
			for (int k = 1; k <= 6; k++)
				dp1[j + k] += dp[j] * 1 / 6;
		dp = dp1;
	}
	double ans = 0;
	for (int i = a; i <= b; i++) ans += dp[i];
	cout << fixed << setprecision(6) << ans << '\n';
}
	



