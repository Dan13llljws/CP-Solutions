#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
 
int main() {
	string s; cin >> s;
	int n = s.size();
	vector<ll> dp(26);
	for (int i = 0; i < n; i++) 
		dp[s[i] - 'a'] = accumulate(dp.begin(), dp.end(), 1LL) % mod;
	cout << accumulate(dp.begin(), dp.end(), 0LL) % mod << '\n';
}


