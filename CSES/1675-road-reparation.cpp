#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<array<int,3>> edges(m);
	for (auto &x : edges) cin >> x[1] >> x[2] >> x[0];
	sort(edges.begin(), edges.end());
	vector<int> dsu(n + 1);
	for (int i = 1; i <= n; i++) dsu[i] = i;
	function<int(int)> Find = [&](int x){
		return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);
	};
	long long ans = 0;
	int cnt = 0;
	for (auto x : edges){
		if (Find(x[1]) != Find(x[2])){
			ans += x[0];
			dsu[Find(x[1])] = Find(x[2]);
			cnt++;
		}
	}
	if (cnt != n - 1) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';
}
	



