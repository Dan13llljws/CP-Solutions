#include "bits/stdc++.h"
using namespace std;

template <class S,
		  auto op,
		  auto e,
		  class F,
		  auto mapping,
		  auto composition,
		  auto id>
struct lazy_segtree {
	static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
				  "op must work as S(S, S)");
	static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
				  "e must work as S()");
	static_assert(
		std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
		"mapping must work as S(F, S)");
	static_assert(
		std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,
		"composition must work as F(F, F)");
	static_assert(std::is_convertible_v<decltype(id), std::function<F()>>,
				  "id must work as F()");

  public:
	lazy_segtree() : lazy_segtree(0) {}
	explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
	explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
		size = (int)bit_ceil((unsigned int)(_n));
		log = countr_zero((unsigned int)size);
		d = std::vector<S>(2 * size, e());
		lz = std::vector<F>(size, id());
		for (int i = 0; i < _n; i++) d[size + i] = v[i];
		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < _n);
		p += size;
		for (int i = log; i >= 1; i--) push(p >> i);
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	S get(int p) {
		assert(0 <= p && p < _n);
		p += size;
		for (int i = log; i >= 1; i--) push(p >> i);
		return d[p];
	}

	S prod(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);
		if (l == r) return e();

		l += size;
		r += size;

		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}

		S sml = e(), smr = e();
		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}

		return op(sml, smr);
	}

	S all_prod() { return d[1]; }

	void apply(int p, F f) {
		assert(0 <= p && p < _n);
		p += size;
		for (int i = log; i >= 1; i--) push(p >> i);
		d[p] = mapping(f, d[p]);
		for (int i = 1; i <= log; i++) update(p >> i);
	}
	void apply(int l, int r, F f) {
		assert(0 <= l && l <= r && r <= _n);
		if (l == r) return;

		l += size;
		r += size;

		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}

		{
			int l2 = l, r2 = r;
			while (l < r) {
				if (l & 1) all_apply(l++, f);
				if (r & 1) all_apply(--r, f);
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}

		for (int i = 1; i <= log; i++) {
			if (((l >> i) << i) != l) update(l >> i);
			if (((r >> i) << i) != r) update((r - 1) >> i);
		}
	}

	template <bool (*g)(S)> int max_right(int l) {
		return max_right(l, [](S x) { return g(x); });
	}
	template <class G> int max_right(int l, G g) {
		assert(0 <= l && l <= _n);
		assert(g(e()));
		if (l == _n) return _n;
		l += size;
		for (int i = log; i >= 1; i--) push(l >> i);
		S sm = e();
		do {
			while (l % 2 == 0) l >>= 1;
			if (!g(op(sm, d[l]))) {
				while (l < size) {
					push(l);
					l = (2 * l);
					if (g(op(sm, d[l]))) {
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

	template <bool (*g)(S)> int min_left(int r) {
		return min_left(r, [](S x) { return g(x); });
	}
	template <class G> int min_left(int r, G g) {
		assert(0 <= r && r <= _n);
		assert(g(e()));
		if (r == 0) return 0;
		r += size;
		for (int i = log; i >= 1; i--) push((r - 1) >> i);
		S sm = e();
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!g(op(d[r], sm))) {
				while (r < size) {
					push(r);
					r = (2 * r + 1);
					if (g(op(d[r], sm))) {
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
	std::vector<F> lz;

	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
	void all_apply(int k, F f) {
		d[k] = mapping(f, d[k]);
		if (k < size) lz[k] = composition(f, lz[k]);
	}
	void push(int k) {
		all_apply(2 * k, lz[k]);
		all_apply(2 * k + 1, lz[k]);
		lz[k] = id();
	}
};

using ll = long long;

const int MOD = 1e9 + 2022;

int n;
lazy_segtree<
  pair<ll,ll>,
  [](auto a, auto b) { return pair<ll,ll>{ (a.first + b.first) % MOD, (a.second + b.second) % MOD }; },
  []() { return pair<ll,ll>{ 0LL, 0LL }; },
  int,
  [](int f, pair<ll,ll> x) {
    if (f) swap(x.first, x.second);
    return x;
  },
  [](int f, int g) { return f ^ g; },
  []() { return 0; }
> seg;

void init(int N, int M, vector<int> P, vector<int> A) {
  n = N;
  seg = decltype(seg)(M); 
  vector<vector<int>> adj(N + M);
  for (int i = 1; i < N + M; i++) adj[P[i]].push_back(i);
  vector<ll> p(N + M), ways(N + M, 1);
  p[0] = 1;
  for (int i = N - 1; i >= 0; i--) {
    ways[i] = adj[i].size();
    for (int v : adj[i]) ways[i] = ways[i] * ways[v] % MOD;
  }
  for (int i = 0; i < N; i++) {
    int c = adj[i].size();
    vector<ll> pre(c + 2, 1), suf(c + 2, 1);
    for (int j = 1; j <= c; j++)
      pre[j] = suf[j] = ways[adj[i][j - 1]];
    for (int j = 1; j <= c; j++) pre[j] = pre[j] * pre[j - 1] % MOD;
    for (int j = c; j >= 1; j--) suf[j] = suf[j] * suf[j + 1] % MOD;
    for (int j = 1; j <= c; j++)
      p[adj[i][j - 1]] = p[i] * pre[j - 1] % MOD * suf[j + 1] % MOD;
  }
  for (int i = N; i < N + M; i++) 
    seg.set(i - N, pair<ll,ll>{A[i - N] * p[i], (1 - A[i - N]) * p[i]});
}

int count_ways(int L, int R) {
  seg.apply(L - n, R - n + 1, 1);
  return seg.all_prod().first;
}