#include <bits/stdc++.h>
using namespace std;
 
struct DSU_rollback {
	int n, cc;
	vector<int> dsu, sz, st;
	DSU_rollback(int _n): n(_n), cc(n), dsu(n), sz(n, 1) {
		iota(dsu.begin(), dsu.end(), 0);
	}
	inline int find(int x) { return dsu[x] == x ? x : find(dsu[x]); }
	inline bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return 0;
		if (sz[x] > sz[y]) swap(x, y);
		return dsu[x] = y, sz[y] += sz[x], cc--, st.push_back(x), 1;
	}
	void roll_back(int k = 1) {
		while(k--) {
			int x = st.back(); st.pop_back();
			sz[dsu[x]] -= sz[x], dsu[x] = x, cc++;
		}
	}
};
 
struct Query { int a, b; };
struct QueryTree {
	int n, m; // n is DS size, m is no. queries
	vector<vector<Query>> tree;
	// DS
	DSU_rollback dsu;
	QueryTree(int _n, int _m): n(_n), m(_m), tree(4 * m + 1), dsu(_n) {}
	void insert(Query q, int ql, int qr, int l, int r, int i) {
		if (ql >= qr) return;
		if (ql == l && qr == r) { tree[i].push_back(q); return; }
		int mid = (l + r + 1) >> 1;
		insert(q, ql, min(mid, qr), l, mid, i << 1);
		insert(q, max(mid, ql), qr, mid, r, i << 1 | 1);
	} void insert(Query q, int ql, int qr) { insert(q, ql, qr, 0, m, 1); };
	void solve(int i, int l, int r) {
		if (l >= r) return;
		int cnt = 0;
		for (auto [a, b] : tree[i]) {
			cnt += dsu.unite(a, b);
		}
		if (l == r - 1) { // answer query
			cout << dsu.cc << ' ';
			dsu.roll_back(cnt);
			return;
		}
		int mid = (l + r + 1) >> 1;
		solve(i << 1, l, mid), solve(i << 1 | 1, mid, r);
		dsu.roll_back(cnt);
	} void solve() { solve(1, 0, m); }
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k; cin >> n >> m >> k;
	QueryTree qt(n, k + 1);
	vector<map<int,int>> f(n);
	auto add = [&](int a, int b, int c) -> void {
		if (a > b) swap(a, b);
		f[a][b] = c;
	};
	auto get = [&](int a, int b) -> int {
		if (a > b) swap(a, b);
		int ret = f[a][b]; f[a].erase(b);
		return ret;
	};
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--, add(a, b, 0);
	}
	for (int i = 1; i <= k; i++) {
		int t, a, b; cin >> t >> a >> b;
		a--, b--;
		if (t == 1) add(a, b, i);
		else {
			int j = get(a, b);
			qt.insert(Query{a, b}, j, i);
		}
	}
	for (int i = 0; i < n; i++)
		for (auto [x, y] : f[i])
			qt.insert(Query{i, x}, y, k + 1);
	qt.solve();
}
