#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; string s;
	cin >> n >> s;
	int m = s.size();
	vector<int> f(n);
	for (int i = 1, j = 0; i < m; i++) {
		while(j && s[j] != s[i]) j = f[j - 1];
		if (s[j] == s[i]) j++;
		f[i] = j;
	}
	vector<vector<int>> dfa(m, vector<int>(26));
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < 26; j++) {
			if (j == s[i] - 'A') continue;
			int k = i;
			while(k && j != s[k] - 'A') k = f[k - 1];
			if (j == s[k] - 'A') k++;
			dfa[i][j] = k;
		}
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int c = 0; c < 26; c++) {
				if (c == s[j] - 'A') dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
				else dp[i + 1][dfa[j][c]] = (dp[i + 1][dfa[j][c]] + dp[i][j]) % mod;
			}
		}
	}
	ll ans = 1;
	for (int i = 0; i < n; i++) ans = ans * 26 % mod;
	for (int i = 0; i < m; i++) ans = (ans - dp[n][i] + mod) % mod;
	cout << ans << '\n';
}
	
	
