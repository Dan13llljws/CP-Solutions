#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5, MN = 5e4 + 5, SZ = 1000;
struct Edge{int u, v, d;} e[MM];
struct Query{int t, x, y, id;} q[MM], qry[MM], upd[MM];
int N, M, Q, proc[MM], dsu[MN], sz[MN], st[MM], eid[MM], top, ans[MM], tq, tu;
vector<pair<int,int>> val[MM];
int Find(int x) {
	return dsu[x] == x ? x : Find(dsu[x]);
}
bool unite(int x, int y) {
	x = Find(x), y = Find(y);
	if (x == y) return 0;
	if (sz[x] > sz[y]) swap(x, y);
	sz[y] += sz[x], dsu[x] = y, st[top++] = x;
	return 1;
}
void roll_back() {
	int x = st[--top];
	sz[dsu[x]] -= sz[x], dsu[x] = x;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> e[i].u >> e[i].v >> e[i].d;
		val[i].emplace_back(-1, e[i].d);
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> q[i].t >> q[i].x >> q[i].y, q[i].id = i;
		if (q[i].t == 1) val[q[i].x - 1].emplace_back(i, q[i].y);
	}
	iota(eid, eid + M, 0);
	int B = (Q + SZ - 1) / SZ;
	for (int blc = 0; blc < B; blc++) {
		memset(proc, 0, sizeof proc); top = 0;
		for (int i = 1; i <= N; i++) dsu[i] = i, sz[i] = 1;
		sort(eid, eid + M, [&](int a, int b) { return e[a].d > e[b].d; });
		tu = tq = 0;
		for (int i = blc * SZ; i < min(Q, blc * SZ + SZ); i++) {
			if (q[i].t == 1) upd[tu++] = q[i], proc[q[i].x - 1] = 1;
			else qry[tq++] = q[i]; 
		}
		sort(qry, qry + tq, [&](Query a, Query b) { return a.y > b.y; });
		int ei = 0;
		for (int i = 0; i < tq; i++) {
			auto [t, s, w, id] = qry[i];
			while(ei < M && e[eid[ei]].d >= w) {
				if (!proc[eid[ei]]) unite(e[eid[ei]].u, e[eid[ei]].v);
				ei++;
			}
			int tmp = top;
			for (int i1 = 0; i1 < tu; i1++) {
				auto [_, b, r, uid] = upd[i1];
				int j = upper_bound(val[b - 1].begin(), val[b - 1].end(), make_pair(id, 0)) - val[b - 1].begin() - 1;
				if (val[b - 1][j].second >= w) {
					unite(e[b - 1].u, e[b - 1].v);
				}
			}
			ans[id] = sz[Find(s)];
			while(top > tmp) roll_back();
		}
		for (int i = 0; i < tu; i++) e[upd[i].x - 1].d = upd[i].y;
	}
	for (int i = 0; i < Q; i++) 
		if (q[i].t == 2) cout << ans[i] << '\n';
}
