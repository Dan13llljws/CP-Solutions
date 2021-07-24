#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t, st[505], h[505], g[505][505]; ll ans; vector<pair<int,int>> vec;
ll get(){
	ll ret = 0; memset(h, 0, sizeof h);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			if (g[i][j]) h[j]++;
			else h[j] = 0;
		int sum = 0; t = 0;
		for (int j = 1; j <= n; sum += h[j], ret += sum, st[++t] = j++)
			while(t && h[st[t]] >= h[j]) sum -= (h[st[t]] - h[j]) * (st[t] - st[t - 1]), t--;
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			int x; scanf("%d", &x);
			if (x == 100) vec.push_back({i, j});
			if (x >= 100) g[i][j] = 1;
		}
	ans = get();
	for (auto x : vec) g[x.first][x.second] = 0;
	printf("%lld\n", ans - get());
}
	
