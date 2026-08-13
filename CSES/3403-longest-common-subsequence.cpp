#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  a.push_back(0);
  b.push_back(0);
  n++, m++;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  vector<vector<pair<int,int>>> prev(n + 1, vector<pair<int,int>>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        prev[i][j] = {i, j};
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        prev[i][j] = dp[i - 1][j] > dp[i][j - 1] ? prev[i - 1][j] : prev[i][j - 1];
      }
    }
  }
  cout << dp[n][m] - 1 << '\n';
  vector<int> ans;
  for (int i = n, j = m; i || j; tie(i, j) = prev[i - 1][j - 1]) {
    ans.push_back(a[i - 1]);
  }
  reverse(ans.begin(), ans.end());
  ans.pop_back();
  for (int x : ans) cout << x << ' ';
  cout << '\n';
}