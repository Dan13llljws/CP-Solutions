#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> dsu(n + 1), sz(n + 1);
	for (int i = 1; i <= n; i++) dsu[i] = i, sz[i] = 1;
	int ans = 1, cnt = n;
	function<int(int)> Find = [&](int x){
		return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);
	};
	auto unite =  [&](int x, int y){
		int fx = Find(x), fy = Find(y);
		if(fx == fy) return;
		sz[fy] += sz[fx];
		ans = max(ans, sz[fy]);
		cnt--;
		dsu[fx] = fy;
	};
	while(m--){
		int a, b;
		cin >> a >> b;
		unite(a, b);
		cout << cnt << ' ' << ans << '\n';
	}
}
	




