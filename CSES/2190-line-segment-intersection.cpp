#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		auto cross = [&](int ax, int ay, int bx, int by, int cx, int cy) {
			ll prod = 1LL * (bx - ax) * (cy - by) - 1LL * (by - ay) * (cx - bx);
			if (prod == 0) return 0;
			if (prod > 0) return 1;
			return -1;
		};
		auto dis = [&](int ax, int ay, int bx, int by) {
			return sqrt(1LL * (ax - bx) * (ax - bx) + 1LL * (ay - by) * (ay - by));
		};
		int x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		int a = cross(x1, y1, x2, y2, x3, y3), b = cross(x1, y1, x2, y2, x4, y4);
		int c = cross(x3, y3, x4, y4, x1, y1), d = cross(x3, y3, x4, y4, x2, y2);
		if (a == 0 && b == 0) {
			if (dis(x1, y1, x2, y2) + dis(x3, y3, x4, y4) < 
				max({dis(x1, y1, x3, y3),dis(x1, y1, x4, y4),dis(x2, y2, x3, y3),dis(x2, y2, x4, y4)})) cout << "NO\n";
			else cout << "YES\n";
		} else if (a * b <= 0 && c * d <= 0) cout << "YES\n";
		else cout << "NO\n";
	}
}
