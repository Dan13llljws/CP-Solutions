#include "bits/stdc++.h"
using namespace std;

using ll = long long;

template<typename T = int>
struct DisjointIntervals{
  std::set<std::pair<T, T>> intervals;
  DisjointIntervals() {}
	static std::pair<T,T> merge(const std::pair<T,T> &a, const std::pair<T,T> &b) {
		assert(a.second >= b.first && a.first <= b.second);
		return std::make_pair(std::min(a.first, b.first), std::max(a.second, b.second));
	}
  void add(T l, T r) { // [l, r) 
    auto val = std::make_pair(l, r);
    auto it = intervals.upper_bound(val);
    while (it != intervals.end() && it->first <= val.second) { // merge after
      val = merge(*it, val);
      it = intervals.erase(it);
    }
    if (it != intervals.begin()) { // merge before
			it--; // it->first <= x
			if (it->second >= val.first) {
				val = merge(*it, val);
				intervals.erase(it);
			}
    }
    intervals.insert(val);
  }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, q; cin >> n >> n >> m >> q;
	unordered_map<int,DisjointIntervals<int>> vertical, horizontal, diagonal;
	for (int i = 0; i < q; i++) {
		int t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
		if (t == 1) horizontal[y1].add(x1, x2 + 1);
		else if (t == 2) vertical[x1].add(y1, y2 + 1);
		else if (t == 3) diagonal[x1 - y1].add(x1, x2 + 1);
	}
	vector<int> cx;
	ll ans = 0;
	for (const auto &[x, i] : vertical) {
		cx.push_back(x);
		for (const auto &[l, r] : i.intervals) ans += r - l;
	}
	for (const auto &[y, i] : horizontal)
		for (const auto &[l, r] : i.intervals)
			ans += r - l;
	sort(cx.begin(), cx.end()), cx.resize(unique(cx.begin(), cx.end()) - cx.begin());

	// line sweep
	int t = cx.size();
	vector<int> bit(t + 1);
	auto upd = [&](int x, int v) {
		for (; x <= t; x += x & -x) bit[x] += v;
	};
	auto get = [&](int x) {
		ll ret = 0;
		for (; x; x -= x & -x) ret += bit[x];
		return ret;
	};

	// t=0 remove, t=1 add, t=2 query
	struct Event { int t, y, l, r; };
	vector<Event> e;
	for (const auto &[x, i] : vertical)
		for (const auto &[l, r] : i.intervals) {
			e.emplace_back(0, r, x, 0);
			e.emplace_back(1, l, x, 0);
		}
	for (const auto &[y, i] : horizontal)
		for (const auto &[l, r] : i.intervals)
			e.emplace_back(2, y, l, r);
	sort(e.begin(), e.end(), [](auto a, auto b) {
		return a.y == b.y ? a.t < b.t : a.y < b.y;
	});
	for (auto [t, y, l, r] : e) {
		if (t <= 1) {
			l = lower_bound(cx.begin(), cx.end(), l) - cx.begin() + 1;
			upd(l, t * 2 - 1);
		} else if (t == 2) {
			l = lower_bound(cx.begin(), cx.end(), l) - cx.begin();
			r = lower_bound(cx.begin(), cx.end(), r) - cx.begin();
			ans -= get(r) - get(l);
		}
	}

	set<pair<int,int>> inter;
	for (const auto &[delta, d] : diagonal) {
		for (const auto &[l, r] : d.intervals) {
			int x1 = l, x2 = r - 1, y1 = x1 - delta, y2 = x2 - delta;
			for (const auto &[x, i] : vertical)
				for (const auto &[l, r] : i.intervals) {
					if (x < x1 || x > x2) continue;
					int t = x - x1;
					int y = y1 + t;
					if (y >= l && y < r) inter.emplace(x, y);
				}
			for (const auto &[y, i] : horizontal)
				for (const auto &[l, r] : i.intervals) {
					if (y < y1 || y > y2) continue;
					int t = y - y1;
					int x = x1 + t;
					if (x >= l && x < r) inter.emplace(x, y);
				}
			ans += x2 - x1 + 1;
		}
	}
	if (q > 0) assert(ans);
	cout << ans - inter.size() << '\n';
}