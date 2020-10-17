#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
const int mod = 1e9 + 7, MM = 2e5 + 5;
int h, w, n, fact[MM], inv[MM], dp[3005];
pair<int, int> c[3005];
int fpow(int a, int b){
	int ret = 1;
	while(b){
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod, b >>= 1;
	}
	return ret;
}
int choose(int a, int b){return 1LL * fact[a] * inv[b] % mod * inv[a - b] % mod;}
int main(){
	h = read() - 1, w = read() - 1, n = read();
	for (int i = 0; i < n; i++) c[i] = {read() - 1, read() - 1};
	sort(c, c + n); c[n] = {h, w};
	fact[0] = inv[0] = 1; int t = h + w + 2;
	for (int i = 1; i <= t; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
	inv[t] = fpow(fact[t], mod - 2);
	for (int i = t - 1; i; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
	for (int i = 0; i <= n; i++){
		dp[i] = choose(c[i].first + c[i].second, c[i].second);
		for (int j = 0; j < i; j++)
			if (c[j].first <= c[i].first && c[j].second <= c[i].second)
				dp[i] = (dp[i] - 1LL * dp[j] * choose(c[i].first - c[j].first + c[i].second - c[j].second, c[i].second - c[j].second) % mod + mod) % mod;
	}
	printf("%d", dp[n]);
}
