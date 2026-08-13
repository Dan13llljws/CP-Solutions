#include "bits/stdc++.h"
using namespace std;

int get_iter(int x) { return x <= 12 ? (x - 1) / 3 : (x - 13) / 2 + 4; }
int get_base(int iter) { return iter <= 3 ? 1 + 3 * iter : 13 + 2 * (iter - 4); }
int get_v(int x) { return x <= 12 ? (x - 1) % 3 : (x - 13) % 2; }

array<int,3> get_range(int iter, int x) {
  int l = 1, r = 5000, pos = 0;
  for (int i = 0; i <= iter; i++) {
    l++, r--;
    int k = i <= 3 ? 3 : 2;
    int len = (r - l + 1) / k;
    pos = min(k - 1, (x - l) / len);
    l += pos * len, r = pos == k - 1 ? r : l + len - 1;
  }
  return {l, r, pos};
}

#define ME (side ? -1 : -2)
#define THEM (side ? -2 : -1)

vector<vector<int>> devise_strategy(int N) {
  int x = 20;
  vector<vector<int>> s(x + 1, vector<int>(N + 1));
  for (int j = 1; j <= N; j++) s[0][j] = get_range(0, j)[2] + 1;
  s[0][1] = -1;
  if (N == 5000) s[0][5000] = -2;
  for (int i = 1; i <= x; i++) {
    int iter = get_iter(i), v = get_v(i), side = iter & 1;
    s[i][0] = side ^ 1;
    for (int j = 1; j <= N; j++) {
      auto [l, r, p] = get_range(iter, j);
      if (p < v) s[i][j] = ME;
      else if (p > v) s[i][j] = THEM;
      else if (j <= l) s[i][j] = ME;
      else if (j >= r) s[i][j] = THEM;
      else if (iter < 7) s[i][j] = get_base(iter + 1) + get_range(iter + 1, j)[2];
    }
  }
  return s;
}