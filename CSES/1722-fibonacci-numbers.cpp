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
	M a = {{0, 1}, {1, 1}};
	auto mul = [&](M b, M c){
		M ret;
		ret.resize(2, vector<ll>(2));
		FOR(i, 2) FOR(j, 2) FOR(k, 2)
			ret[i][k] = (ret[i][k] + b[i][j] * c[j][k]) % mod;
		return ret;
	};
	auto fpow = [&](M b, ll c){
		M ret = {{1, 0}, {0, 1}};
		while(c){
			if (c & 1) ret = mul(ret, b);
			b = mul(b, b), c >>= 1;
		}
		return ret;
	};
	a = fpow(a, n);
	cout << a[0][1] << '\n';
}
	


