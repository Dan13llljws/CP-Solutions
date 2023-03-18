#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[19][11][2][2];
int main(){
	ll a, b;
	cin >> a >> b;
	vector<ll> p(19);
	memset(dp, -1, sizeof dp);
	p[0] = 1;
	for (int i = 1; i <= 18; i++) p[i] = p[i - 1] * 10;
	function<ll(int,int,bool,bool,ll)> dfs = [&](int pos, int pre, bool lead, bool less, ll x){
		if (pos == -1) return 1LL;
		ll &ret = dp[pos][pre][lead][less];
		if (ret != -1) return ret;
		ret = 0;
		int md = x / p[pos] % 10;
		for (int i = 0; i <= (less ? 9 : md); i++)
			if (pre != i) 
				ret += dfs(pos - 1, lead && !i ? 10 : i, lead && !i, less || i < md, x);
		return ret;
	};
	b = b ? dfs(log10(b), 10, 1, 0, b) : 1;
	memset(dp, -1, sizeof dp);
	if (a != 1) a = a ? dfs(log10(a - 1), 10, 1, 0, a - 1) : 0;
	cout << b - a << '\n';
}
