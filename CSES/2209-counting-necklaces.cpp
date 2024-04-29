#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
// |X/G| = 1/|G| * \sum_{g \in G} |X^g| where G = <(12...n)> 
// g = (12...n)^k => |X^g| = m^gcd(n,k)
ll fpow(ll x, ll k) {
	ll ret = 1;
	while(k) {
		if (k & 1) ret = ret * x % mod;
		x = x * x % mod, k >>= 1;
	}
	return ret;
}
int main() {
	int n, m; cin >> n >> m;
	ll ans = 0;
	for (int i = 0; i < n; i++) ans = (ans + fpow(m, gcd(n, i))) % mod;
	ans = ans * fpow(n, mod - 2) % mod;
	cout << ans << '\n';
}
