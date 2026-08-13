#include "souvenirs.h"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void buy_souvenirs(int N, long long P0) {
  vector<pair<ll, set<int>>> eq(N);
  vector<ll> p(N, -1), cnt(N);
  p[0] = P0;

  auto work = [&](ll m) {
    auto [v, rem] = transaction(m);
    m -= rem;

    set<int> unk;
    for (int x : v) { 
      if (p[x] != -1) m -= p[x];
      else unk.insert(x);
      cnt[x]++;
    }
    eq[v[0]] = {m, unk};
  };
  while([&]() -> bool {
    for (int i = N - 1; i >= 0; i--) {
      if (eq[i].second.size() > 1) {
        work(eq[i].first / eq[i].second.size());
        return true;
      }
      if (p[i] != -1 && i < N - 1 && p[i + 1] == -1) {
        work(p[i] - 1);
        return true;
      }
      if (eq[i].second.size() == 1) {
        assert(*(eq[i].second.begin()) == i);
        p[i] = eq[i].first;

        for (int j = 0; j < N; j++) {
          for (auto x : eq[j].second) {
            if (x == i) {
              eq[j].second.erase(i);
              eq[j].first -= p[i];
              break;
            }
          }
        }
        return true;
      }
    }
    return false;
  }());

  for (int i = 0; i < N; i++) 
    for (int j = cnt[i]; j < i; j++)
      transaction(p[i]);
}