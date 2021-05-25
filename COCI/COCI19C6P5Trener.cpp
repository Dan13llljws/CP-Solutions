#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, base = 131;
int n, k; ll ans, p[55], h[55]; char s[55]; unordered_map<ll, ll> dp, dp2;
ll get(int l, int r){return (h[r] - (h[l - 1] * p[r - l + 1] % mod) + mod) % mod;}
int main(){
	p[0] = 1;
	for (int i = 1; i <= 50; i++) p[i] = p[i - 1] * base % mod;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++){
		scanf("%s", s + 1);
		dp[s[1] - 'a' + 1] += 1;
	}
	for (int i = 2; i <= n; i++){
		dp2.clear();
		for (int j = 0; j < k; j++){
			scanf("%s", s + 1);
			for (int a = 1; a <= i; a++) h[a] = (h[a - 1] * base + s[a] - 'a' + 1) % mod;
			if (get(1, i - 1) != get(2, i)) dp2[h[i]] = (dp2[h[i]] + dp[get(1, i - 1)] + dp[get(2, i)]) % mod;
			else dp2[h[i]] = (dp2[h[i]] + dp[get(1, i - 1)]) % mod;
		}
		swap(dp, dp2);
	}
	for (auto x : dp) ans = (ans + x.second) % mod;
	printf("%lld", ans);
}

