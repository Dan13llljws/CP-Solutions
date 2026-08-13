#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

template<typename T>
class Z2Span{
  static constexpr int MAX_DIM = std::numeric_limits<T>::digits;
  T basis[MAX_DIM];
public:
  Z2Span() {}
  Z2Span(const vector<T> &vec) { memset(basis, 0, sizeof(basis)); extend(vec); }
  void extend(T x) {
    for (int i = MAX_DIM; i >= 0; i--) {
      if (x & (1 << i)) {
        if (!basis[i]) { basis[i] = x; return; }
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
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  Z2Span<int> span(a);
  cout << (1 << span.size()) << '\n';
}