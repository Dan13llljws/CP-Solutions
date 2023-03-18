#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	vector<ll> fac(s.size() + 1);
	vector<int> f(26);
	for (int i = 0; i < (int)s.size(); i++)
		f[s[i] - 'a']++;
	fac[0] = 1;
	for (int i = 1; i <= (int)s.size(); i++) fac[i] = fac[i - 1] * i % mod;
	auto fpow = [&](ll a, ll b){
		ll ret = 1;
		while(b){
			if (b & 1) ret = ret * a % mod;
			a = a * a % mod, b >>= 1;
		}
		return ret;
	};
	ll ans = fac[s.size()];
	for (int i = 0; i < 26; i++)
		if (f[i]) ans = ans * (fpow(fac[f[i]], mod - 2)) % mod;
	cout << ans << '\n';
}
	

