#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> dp(m + 1, 1e9);
	dp[0] = 0;
	for (int i = 0; i < n; i++){
		int w;
		cin >> w;
		for (int j = w; j <= m; j++)
			dp[j] = min(dp[j], dp[j - w] + 1);
	}
	cout << (dp[m] == 1e9 ? -1 : dp[m]) << '\n';
}
