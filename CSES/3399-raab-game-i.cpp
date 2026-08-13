#include "bits/stdc++.h"
using namespace std;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) []() {
    int n, a, b; cin >> n >> a >> b;
    if (a + b > n) { cout << "NO\n"; return; }
    if (!!a ^ !!b) { cout << "NO\n"; return; }
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    cout << "YES\n";
    for (int x : v) cout << x << ' ';
    cout << '\n';
    rotate(v.begin() + n - a - b, v.begin() + n - b, v.end());
    for (int x : v) cout << x << ' ';
    cout << '\n';
  }(); 
}