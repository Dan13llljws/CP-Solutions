#include "bits/stdc++.h"
using namespace std;

using ll = long long;

ll max_weights(int N, int M, vector<int> X, vector<int> Y, vector<int> W) { 
  // some sort of up down up down sequence
  // start must be up, end must be down
  // go from up to down, there must be gap
  // go from down to up, it can transition from same Y
  vector<vector<pair<int,int>>> fish(N);
  for (int i = 0; i < M; i++) fish[X[i]].emplace_back(Y[i] + 1, W[i]);
  vector<pair<int,ll>> dp_up = {{0, 0}}, dp_down = {{N + 1, (ll)-1e18}};
  ll dp_empty = -1e18;
  for (auto &f : fish) ranges::sort(f);
  for (int i = 0; i < N; i++) {
    vector<pair<int,ll>> ndp_up, ndp_down;
    ll prev = max(dp_up.back().second, dp_down.back().second);
    ndp_up.emplace_back(0, max(dp_down.back().second, dp_empty));
    ndp_down.emplace_back(N + 1, dp_empty);
    int j = 0;
    for (auto [y, w] : fish[i]) {
      while(j < (int)dp_up.size() - 1 && dp_up[j + 1].first < y) j++; 
      ndp_up.emplace_back(y, max(ndp_up.back().second, dp_up[j].second) + w);
    }
    j = 0;
    for (auto [y, w] : fish[i] | views::reverse) {
      while(j < (int)dp_down.size() - 1 && dp_down[j + 1].first > y) j++; 
      ndp_down.emplace_back(y, max(ndp_down.back().second, dp_down[j].second) + w);
    }
    dp_empty = prev;
    dp_up = ndp_up;
    dp_down = ndp_down;
  }

  return max(dp_empty, dp_down.back().second);
}