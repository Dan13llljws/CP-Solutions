#include "bits/stdc++.h"
using namespace std;

int hubDistance(int N, int sub) {
  int far = -1, max_d = 0;
  vector<int> da(N), dr(N);
  for (int i = 1; i < N; i++) {
    dr[i] = getDistance(0, i);
    if (dr[i] > max_d) max_d = dr[i], far = i;
  }
  int a = far;
  max_d = 0;
  for (int i = 0; i < N; i++) {
    if (i == a) continue;
    da[i] = getDistance(a, i);
    if (da[i] > max_d) max_d = da[i], far = i;
  }
  int b = far, dia = da[b];

  vector<int> dep(N), pd;
  vector<vector<int>> strees;
  int R = 1e9;
  {
    map<int,vector<int>> mp;
    for (int i = 0; i < N; i++) {
      dep[i] = (da[i] + dr[i] - dr[a]) / 2;
      mp[da[i] - dep[i]].push_back(i);
      R = min(R, max(da[i] - dep[i], dia - da[i] + dep[i]));
    }
    for (auto [x, y] : mp) pd.push_back(x), strees.push_back(y);
  }

  int t = pd.size();
  vector<int> cand;
  for (int i = 0; i < t; i++) {
    if (R == max(pd[i], dia - pd[i])) cand.push_back(i);
  }

  // if 2 cand, avoid checking both
  auto ok = [&](int v) {
    int lft = 0, rit = 0;
    for (int i = 0; i < v; i++) lft += strees[i].size();
    for (int i = t - 1; i > v; i--) rit += strees[i].size();
    if (lft > N / 2 || rit > N / 2) return false;
    return true;
  };

  if (cand.size() == 2) { 
    // both ok, both centroid, cut is even
    bool ok0 = ok(cand[0]), ok1 = ok(cand[1]);
    if (ok0 && ok1) return R;
    // both not ok, rip
    if (!ok0 && !ok1) return -R;
    // only one of them is ok, WLOG say 0, 
    if (!ok0) swap(cand[0], cand[1]);
  }
  if (!ok(cand[0])) return -R;

  int cnt = 0;
  auto same_comp = [&](int u, int v) {
    if (u == v) return true;
    ++cnt;
    int dis = getDistance(u, v);
    if (dep[u] + dep[v] == dis) return false;
    return true;
  };

  vector<pair<int,int>> rem, dead;
  for (auto v : strees[cand[0]]) rem.emplace_back(v, 1);
  while(rem.size() > 1) {
    vector<pair<int,int>> nrem;
    for (int i = 1; i < (int)rem.size(); i += 2) {
      auto [u, uc]  = rem[i - 1];
      auto [v, vc]  = rem[i];
      if (same_comp(u, v)) {
        nrem.emplace_back(u, uc + vc);
      } else {
        if (uc > vc) {
          nrem.emplace_back(u, uc - vc);
        } else if (uc < vc) {
          nrem.emplace_back(v, vc - uc);
        }
        dead.emplace_back(u, min(uc, vc));
        dead.emplace_back(v, min(uc, vc));
      }
    }
    if (rem.size() & 1) nrem.push_back(rem.back());
    rem = nrem;
  }

  if (!rem.size()) return R;
  int sz = rem[0].second;
  for (auto [v, c] : dead) {
    if (same_comp(rem[0].first, v)) sz += c;
  }
  if (sz > N / 2) return -R;
  return R;
}