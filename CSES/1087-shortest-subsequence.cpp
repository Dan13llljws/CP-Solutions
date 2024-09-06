#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> nxt(n, vector<int>(4, -1));
  vector<int> lst(4, n);
  map<int,int> mp = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
  string rmp = "ACGT";
  for (int i = n - 1; i >= 0; i--){
    for (int j = 0; j < 4; j++) nxt[i][j] = lst[j];
    lst[mp[s[i]]] = i;
  }
  string ans;
  int i = *max_element(lst.begin(), lst.end());
  if (i == n) {
    for (int k = 0; k < 4; k++)
      if (lst[k] == n){
        ans.push_back(rmp[k]);
        break;
      }
  }
  while(i < n){
    ans.push_back(s[i]);
    int j = *max_element(nxt[i].begin(), nxt[i].end());
    if (j == n){
      for (int k = 0; k < 4; k++)
        if (nxt[i][k] == n){
          ans.push_back(rmp[k]);
          break;
        }
    }
    i = j;
  }
  cout << ans << '\n';
}
