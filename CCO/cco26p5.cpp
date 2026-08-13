#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

namespace internal {

template <class T>
concept is_tuple_like = requires {
  typename std::tuple_size<remove_cvref_t<T>>::type;
};

template <typename T>
requires (std::is_aggregate_v<std::remove_cvref_t<T>> || is_tuple_like<T>)
constexpr std::size_t aggregate_arity() {
  using U = std::remove_cvref_t<T>;
  if constexpr (is_tuple_like<U>) {
    constexpr std::size_t n = std::tuple_size<U>::value;
    static_assert(n > 0, "arity must be positive");
    return n;
  } else if constexpr (std::is_aggregate_v<U>) {
    if constexpr (requires { U{ {}, {}, {}, {}, {} }; }) return 5;
    else if constexpr (requires { U{ {}, {}, {}, {} }; }) return 4;
    else if constexpr (requires { U{ {}, {}, {} }; }) return 3;
    else if constexpr (requires { U{ {}, {} }; }) return 2;
    else if constexpr (requires { U{ {} }; }) return 1;
    else static_assert(false, "could not determine arity");
  } else static_assert(false, "not aggregate or tuple-like");
}

template<typename T>
constexpr decltype(auto) first_field(T&& t) { return std::forward<T>(t); }

template<typename T>
requires (std::is_aggregate_v<std::remove_cvref_t<T>> || is_tuple_like<T>)
constexpr decltype(auto) first_field(T&& t) {
  constexpr std::size_t arity = aggregate_arity<T>();

  if constexpr (arity == 1) {
    auto &&[a] = t; return (a);
  } else if constexpr (arity == 2) {
    auto &&[a, b] = t; return (a);
  } else if constexpr (arity == 3) {
    auto &&[a, b, c] = t; return (a);
  } else if constexpr (arity == 4) {
    auto &&[a, b, c, d] = t; return (a);
  } else if constexpr (arity == 5) {
    auto &&[a, b, c, d, e] = t; return (a);
  }
}

template<typename T>
using first_field_t = std::remove_cvref_t<decltype(first_field(std::declval<T>()))>;

}; // namespace internal

class HLD {
  std::vector<int> par, dep, head, hvy, tin, ord;

public:
	HLD() {}
	template<typename Edge>
	HLD(const std::vector<std::vector<Edge>> &adj, int root = 0) { init(adj, root); }

	template<typename Edge>
	void init(const std::vector<std::vector<Edge>> &adj, int root = 0) {
		int n = adj.size();
    assert(root >= 0 && root < n);
		par.resize(n);
		dep.resize(n);
		head.resize(n);
		hvy.resize(n, -1);
		tin.resize(n);

		int time = 0;
		init_dfs(adj, root, root);
		hld_dfs(adj, root, root, time);
	}

	int lca(int x, int y) {
		for (; head[x] != head[y]; x = par[head[x]])
			if (dep[head[x]] < dep[head[y]]) swap(x, y);
		return dep[x] < dep[y] ? x : y;
	}

  std::pair<const std::vector<int>&, const std::vector<int>&> pre_order_traversal() const {
    return {tin, ord};
  }

	const std::vector<int> &depth() { return dep; }

	void processPath(int x, int y, auto f) {
		static_assert(std::is_convertible_v<decltype(f), std::function<void(int,int)>>,
					"f must have signature void(int l, int r) with [l, r)");
		for (; head[x] != head[y]; x = par[head[x]]) {
			if (dep[head[x]] < dep[head[y]]) swap(x, y);
			f(tin[head[x]], tin[x] + 1);
		}
		if (dep[x] < dep[y]) swap(x, y);
		f(tin[y], tin[x] + 1);
	}

private:

  template<typename T>
  using to_edge_t = internal::first_field_t<T>;

	template<typename Edge>
  int init_dfs(const std::vector<std::vector<Edge>> &adj, int src, int parent) {
    static_assert(std::is_integral_v<to_edge_t<Edge>> || internal::is_tuple_like<Edge>,
                  "Edge must be integral or tuple-like");
		int size = 1, max_subtree = -1;
		for (const Edge &e : adj[src]) {
			int v = internal::first_field(e);
			if (v == parent) continue;
			dep[v] = dep[src] + 1;
			par[v] = src;
			int cur = init_dfs(adj, v, src);
			if (cur > max_subtree) max_subtree = cur, hvy[src] = v;
			size += cur;
		}
		return size;
  }

	template<typename Edge>
  void hld_dfs(const std::vector<std::vector<Edge>> &adj, int src, int h, int &time) {
    static_assert(std::is_integral_v<to_edge_t<Edge>> || internal::is_tuple_like<Edge>,
                  "Edge must be integral or tuple-like");
    ord.push_back(src);
    tin[src] = time++, head[src] = h;
    if (hvy[src] != -1) hld_dfs(adj, hvy[src], h, time);
    for (const Edge &e : adj[src]) {
      int v = internal::first_field(e);
      if (v != par[src] && v != hvy[src]) hld_dfs(adj, v, v, time);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T; cin >> T;
  while(T--) [&]() {
    int N, Q; cin >> N >> Q;
    vector<vector<int>> adj(N);
    for (int i = 1; i < N; i++) {
      int u, v; cin >> u >> v; u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    HLD hld(adj);
    auto &dep = hld.depth();
    auto [tin, ord] = hld.pre_order_traversal();
    vector<vector<int>> d(N);
    for (int i = 0; i < N; i++) d[dep[i]].push_back(i);

    auto dist = [&](int u, int v) { return dep[u] + dep[v] - 2 * dep[hld.lca(u, v)]; };

    vector<ll> fac(N + 1);
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % MOD;
    int max_k = 1;
    for (int i = 1; i < N; i++) {
      auto &v = d[i];
      if (v.empty()) break;
      ranges::sort(v, [&](int u, int v) { return tin[u] < tin[v]; });
      max_k = max(max_k, dist(v[0], v.back()));
    }
    ll prod = 1, all = 1;
    for (int i = 1; i < N; i++) {
      auto &v = d[i];
      all = all * fac[v.size()] % MOD;
      if (v.empty()) break;
      auto &vp = d[i - 1];
      auto leafp = vp | views::filter([&](int x) { return adj[x].size() == 1 && x; }) | ranges::to<vector<int>>();
      int good = ranges::count_if(vp, [&](int u) { return dist(u, v[0]) <= max_k; });
      prod = prod * good % MOD * fac[vp.size() - 1] % MOD;
      if (i == N - 1 || d[i + 1].empty()) { // last level
        prod = prod * fac[v.size()] % MOD;
        continue;
      }
    }

    while(Q--) {
      int k; cin >> k;
      if (k < max_k) cout << 0 << ' ';
      else if (k == max_k) cout << prod << ' ';
      else cout << all << ' ';
    }
    cout << '\n';
  }();
}