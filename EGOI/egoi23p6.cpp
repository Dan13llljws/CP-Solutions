#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, F; ll T; cin >> n >> F >> T;
	vector<vector<ll>> dp(F + 1, vector<ll>(n * (n + 1) / 2 + 1, -1e9));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		for (int j = i * (i + 1) / 2; j >= i; j--)
			for (int k = F; k; k--)
				dp[k][j] = max(dp[k][j], dp[k - 1][j - i] + x);
	} 
	for (int i = 0; i <= n * (n + 1) / 2; i++)
		if (dp[F][i] >= T) return cout << max(0, i - F * (F + 1) / 2) << endl, 0;
	cout << "NO\n";
}

