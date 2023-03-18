#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> M;
#define FOR(i, n) for (int i = 0; i < (n); i++)
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	M a(n, vector<ll>(n));
	while(m--){
		int u, v;
		cin >> u >> v;
		a[--u][--v]++;
	}
	auto mul = [&](M b, M c){
		M ret(n, vector<ll>(n));
		FOR(i, n) FOR(j, n) FOR(i1, n)
			ret[i][i1] = (ret[i][i1] + b[i][j] * c[j][i1]) % mod;
		return ret;
	};
	auto fpow = [&](M b, ll c){
		M ret(n, vector<ll>(n));
		FOR(i, n) ret[i][i] = 1;
		while(c){
			if (c & 1) ret = mul(ret, b);
			b = mul(b, b), c >>= 1;
		}
		return ret;
	};
	a = fpow(a, k);
	cout << a[0][n - 1] << '\n';
}
	



