#include <bits/stdc++.h>
using namespace std;
int n, m, t, a[105], b[105], c[105], d[105];
bool check(int x){
	int l = x, r = t - x, cl = 0, cr = 0;
	for (int i = 0; i < n; i++) cl += max(0, (l - a[i] + b[i]) / b[i]);
	for (int i = 0; i < m; i++) cr += max(0, (r - c[i] + d[i]) / d[i]);
	return cr >= cl;
}
int main(){
	scanf("%d%d", &t, &n);
	for (int i = 0; i < n; i++) scanf("%d%d", a + i, b + i);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d%d", c + i, d + i);
	int l = 0, r = t;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
}

