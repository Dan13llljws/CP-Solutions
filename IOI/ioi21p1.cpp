#include "bits/stdc++.h"
using namespace std;

using ll = long long;

template <class S, auto op, auto e> struct segtree {
	static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
				  "op must work as S(S, S)");
	static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
				  "e must work as S()");
public:
	segtree() : segtree(0) {}
	explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
	explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
		size = (int)bit_ceil((unsigned int)(_n));
		log = countr_zero((unsigned int)size);
		d = std::vector<S>(2 * size, e());
		for (int i = 0; i < _n; i++) d[size + i] = v[i];
		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < _n);
		p += size;
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	S get(int p) const {
		assert(0 <= p && p < _n);
		return d[p + size];
	}

	S prod(int l, int r) const {
		assert(0 <= l && l <= r && r <= _n);
		S sml = e(), smr = e();
		l += size;
		r += size;

		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}
		return op(sml, smr);
	}

	S all_prod() const { return d[1]; }

	template <bool (*f)(S)> int max_right(int l) const {
		return max_right(l, [](S x) { return f(x); });
	}
	template <class F> int max_right(int l, F f) const {
		assert(0 <= l && l <= _n);
		assert(f(e()));
		if (l == _n) return _n;
		l += size;
		S sm = e();
		do {
			while (l % 2 == 0) l >>= 1;
			if (!f(op(sm, d[l]))) {
				while (l < size) {
					l = (2 * l);
					if (f(op(sm, d[l]))) {
						sm = op(sm, d[l]);
						l++;
					}
				}
				return l - size;
			}
			sm = op(sm, d[l]);
			l++;
		} while ((l & -l) != l);
		return _n;
	}

	template <bool (*f)(S)> int min_left(int r) const {
		return min_left(r, [](S x) { return f(x); });
	}
	template <class F> int min_left(int r, F f) const {
		assert(0 <= r && r <= _n);
		assert(f(e()));
		if (r == 0) return 0;
		r += size;
		S sm = e();
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!f(op(d[r], sm))) {
				while (r < size) {
					r = (2 * r + 1);
					if (f(op(d[r], sm))) {
						sm = op(d[r], sm);
						r--;
					}
				}
				return r + 1 - size;
			}
			sm = op(d[r], sm);
		} while ((r & -r) != r);
		return 0;
	}

  private:
	int _n, size, log;
	std::vector<S> d;

	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

struct S { ll sum, suf_mx, suf_mn; };
using seg_t = segtree<
  S,
  [](S a, S b) {
    S s;
    s.sum = a.sum + b.sum;
    s.suf_mx = max(b.suf_mx, a.suf_mx + b.sum);
    s.suf_mn = min(b.suf_mn, a.suf_mn + b.sum);
    return s;                                 
  },
  []() { return S{0, (ll)-1e18, (ll)1e18 }; }>;

vector<int> distribute_candies(vector<int> c, vector<int> l, vector<int> r, vector<int> v) {
  int n = c.size(), m = l.size();
  struct Event { int i, v; };
  vector<vector<Event>> e(n + 1);
  for (int i = 0; i < m; i++) {
    e[l[i]].emplace_back(i, v[i]);
    e[r[i] + 1].emplace_back(i, 0);
  }
  seg_t seg(m + 1);
  seg.set(m, S{0, 0, 0 });
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int thres = c[i];
    for (auto &[idx, v] : e[i]) seg.set(idx, S{v, v, v});
    int j = max(0, seg.min_left(m + 1, [&thres](S s) { return s.suf_mx - s.suf_mn <= thres; }) - 1);
    auto s = seg.prod(j, m + 1);
    ans[i] = (s.suf_mx - s.suf_mn <= thres || s.sum == s.suf_mn ? s.suf_mx : s.suf_mn + thres);
  }
  return ans;
}

int main() {
  println("{}", distribute_candies({10, 15, 13}, {0, 0}, {2, 1}, {20, -11}));
}
