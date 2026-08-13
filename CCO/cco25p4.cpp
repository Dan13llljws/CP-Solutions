#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const int mod = 998224353;

template<typename T, auto merge>
struct SegmentTree {
	size_t n; 
	std::vector<T> tree;

	#define lc i << 1
	#define rc i << 1 | 1

	void build(int i, const T& v, int l, int r) {
		if (l == r - 1) { tree[i] = v; return; }
		int m = (l + r) >> 1;
		build(lc, v, l, m), build(rc, v, m, r);
		tree[i] = merge(tree[lc], tree[rc]);
	}
	SegmentTree(size_t _n, const T& t = T{}): n(_n), tree(4 * _n, t) { build(1, t, 0, n); }

	void update(int i, int pos, const T& val, int l, int r) {
		if (l == r - 1) { tree[i] = val; return; }
		int m = (l + r) >> 1;
		if (pos < m) update(lc, pos, val, l, m);
		else update(rc, pos, val, m, r);
		tree[i] = merge(tree[lc], tree[rc]);
	}
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
	}
	if (n == 1) {
		if (a[0] == -1) cout << 1 << ' ' << 0 << '\n';
		else cout << 0 << ' ' << 0 << '\n';	
		return 0;
	}
	if (accumulate(a.begin(), a.end(), 0) != -1) {
		cout << 0 << ' ' << 0 << '\n';
		return 0;
	}

	struct S{ int sum, psa, idx; };

	SegmentTree<S, [](S a, S b) -> S {
		S ret;
		ret.sum = a.sum + b.sum;
		if (a.psa <= b.psa + a.sum) ret.psa = a.psa, ret.idx = a.idx;
		else ret.psa = b.psa + a.sum, ret.idx = b.idx;
		return ret;
	}> seg(n);

	for (int i = 0; i < n; i++) seg.update(1, i, {a[i], a[i], i}, 0, n);
	cout << 1 << ' ' << (seg.tree[1].idx + 1) % n << '\n';
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		swap(a[x], a[y]);
		seg.update(1, x, {a[x], a[x], x}, 0, n);
		seg.update(1, y, {a[y], a[y], y}, 0, n);
		cout << 1 << ' ' << (seg.tree[1].idx + 1) % n << '\n';
	}
}
