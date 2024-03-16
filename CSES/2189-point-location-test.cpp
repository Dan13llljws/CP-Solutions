#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int ax, ay, bx, by, cx, cy;
		scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
		ll prod = 1LL * (bx - ax) * (cy - by) - 1LL * (by - ay) * (cx - bx);
		if (prod == 0) cout << "TOUCH\n";
		else if (prod > 0) cout << "LEFT\n";
		else cout << "RIGHT\n";
	}
}
