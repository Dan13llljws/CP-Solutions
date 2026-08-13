#include "bits/stdc++.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m; cin >> n >> m;
  vector<vector<int>> stks(m);
  vector<int> missing(n, 1);
  for (auto &stk : stks) {
    int t; cin >> t;
    stk.resize(t);
    for (int &x : stk) cin >> x, missing[x] = 0;
    ranges::reverse(stk);
  }
  vector<int> mid = views::iota(0, n) | views::filter([&missing](int i) { return missing[i]; }) | ranges::to<vector<int>>();
  ranges::reverse(mid);
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    ans.push_back(stks[i].back());
  }
  ranges::sort(stks, greater<int>{}, [](auto x) { return x.back(); });
  vector<int> st, top(m);
  for (int i = 0; i < m; i++) {
    top[i] = stks[i].back();
    stks[i].pop_back();
  }
  for (int i = 0; i < m; i++) {
    if (stks[i].size() && (i == 0 || stks[i].back() < top[i - 1])) st.push_back(i); // positions i can put one more on top
  }
  while(st.size() || mid.size()) {
    // push missing item
    if (mid.size() && mid.back() < top.back()) {
      ans.push_back(mid.back());
      mid.pop_back();
      continue;
    }
    if (st.empty()) return cout << "NO\n", 0;
    int j = st.back();
    bool nxt_ok = j < m - 1 && stks[j + 1].size() && stks[j + 1].back() < top[j];
    if (!nxt_ok) st.pop_back();
    for (int i = j + nxt_ok; i < m; i++) {
      if (i == 0 || stks[i].size() && stks[i].back() < top[i - 1]) {
        if (stks[i].back() < top[i]) return cout << "NO\n", 0;
        top[i] = stks[i].back();
        ans.push_back(stks[i].back());
        stks[i].pop_back();
        if (stks[i].size() && (i == 0 || stks[i].back() < top[i - 1])) st.push_back(i); // this is avail
      } else break; // cant push anymore
    }
  }
  if ((int)ans.size() == n) {
    cout << "YES\n";
    for (int x : ans) cout << x << ' ';
    cout << "\n";
  } else cout << "NO\n";
}