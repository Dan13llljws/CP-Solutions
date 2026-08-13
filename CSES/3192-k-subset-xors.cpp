#include "bits/stdc++.h"
using namespace std;

template<typename T>
class Z2Span{
  static constexpr int MAX_DIM = std::numeric_limits<T>::digits;
  T basis[MAX_DIM];
  T mask;
public:
  Z2Span(): mask{0} {}
  Z2Span(const vector<T> &vec): mask{0} { memset(basis, 0, sizeof(basis)); extend(vec); }
  void extend(T x) {
    for (int i = MAX_DIM; i >= 0; i--) {
      if (x & (1 << i)) {
        if (!basis[i]) { basis[i] = x, mask |= 1 << i; return; }
        x ^= basis[i];
      }
    }
  }
  void extend(const vector<T> &vec) { for (auto x : vec) extend(x); }
  T max() const {
    T res = 0;
    for (int i = MAX_DIM - 1; i >= 0; i--) {
      if (!(res & (1 << i)) && basis[i]) res^= basis[i];
    }
    return res;
  }
  int size() const { 
    int res = 0;
    for (int i = 0; i < MAX_DIM; i++) {
      if (basis[i]) res++;
    }
    return res;
  }
  T get_mask() const { return mask; }
  vector<T> get_basis(bool compressed = false) const { 
    if (compressed) {
      vector<T> res;
      for (int i = 0; i < MAX_DIM; i++) {
        if (basis[i]) res.push_back(basis[i]);
      }
      return res;
    }
    return vector<T>(basis, basis + MAX_DIM); 
  }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  Z2Span<int> span(a);
  auto basis = span.get_basis(true);
  int ker_size = n - span.size();
  if (ker_size > 22) {
    while(k--) cout << 0 << ' ';
    cout << '\n';
    return 0;
  }
  ker_size = 1 << ker_size;
  vector<int> ans(ker_size, 0);
  for (int i = 0; (int)ans.size() < k && i < (int)basis.size(); i++) {
    vector<int> t;
    for (int j = 1 << i; j < (1 << (i + 1)); j++) {
      int cur = 0;
      for (int k = 0; k <= i; k++) 
        if (j >> k & 1) cur ^= basis[k];
      t.push_back(cur);
    }
    sort(t.begin(), t.end());
    for (int j = 0; (int)ans.size() < k && j < (int)t.size(); j++) {
      for (int k = 0; k < ker_size; k++) ans.push_back(t[j]);
    }
  } 
  for (int i = 0; i < k; i++) cout << ans[i] << ' ';
  cout << '\n';
}