#include <bits/stdc++.h>
using namespace std;
struct P{int f, s, i;};
int t, n; bool vis[1005]; vector<P> v[1005], p;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); memset(vis, 0, sizeof vis); p.clear();
		for (int i = 0; i < n; i++){
			int a, b; scanf("%d-%d", &a, &b);
			v[i].clear();
			p.push_back({a, b, i}), p.push_back({b, a, i});
		}
		sort(p.begin(), p.end(), [](P a, P b){return a.f == b.f ? a.s < b.s : a.f < b.f;});
		int ans = 0;
		for (int i = 2 * n - 1; i >= 0; i--){
			if (vis[p[i].i]) continue;
			P cur = p[i];
			v[ans].push_back(p[i]);
			vis[p[i].i] = 1;
			for (int j = i - 1; j >= 0; j--)
				if (!vis[p[j].i] && cur.f >= p[j].f && cur.s >= p[j].s)
					v[ans].push_back(cur = p[j]), vis[p[j].i] = 1;
			ans++;
		}
		printf("%d\n", ans);
		for (int i = 0; i < ans; i++){
			sort(v[i].begin(), v[i].end(), [](P a, P b){return a.f == b.f ? a.s < b.s : a.f < b.f;});
			for (P x : v[i]) printf("%d-%d ", x.f , x.s);
			puts("");
		}
	}
}
