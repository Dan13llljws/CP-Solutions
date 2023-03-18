#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> fac(n + m);
	fac[0] = 1;
	for (int i = 1; i < n + m; i++) fac[i] = fac[i - 1] * i % mod;
	auto fpow = [&](ll a, ll b){
		ll ret = 1;
		while(b){
			if (b & 1) ret = ret * a % mod;
			a = a * a % mod, b >>= 1;
		}
		return ret;
	};
	auto inv = [&](int x){
		return x ? fpow(fac[x], mod - 2) : 1;
	};
	auto choose = [&](int a, int b){
		return fac[a] * inv(b) % mod * inv(a - b) % mod;
	};
	cout << choose(n + m - 1, n - 1) << '\n';
}
	


