#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, x, p[12], dp[12][10005][2][2]; char d[10]; bool f[10];
ll rec(int i, int rem, bool less, bool lead, ll v){
	ll &ret = dp[i][rem][less][lead];
	if (ret != -1) return ret;
	if (!i) return !rem;
	ret = 0; int up = less ? 9 : v / p[i - 1] % 10;
	for (int dig = 0; dig <= up; dig++){
		if (!f[dig] && (dig || !lead)) continue;
		ret += rec(i - 1, (rem + dig * p[i - 1]) % x, less || (dig < up), lead && !dig, v);
	}
	return ret;
}
int main(){
	scanf("%lld%lld%lld %s", &x, &a, &b, d);
	for (int i = 0; d[i]; i++) f[d[i] - '0'] = 1;
	if (x >= 1e4){
		ll ans = 0;
		for (ll i = x; i <= b; i += x){
			ll tmp = i; bool wrk = 1;
			while(tmp){
				if (!f[tmp % 10]) wrk = 0;
				tmp /= 10;
			}
			ans += wrk;
		}
		return 0 * printf("%lld\n", ans);
	}
	p[0] = 1;
	for (int i = 1; i < 12; i++) p[i] = p[i - 1] * 10;
	memset(dp, -1, sizeof dp); b = rec(log10(b) + 1, 0, 0, 1, b);
	memset(dp, -1, sizeof dp); a = a == 1 ? 1 : rec(log10(a - 1) + 1, 0, 0, 1, a - 1);
	printf("%lld\n", b - a);
}
