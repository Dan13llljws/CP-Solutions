#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, m, k, c[MM];
bool check(int x){
	long long res = 0;
	for (int i = 1; i <= x; i++) res += max(0, x - c[i]);
	return res <= 1LL * m * k && c[x] + m >= x;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	sort(c + 1, c + 1 + n, greater<int>());
	int l = 0, r = n;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	} printf("%d\n", l);
}
