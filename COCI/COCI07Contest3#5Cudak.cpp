#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, dp[20][135][2][2], dp2[20][135][2][2], pw[20]; int s;
ll rec(int pos, int sum, bool less, bool great){
	if (!pos){if (sum == s){dp2[pos][sum][less][great] = 0; return 1;}return 0;}
	ll &ret = dp[pos][sum][less][great]; ll &tmp = dp2[pos][sum][less][great];
	if (ret != -1) return ret;
	ret = 0; 
	int mn = great ? 0: a / pw[pos - 1] % 10, mx = less ? 9 : b / pw[pos - 1] % 10;
	for (int i = mn; i <= mx; i++){
		ll x = rec(pos - 1, sum + i, less || i < mx, great || i > mn);
		if (x) tmp = min(tmp, i * pw[pos - 1] + dp2[pos - 1][sum + i][less || i < mx][great || i > mn]), ret += x;
	}
	return ret;
}
int main(){
	scanf("%lld%lld%d", &a, &b, &s);
	pw[0] = 1; memset(dp, -1, sizeof dp); memset(dp2, 0x3f, sizeof dp2);
	for (int i = 1; i < 20; i++) pw[i] = pw[i - 1] * 10;
	ll ans = rec(log10(b) + 1, 0, 0, 0);
	printf("%lld\n%lld\n", ans, dp2[(int)log10(b) + 1][0][0][0]);
}
