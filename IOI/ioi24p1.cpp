#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void ckmin(int &x, int y) { x = min(x, y); }

vector<ll> calculate_costs(vector<int> W, vector<int> A, vector<int> B, vector<int> E) {
  int N = W.size(), M = E.size();
  struct Item { int w, a; ll s; };
  vector<Item> items(from_range, views::iota(0, N) | views::transform([&](int i) {
    return Item{ W[i], A[i] - B[i], B[i] };
  }));
  vector<int> even(N, 1e9), odd(N, 1e9), mn(N, 1e9);
  ranges::sort(items, [](Item a, Item b) { return a.w < b.w; });
  for (int i = 0; i < N; i++) {
    if (i & 1) odd[i] = items[i].a;
    else even[i] = items[i].a;
  }

  struct Event { int t, w, i; };
  vector<Event> e;
  for (int i = 0; i < N - 1; i++) e.emplace_back(0, items[i + 1].w - items[i].w, i);
  e.emplace_back(1, 0, 0), e.emplace_back(1, 0, N - 1);
  for (int i = 1; i < N - 1; i++) e.emplace_back(1, items[i + 1].w - items[i - 1].w, i);
  ranges::sort(e, [](Event a, Event b) { return a.w < b.w; });

  ll sum = ranges::fold_left(A, 0LL, plus<ll>());

  vector<int> dsu(from_range, views::iota(0, N)), sz(N, 1);
  vector<ll> S(from_range, B | views::transform([](int i) { return i * 1LL; }));
  auto find = [&](this auto &&self, int x) -> int { return x == dsu[x] ? x : dsu[x] = self(dsu[x]); };
  auto calc = [&](int x) {
    if (sz[x] % 2 == 0) return (ll)items[x].s;
    int a = x & 1 ? odd[x] : even[x];
    return items[x].s + min(mn[x], a);
  };
  auto unite = [&](int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    sum -= calc(x) + calc(y);
    ckmin(mn[y], mn[x]);
    ckmin(even[y], even[x]);
    ckmin(odd[y], odd[x]);
    items[y].s += items[x].s, sz[y] += sz[x], dsu[x] = y;
    sum += calc(y);
  };

  struct Query { int d, i; };
  vector<Query> q(from_range, views::iota(0, M) | views::transform([&](int i) {
    return Query{ E[i], i };
  }));
  ranges::sort(q, [](Query a, Query b) { return a.d < b.d; });

  vector<ll> ans(M);
  for (int i = 0, j = 0; i < M; i++) {
    auto [d, idx] = q[i];
    while(j < 2 * N - 1 && e[j].w <= d) {
      if (!e[j].t) unite(e[j].i, e[j].i + 1);
      else {
        int y = find(e[j].i);
        sum -= calc(y);
        ckmin(mn[y], items[e[j].i].a);
        sum += calc(y);
      }
      j++;
    }
    ans[idx] = sum;
  }

  return ans;
}