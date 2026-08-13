#include "bits/stdc++.h"
using namespace std;

bool are_connected(std::vector<int> A, std::vector<int> B);

vector<int> longest_trip(int N, int D) {
  vector<int> dsu(from_range, views::iota(0, N)), comps = dsu;
  vector<vector<int>> p(N);
  for (int i = 0; i < N; i++) p[i] = {i};
  auto find = [&](this auto &&self, int x) -> int { return dsu[x] == x ? x : dsu[x] = self(dsu[x]); };
  auto unite = [&](int x, int y) {
    int fx = find(x), fy = find(y);
    if (p[fx][0] != x) ranges::reverse(p[fx]);
    if (p[fy].back() != y) ranges::reverse(p[fy]);
    dsu[fx] = fy;
    p[fy].insert(p[fy].end(), p[fx].begin(), p[fx].end());
  };
  auto try_merge = [&](int x, int y) {
    bool res = are_connected({x}, {y});
    if (res) unite(x, y);
    return res;
  };
  auto try_merge_ends = [&](int x, int y) {
    return try_merge(p[find(x)][0], p[find(y)][0]);
  };
  auto merge3 = [&](int x, int y, int z) -> vector<int> {
    if (try_merge_ends(x, y)) return {x, z};
    if (try_merge_ends(x, z)) return {x, y};
    unite(p[find(y)][0], p[find(z)][0]);
    return {z, x};
  };
  auto merge4 = [&](int x, int y, int z, int w) -> vector<int> {
    if (try_merge_ends(x, y)) return {x, z, w};
    if (try_merge_ends(z, x)) {
      if (try_merge_ends(y, w)) return {x, y};
      unite(p[find(z)][0], p[find(w)][0]);
      return {x, y};
    } else {
      unite(p[find(z)][0], p[find(y)][0]);
      if (try_merge_ends(x, w)) return {y, x};
      unite(p[find(y)][0], p[find(w)][0]);
      return {x, y};
    }
  };
  while(comps.size() > 2) {
    ranges::sort(comps, greater<int>(), [&](int x) {
      return p[find(x)].size();
    });
    int x = comps.back(); comps.pop_back();
    int y = comps.back(); comps.pop_back();
    int z = comps.back(); comps.pop_back();
    if (comps.size() > 3 && p[find(z)].size() == 1) {
      int w = comps.back(); comps.pop_back();
      auto v = merge4(x, y, z, w);
      comps.insert(comps.end(), v.begin(), v.end());
    } else {
      auto v = merge3(x, y, z);
      comps.insert(comps.end(), v.begin(), v.end());
    }
  }
  vector<int> c1, c2;
  for (int i = 0; i < N; i++) {
    if (find(i) == find(0)) c1.push_back(i);
    else c2.push_back(i);
  }
  // 21 queries after this point
  if (c1.size() > c2.size()) swap(c1, c2);
  // cliques
  if (!are_connected(c1, c2)) return c2;
  auto& h1 = p[find(c1[0])], &h2 = p[find(c2[0])];
  if (try_merge(h1[0], h2[0]) || try_merge(h1[0], h2.back()) ||
      try_merge(h1.back(), h2[0]) || try_merge(h1.back(), h2.back())) {
    return (int)h2.size() == N ? h2 : h1;
  }
  // 2 cycles
  while(c1.size() > 1) {
    int mid = c1.size() / 2;
    if (are_connected(vector<int>(c1.begin(), c1.begin() + mid), c2)) c1 = vector<int>(c1.begin(), c1.begin() + mid);
    else c1 = vector<int>(c1.begin() + mid, c1.end());
  }
  while(c2.size() > 1) {
    int mid = c2.size() / 2;
    if (are_connected(vector<int>(c2.begin(), c2.begin() + mid), c1)) c2 = vector<int>(c2.begin(), c2.begin() + mid);
    else c2 = vector<int>(c2.begin() + mid, c2.end());
  }
  ranges::rotate(h1, ranges::find(h1, c1[0]));
  ranges::rotate(h2, ranges::find(h2, c2[0]));
  ranges::reverse(h1);
  h1.insert(h1.end(), h2.begin(), h2.end());
  return h1;
}