#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n; cin >> n; map<ll,ll> sum;
  ll ans = 0, inf = 0;
  for (int i = 0; i < n; i++){
    int a;
    cin >> a;
    sum[a]++, ans += a;
  } int q; cin >> q;
  while(q--){
    string s;
    cin >> s;
    if (s == "SET"){
      int x, y;
      cin >> x >> y;
      if (x != y){
        ans += (y - x) * sum[x - inf];
        sum[y - inf] += sum[x - inf];
        sum.erase(x - inf);
      }
    } else {
      ll x; cin >> x;
      inf += x;
    } cout << ans + inf * n << '\n';
  }
}


