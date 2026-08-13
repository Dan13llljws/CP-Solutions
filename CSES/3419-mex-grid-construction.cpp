#include "bits/stdc++.h"
using namespace std;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (i ^ j) << ' ';
    }
    cout << endl;
  }
}