#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans, idx, p[101];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	sort(p + 1, p + n + 1);
	scanf("%d%d", &a, &b);
	if (a % 2 == 0) a++;
	if (b % 2 == 0) b--;
	p[0] = -1e9, p[n + 1] = 1e9;
	for (int i = 1; i <= n + 1; i++){
		if (p[i - 1] > b || p[i] < a) continue;
		int x = (p[i - 1] + p[i]) >> 1;
		if (x % 2 == 0) x++;
		if (x < a) x = a;
		if (x > b) x = b;
		if (ans < min(p[i] - x, x - p[i - 1])) ans = min(p[i] - x, x - p[i - 1]), idx = x;
	}
	printf("%d", idx);
}
