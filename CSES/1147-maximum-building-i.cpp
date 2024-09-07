#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<string> g(n);
  vector<int> h(m + 1);
  for (int i = 0; i < n; i++) cin >> g[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '*') h[j] = 0;
      else h[j]++;
    }
    vector<int> st = {-1};
    for (int j = 0; j <= m; j++) {
      while(st.size() > 1 && h[j] < h[st.back()]) {
        ans = max(ans, h[st.back()] * (j - st[st.size() - 2] - 1));
        st.pop_back();
      }
      st.push_back(j);
    }
  }
  cout << ans << '\n';
}
