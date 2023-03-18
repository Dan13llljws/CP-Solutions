#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> M;
#define FOR(i, n) for (int i = 0; i < (n); i++)
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	M a;
	a.resize(6, vector<ll>(6));
	FOR(i, 5) a[i + 1][i] = 1;
	FOR(i, 6) a[i][5] = 1;
	auto mul = [&](M b, M c){
		M ret;
		ret.resize(6, vector<ll>(6));
		FOR(i, 6) FOR(j, 6) FOR(k, 6)
			ret[i][k] = (ret[i][k] + b[i][j] * c[j][k]) % mod;
		return ret;
	};
	auto fpow = [&](M b, ll c){
		M ret;
		ret.resize(6, vector<ll>(6));
		FOR(i, 6) ret[i][i] = 1;
		while(c){
			if (c & 1) ret = mul(ret, b);
			b = mul(b, b), c >>= 1;
		}
		return ret;
	};
	a = fpow(a, n + 1);
	cout << a[0][5] << '\n';
}
	


