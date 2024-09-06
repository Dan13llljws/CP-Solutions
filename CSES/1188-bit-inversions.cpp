#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
struct DisjointIntervals{
  int n;
  set<pair<T, T>> intervals;
  multiset<T> sizes; 
  DisjointIntervals(int _n): n(_n) {}
  void add_point(int x) {
    auto val = make_pair(x, x + 1);
    auto it = intervals.upper_bound(val);
    if (it != intervals.end() && it->first == x + 1) {
      val = *it, --val.first;
      sizes.erase(sizes.lower_bound(it->second - it->first));
      intervals.erase(it);
      it = intervals.upper_bound(val);
    }
    if (it == intervals.begin()) {
      intervals.insert(val);
      sizes.insert(val.second - val.first);
      return;
    }
    it--; // it->first <= x
    if (it->second >= val.first) {
      val.first = it->first;
      sizes.erase(sizes.lower_bound(it->second - it->first));
      intervals.erase(it);
    }
    intervals.insert(val);
    sizes.insert(val.second - val.first);
  }
  bool rem_point(int x) {
    auto val = make_pair(x, 1e9);
    auto it = intervals.upper_bound(val);
    if (it == intervals.begin()) return false; // point not exist
    it--;
    if (it->second <= x) return false;
    pair<T, T> left = make_pair(it->first, x), right = make_pair(x + 1, it->second);
    sizes.erase(sizes.lower_bound(it->second - it->first));
    intervals.erase(it);
    if (left.first < left.second) {
      sizes.insert(left.second - left.first);
      intervals.insert(left);
    }
    if (right.first < right.second) {
      sizes.insert(right.second - right.first);
      intervals.insert(right);
    }
    return true;
  }
};
int main(){
  cin.sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int q; cin >> q;
  int n = s.size();
  DisjointIntervals black(n), white(n);
  for (int i = 0; i < n; i++) { 
    if (s[i] == '1') black.add_point(i);
    else white.add_point(i);
  }
  while (q--) {
    int i; cin >> i; i--;
    if (s[i] == '1') {
      s[i] = '0';
      white.add_point(i);
      black.rem_point(i);
    } else {
      s[i] = '1';
      white.rem_point(i);
      black.add_point(i);
    }
    int bmax =  black.sizes.empty() ? 0 : *black.sizes.rbegin();
    int wmax =  white.sizes.empty() ? 0 : *white.sizes.rbegin();
    cout << max(bmax, wmax) << ' ';
  }
  cout << '\n';
}
