#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q, x[40], y[40], d[40]; ll dp[40][2][2][2];
void get(ll v, int a[]){for (int i = 0; v; i++, v /= 3) a[i] = v % 3;}
bool check(int a, int b){return a >= 0 && a < 3 && b >= 0 && b < 3 && (a & 1)  == (b & 1);}
ll rec(int pos, int less, int xc, int yc){
	if (pos < 0) return !xc && !yc;
	ll &ret = dp[pos][less][xc][yc];
	if (ret != -1) return ret;
	ret = 0; int up = less ? 2 : d[pos];
	for (int v = 0; v <= up; v++)
		for (int c1 : {0, 1}) for (int c2 : {0, 1})
			if (check(x[pos] + v - 3 * xc + c1, y[pos] + v - 3 * yc + c2))
				ret += rec(pos - 1, less || v < up, c1, c2);
	return ret;
}
int main(){
	scanf("%d", &q);
	while(q--){
		ll X, Y, D; scanf("%lld%lld%lld", &D, &X, &Y);
		memset(x, 0, sizeof x), memset(y, 0, sizeof y), memset(d, 0, sizeof d);
		get(X, x), get(Y, y), get(D, d); memset(dp, -1, sizeof dp);
		printf("%lld\n", rec(39, 0, 0, 0));
	}
}
