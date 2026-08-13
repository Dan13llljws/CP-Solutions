#include "bits/stdc++.h"
using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int a, b, x, y; cin >> a >> b >> x >> y;
	cout << 2 * min(a + x + max(b, y), b + y + max(a, x)) << '\n';
}