#include <bits/stdc++.h>
using namespace std;
const int MM = 5005, mod = 1e9 + 7;
int n, m, k, ans = 1, s[MM], t[MM], dp[MM], cnt[MM], f[26];
int fpow(int a, int b){
	int ret = 1;
	while(b){
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod, b >>= 1;
	}
	return ret;
}
int main(){
	//freopen("poetry.in", "r", stdin); freopen("poetry.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k); dp[0] = 1;
	for (int i = 0; i < n; i++) scanf("%d%d", s + i, t + i);
	for (int i = 1; i < k; i++)
		for (int j = 0; j < n; j++)
			if (s[j] <= i) dp[i] = (dp[i] + dp[i - s[j]]) % mod;
	for (int i = 0; i < n; i++) cnt[t[i]] = (cnt[t[i]] + dp[k - s[i]]) % mod;
	for (char x; m--; ) scanf(" %c", &x), f[x - 'A']++;
	for (int i = 0; i < 26; i++) {
		int tmp = 0;
		if (!f[i]) continue;
		for (int j = 1; j <= n; j++)
			if (cnt[j]) tmp = (tmp + fpow(cnt[j], f[i])) % mod;
		ans = 1LL * ans * tmp % mod;
	}
	printf("%d\n", ans);
}
	
