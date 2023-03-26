#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5005;
int k, q, d, m, a[MM]; vector<int> ans; unordered_set<ll> vis;
bool dfs(ll x, int zero){
	if (x == 0 && !zero) return 1;
	if (vis.count(x)) return 0;
	vis.insert(x);
	for (int i = 0; i < d; i++)
		if ((x - a[i]) % k == 0){
			ans.push_back(a[i]);
			if (dfs((x - a[i]) / k, 0)) return 1;
			ans.pop_back();
		}
	return 0;
}
int main(){
	scanf("%d%d%d%d", &k, &q, &d, &m);
	for (int i = 0; i < d; i++) scanf("%d", a + i);
	while(q--){
		ll x; scanf("%lld", &x);
		ans.clear(); vis.clear();
		if (dfs(x, 1)){
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < (int)ans.size(); i++)
				printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
		} else puts("IMPOSSIBLE");
	}
}
