#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T>
class SlopeTrick {
  using pq_dsc = std::priority_queue<T>;
  using pq_asc = std::priority_queue<T, std::vector<T>, std::greater<T>>;

public:
  static constexpr T inf = std::numeric_limits<T>::max() / 2;

  SlopeTrick() : base(0), add_l(0), add_r(0) { l.push(-inf), r.push(+inf); }

  T min() const { return base; }
  std::pair<T, T> argmin_range() const {
    return {l.top() + add_l, r.top() + add_r};
  }
  SlopeTrick &add_const(const T a) {
    base += a;
    return *this;
  }
  // f += max(0, x - a)
  SlopeTrick &add_right(const T a) {
    if (l.top() + add_l <= a) {
      r.push(a - add_r);
    } else {
      base += (l.top() + add_l) - a;
      l.push(a - add_l), r.push(l.top() + add_l - add_r), l.pop();
    }
    return *this;
  }
  // f += max(0, a - x)
  SlopeTrick &add_left(const T a) {
    if (r.top() + add_r >= a) {
      l.push(a - add_l);
    } else {
      base += a - (r.top() + add_r);
      r.push(a - add_r), l.push(r.top() + add_r - add_l), r.pop();
    }
    return *this;
  }
  // f += |x - a|
  SlopeTrick &add_abs(const T a) {
    add_left(a), add_right(a);
    return *this;
  }
  SlopeTrick &cumulative_min_left() {
    r = pq_asc{}, r.push(+inf);
    return *this;
  }
  SlopeTrick &cumulative_min_right() {
    l = pq_dsc{}, l.push(-inf);
    return *this;
  }
  SlopeTrick &operator<<=(const T shamt_left) {
    add_l -= shamt_left, add_r -= shamt_left;
    return *this;
  }
  SlopeTrick &operator>>=(const T shamt_right) {
    add_l += shamt_right, add_r += shamt_right;
    return *this;
  }
  SlopeTrick &merge(SlopeTrick& other) {
    while(other.l.size() > 1) add_left(other.l.top() + other.add_l), other.l.pop();
    while(other.r.size() > 1) add_right(other.r.top() + other.add_r), other.r.pop();
    return add_const(other.base);
  }
  SlopeTrick &translate(const T dx) {
    return dx >= 0 ? *this >>= dx : *this <<= -dx;
  }
  // f(x) = min_{x-b <= y <= x-a} f(y)
  SlopeTrick &sliding_window_minimum(const T a, const T b) {
    assert(a <= b);
    add_l += a, add_r += b;
    return *this;
  }

  std::tuple<std::vector<T>, T, std::vector<T>> lines() {
    struct seq_getter_dsc : public pq_dsc { static std::vector<T> get(const pq_dsc &pq) { return pq.*&seq_getter_dsc::c; } };
    struct seq_getter_asc : public pq_asc { static std::vector<T> get(const pq_asc &pq) { return pq.*&seq_getter_asc::c; } };
    std::vector<T> neg = seq_getter_dsc::get(l);
    std::vector<T> pos = seq_getter_asc::get(r);
    std::sort(neg.begin(), neg.end());
    std::sort(pos.begin(), pos.end());
    for (auto &e : neg)
      e += add_l;
    for (auto &e : pos)
      e += add_r;
    return std::make_tuple(neg, base, pos);
  }

	std::size_t size() { return l.size() + r.size(); }

  SlopeTrick &transform(T c) {
    ll tmp = r.top();
    cumulative_min_left();
    r.push(tmp + c);
    tmp = l.top();
    l.pop();
    l.push(tmp + c);
    return *this;
  }

  T base, add_l, add_r;
  pq_dsc l;
  pq_asc r;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + m);
  vector<int> c(n + m);
	for (int i = 1; i < n + m; i++) {
		int p; cin >> p >> c[i]; p--;
		adj[p].push_back(i);
	}
	cout << [&](this auto &&self, int u) -> SlopeTrick<ll> {
    SlopeTrick<ll> f;
    if (adj[u].empty()) return f.add_abs(0);
		for (int v : adj[u]) {
			auto g = self(v);
      g.transform(c[v]);
			if (g.size() > f.size()) swap(f, g);
      f.merge(g);
		}
    return f;
	}(0).min() << '\n';
}