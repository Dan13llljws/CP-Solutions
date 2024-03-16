#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
	x.push_back(x[0]), y.push_back(y[0]);

	auto cross = [&](int ax, int ay, int bx, int by, int cx, int cy) {
		ll prod = 1LL * (bx - ax) * (cy - by) - 1LL * (by - ay) * (cx - bx);
		if (prod == 0) return 0;
		if (prod > 0) return 1;
		return -1;
	};
	auto inside = [&](int px, int py) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (px == x[i] && py == y[i]) return 0;
			if (py == y[i] && py == y[i + 1]) {
				if (px >= min(x[i], x[i + 1]) && px <= max(x[i], x[i + 1])) return 0;
			} else {
				bool below = y[i] < py;
				if (below != (y[i + 1] < py)) {
					auto res = cross(px, py, x[i], y[i], x[i + 1], y[i + 1]);
					if (res == 0) return 0;
					if (below == (res > 0)) below ? count++ : count--;
				}
			}
		}
		return count == 0 ? -1 : 1;
	};

	for (int i = 0; i < m; i++) {
		int px, py; scanf("%d%d", &px, &py);
		int res = inside(px, py);
		if (res == 0) printf("BOUNDARY\n");
		else if (res == 1) printf("INSIDE\n");
		else printf("OUTSIDE\n");
	}
}

