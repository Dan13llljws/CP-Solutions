#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  while(n--) {
    string s; cin >> s;
    vector<int> f(26);
    for (char c : s) f[c - 'a']++;
    bool good = 1;
    for (int i = 1; i < m; i++) 
      good &= (f[s[i] - 'a'] == 1) ^ (f[s[i - 1] - 'a'] == 1);
    cout << (good ? 'T' : 'F') << '\n';
  }
}
