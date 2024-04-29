#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll fpow(ll x, ll k) {
	ll ret = 1;
	while(k) {
		if (k & 1) ret = ret * x % mod;
		x = x * x % mod, k >>= 1;
	}
	return ret;
}
int main() {
	ll n; cin >> n;
	ll ans = 0;
	ans += fpow(2, n * n);
	if (n & 1) {
		ans += fpow(2, n * n / 2) * 2;
		ans += fpow(2, n * n / 4) * 4;
	} else {
		ans += fpow(2, n * n / 2);
		ans += fpow(2, n * n / 4) * 2;
	}
	ans %= mod;
	ans = ans * fpow(4, mod - 2) % mod;
	cout << ans << '\n';
}
