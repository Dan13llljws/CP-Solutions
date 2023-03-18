#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> M;
#define FOR(i, n) for (int i = 0; i < (n); i++)
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	M a(n, vector<ll>(n, 2e18));
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		a[u][v] = min(a[u][v], 1LL * w);
	}
	auto mul = [&](M b, M c){
		M ret(n, vector<ll>(n, 2e18));
		FOR(i, n) FOR(j, n) FOR(i1, n)
			ret[i][i1] = min(ret[i][i1], b[i][j] + c[j][i1]);
		return ret;
	};
	auto fpow = [&](M b, ll c){
		M ret(n, vector<ll>(n, 2e18));
		FOR(i, n) ret[i][i] = 0;
		while(c){
			if (c & 1) ret = mul(ret, b);
			b = mul(b, b), c >>= 1;
		}
		return ret;
	};
	a = fpow(a, k);
	cout << (a[0][n - 1] == 2e18 ? -1 : a[0][n - 1]) << '\n';
}
	




