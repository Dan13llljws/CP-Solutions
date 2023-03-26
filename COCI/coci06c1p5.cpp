#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MOD = 1e9 + 7, base = 131;
int n;
double dp[1 << 20], p[20][20];
double rec(int mask){
	int k = __builtin_popcount(mask);
	if (k == n) return 1;
	if (dp[mask]) return dp[mask];
	double &ret = dp[mask] = 0;
	for (int i = 0; i < n; i++){
		if (mask >> i & 1) continue;
		double tmp = p[k][i] * rec(mask | (1 << i));
		ret = max(ret, tmp);
	}
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("", "r", stdin); freopen("", "w", stdout);
	sc(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			sc(p[i][j]);
			p[i][j] /= 100.0;
		}
	printf("%.6f", rec(0) * 100);
	return 0;
}

