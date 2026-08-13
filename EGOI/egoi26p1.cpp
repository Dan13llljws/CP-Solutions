#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n; cin >> n;
  string s; cin >> s;
  if (s[0] == '-' || s.back() == '+') return cout << "NO\n", 0;
  cout << "YES\n";
  for (int i = 0; i < n; i++)
    if (s[i] == '+') cout << i << ' ';
  for (int i = n - 1; i >= 0; i--)
    if (s[i] == '-') cout << i << ' ';
  cout << '\n';
}