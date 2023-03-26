#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5, SZ = 1000;
int n, q, k, cnt, p[MM], a[MM], f[MM], psa[100][MM], mp[MM], bit[MM]; ll ans; vector<int> big, vec[MM]; unordered_map<int,ll> dp[MM];
void upd(int x){
	for (; x <= k; x += x & -x) bit[x]++;
}
int get(int x){
	int ret = 0;
	for (; x; x -= x & -x) ret += bit[x];
	return ret;
}
int main(){
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), f[a[i]]++, vec[a[i]].push_back(i);
	iota(p + 1, p + 1 + k, 1);
	for (int i = 1; i <= k; i++)	
		if (f[i] > SZ) mp[i] = big.size(), big.push_back(i);
	cnt = big.size();
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < cnt; j++){
			psa[j][i] += psa[j][i - 1];
			if (a[i] == big[j]) psa[j][i]++;
		}
	for (int i = n; i; i--)
		upd(a[i]), ans += get(a[i] - 1);
	while(q--){
		int id; scanf("%d", &id);
		swap(p[id], p[id + 1]);
		int x = p[id], y = p[id + 1], rev = 1;
		if (f[x] > f[y]) swap(x, y), rev = -1;
		if (dp[x].count(y)) ans += rev * (dp[x][y] - dp[y][x]);
		else if (f[x] <= SZ && f[y] <= SZ){
			for (int i = 0, j = 0; i < (int)vec[x].size(); i++){
				while(j < (int)vec[y].size() && vec[y][j] < vec[x][i]) j++;
				dp[x][y] += j;
			} dp[y][x] = 1LL * f[x] * f[y] - dp[x][y];
			ans += rev * (dp[x][y] - dp[y][x]);
		} else {
			for (int i = 0; i < (int)vec[x].size(); i++)
				dp[x][y] += psa[mp[y]][vec[x][i]];
			dp[y][x] = 1LL * f[x] * f[y] - dp[x][y];
			ans += rev * (dp[x][y] - dp[y][x]);
		} printf("%lld\n", ans);
	}
		
}
