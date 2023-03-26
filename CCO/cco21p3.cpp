#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 8e5 + 5;
struct Q{ll x; int id;} qq[MM];
int n, q, t = 1, md, tot, ord[MM<<1], d[MM], st[MM], bit[MM<<1], ans[MM]; ll sum; vector<int> adj[MM], c[MM];
void dfs(int src, int par, int dis){
	md = max(md, dis); d[src] = dis; bool add = 0;
	for (int i = 0; i < (int)adj[src].size(); i++)
		if (adj[src][i] == par) add = 1, st[src] = i;
		else dfs(adj[src][i], src, dis + add);
}
void dfs1(int src){
	c[d[src]].push_back(t), ord[t++] = src;
	for (int i = st[src] + 1; i < (int)adj[src].size(); i++)
		dfs1(adj[src][i]), c[d[adj[src][i]]].push_back(t), ord[t++] = src;
	for (int i = 0; i < st[src]; i++)
		dfs1(adj[src][i]), c[d[adj[src][i]]].push_back(t), ord[t++] = src;
}
void upd(int x){
	for (; x <= t; x += x & -x) bit[x]++;
}
int get(int k){
	int x = 0, s = 0;
	for (int i = 25; i >= 0; i--)
		if (x + (1 << i) <= t && s + bit[x + (1 << i)] < k)
			s += bit[x + (1 << i)], x += (1 << i);
	return x + 1;
}
int main(){
	scanf("%d%d", &n, &q), st[1] = -1;
	for (int i = 1; i <= n; i++){
		int k; scanf("%d", &k), adj[i].resize(k);
		for (int j = 0; j < k; j++) scanf("%d", &adj[i][j]);
		rotate(adj[i].begin(), adj[i].begin() + 1, adj[i].end());
	} dfs(1, 1, 0), dfs1(1), t--, c[0].pop_back();
	for (int i = 0; i < q; i++) scanf("%lld", &qq[i].x), qq[i].x++, qq[i].id = i;
	sort(qq, qq + q, [](Q a, Q b){return a.x < b.x;}); int j = 0;
	for (int i = 0; i <= md; i++){
		for (int v : c[i]) upd(v), tot++;
		while(j < q && qq[j].x <= sum + tot) ans[qq[j].id] = ord[get(qq[j].x - sum)], j++;
		sum += tot;
	}
	while(j < q) ans[qq[j].id] = ord[get((qq[j].x - sum - 1) % tot + 1)], j++;
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}

