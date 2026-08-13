#include "bits/stdc++.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n; cin >> n;

  struct Comp { int minl, maxl, minr, maxr; };
  set<Comp,decltype([](Comp a, Comp b) { return a.minl > b.minl; })> st1;
  set<Comp,decltype([](Comp a, Comp b) { return a.minr > b.minr; })> st2;
  auto rem = [&](Comp c) { st1.erase(c); st2.erase(c); };
  auto merge = [&](Comp a, Comp b) {
    return Comp{min(a.minl, b.minl), max(a.maxl, b.maxl), min(a.minr, b.minr), max(a.maxr, b.maxr)};
  };
  for (int i = 0; i < n; i++) {
    int l, r; cin >> l >> r;
    Comp c = {l, l, r, r};
    for (auto it = st1.lower_bound({l, l, r, r}); it != st1.end() && !(it->maxl < l && it->maxr < r); ) {
      Comp old = *it;
      ++it;
      c = merge(old, c);
      rem(old);
    }
    for (auto it = st2.lower_bound({l, l, r, r}); it != st2.end() && !(it->maxl < l && it->maxr < r); ) {
      Comp old = *it;
      ++it;
      c = merge(old, c);
      rem(old);
    }
    st1.insert(c);
    st2.insert(c);
    cout << st1.size() << '\n';
  }
}